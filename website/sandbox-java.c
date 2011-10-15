/*
 * Copyright (c) 2006 Adomas Paltanavicius
 * 
 * Permission is hereby granted, free of charge, to any person obtaining 
 * a copy of this software and associated documentation files (the 
 * "Software"), to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, merge, publish, 
 * distribute, sublicense, and/or sell copies of the Software, and to 
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*
 * Short usage instructions:
 *
 * -m memory_limit (in megabytes), e.g.: -m 16
 * -t time_limit (in seconds), e.g.: -t 5; this counts for user+system time
 * -c clock_limit (in seconds); program is terminates when -t/-c (whichever 
 *    first) comes.
 * -d initial_dir, e.g. -d run/
 * -n no stdin/out/err
 */

#define _GNU_SOURCE

#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <getopt.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/user.h>
#include <sys/time.h>
#include <sys/ptrace.h>
#include <sys/signal.h>
#include <sys/sysinfo.h>
#include <sys/syscall.h>
#include <sys/resource.h>
  
#define MEGABYTE (1024*1024)
 
/* Defaults to no limits.
 */
int time_limit;
int clock_limit;
int memory_limit;
int disable_std;
char *dir;
char **vector;

/* Runtime variables.
 */
int ok = 1;
pid_t pid;
time_t start_time;
int clock_time_terminated;

/* Terminate child process and then exit.
 */
void terminate(int is_ok) {
  if (pid > 0) {
    /* Process group.
     */
    kill(-pid, SIGKILL);
    /* And the process itself.
     */
    kill(pid, SIGKILL);
  }
  if (is_ok != -1) {
    ok = is_ok;
  }
}

/* Print error message and terminate.
 */
void die(char *msg, ...) {
  va_list args;
  va_start(args, msg);
  vfprintf(stderr, msg, args);
  putchar('\n');
  terminate(0);
  exit(ok ? 0 : 1);
}

/* Check if clock time limit is exceeded.
 */
void alarm_handler(int forget __attribute__((unused))) {
  time_t gone = time(NULL) - start_time;

  if (clock_limit) {
    if (gone >= clock_limit) {
      clock_time_terminated = 1;
      terminate(0);
      return;
    }
  }
  alarm(1);
}

/* Run child, put limits, optionally redirect file descriptors.
 */
void child() {
  struct rlimit rl;

  /* Change working directory.
   */
  if (dir) {
    if (chdir(dir) != 0) {
      die("error=chdir: %m");
    }
  }

  /* Hide stdin/stdout.
   */
  if (disable_std) {
    close(0);
    if (open("/dev/null", O_RDWR) < 0) {
      die("error=open: %m");
    }
    dup2(0, 1);
    dup2(0, 2);
  } else {
    dup2(1, 2);
  }

  /* Memory limit (virtual memory address space).
   */
  if (memory_limit) {
    rl.rlim_cur = rl.rlim_max = memory_limit;
    if (setrlimit(RLIMIT_AS, &rl) < 0) {
      die("error=setrlimit[RLIMIT_AS]: %m");
    }
  }

  /* Separate limits for user+system time
   */
  if (time_limit) {
    rl.rlim_cur = rl.rlim_max = time_limit;
    if (setrlimit(RLIMIT_CPU, &rl) < 0) {
      die("error=setrlimit[RLIMIT_CPU]: %m");
    }
  }

  /* So that children can't play with fork().
   */
  rl.rlim_cur = rl.rlim_max = 200;
  if (setrlimit(RLIMIT_NPROC, &rl) < 0) {
    die("error=setrlimit[RLIMIT_NPROC]: %m");
  }
  
  /* Execute.
   */
  execve(vector[0], vector, NULL);

  /* This will go straight to hell.
   */
  die("error=execve(\"%s\"): %m", vector[0]);
}

/* Setup alarm.
 */
void father() { 
  static struct sigaction sa;
  struct rusage usage;
  struct timeval total;
  time_t gone;
  int status, ret;
  int ran;

  /* Start timestamp.
   */
  start_time = time(NULL);

  /* Alarm each 1 second.
   */
  sa.sa_handler = &alarm_handler;
  sigaction(SIGALRM, &sa, NULL);
  alarm(1);

  /* Wait for child to terminate.
   */
  for (;;) {
    ret = wait3(&status, 0, &usage);
    if (ret > 0)
      break;
  }
  
  /* PID of the child that exited.
   */
  if (ret != pid) {
    die("error=wait3, seen pid %d instead of %d", ret, pid);
  }

  /* Clock time. 
   */
  gone = time(NULL) - start_time;
  if (clock_time_terminated) {
    //fprintf(stderr, "Limit exceeded: %us\n", (unsigned) gone);
    fprintf (stderr, "return=tle\n");
    terminate(0);
    return;
  }
  
  /* Sum up user and system times.
   */
  timeradd(&usage.ru_stime,
           &usage.ru_utime,
           &total);
  ran = (unsigned) (total.tv_sec + total.tv_usec/1000000. + .5);
  fprintf(stderr, "time=%u.%.6us\n",
          (unsigned) total.tv_sec, (unsigned) total.tv_usec);
  //fprintf(stderr, "Running time: %u.%.6us. ", 
  //        (unsigned) total.tv_sec, (unsigned) total.tv_usec);
  if (time_limit && ran >= time_limit) {
    fprintf(stderr, "return=tle\n");
    //fprintf(stderr, "Limit exceeded: %us\n", ran);
  } else {
    if (WIFEXITED(status)) {
      int exit_status = WEXITSTATUS(status);
      if (exit_status != 0) {
        //fprintf(stderr, "Non-zero exit status: %d\n", exit_status);
        fprintf(stderr, "return=nz\n");
      } else {
        //fprintf(stderr, "OK\n");
        fprintf(stderr, "return=ok\n");
        terminate(1);
        return;
      }
    } else if (WIFSIGNALED(status)) {
      int sig = WTERMSIG(status);
      fprintf(stderr, "return=%s\n", strsignal(sig));
      //fprintf(stderr, "Terminated by signal: %s\n", strsignal(sig));
    } else {
      fprintf(stderr, "return=unknown\n");
      //fprintf(stderr, "?\n");
    }
  }
  terminate(0);
}

void run() {
  pid = fork();
  if (pid < 0) {
    die("fork: %m");
  } else if (pid == 0) {
    child();
  } else {
    father();
  }
}

void usage() {
  fprintf(stderr,
          "%s",
          "Usage: zsimple [-d working_directory]\n"
          "               [-t time_limit]\n"
          "               [-c clock_limit]\n"
          "               [-m memory_limit]\n"
          "               [-n]\n"
          "               program\n"
          "               [args]\n\n"
          "  -d   Sets working directory.\n"
          "  -t   Sets system+user time limit, in seconds.\n"
          "  -c   Sets clock time limit; defaults to -t value.\n"
          "  -m   Sets memory limit, in megabytes.\n"
          "  -n   Redirect program's std* descriptors to hell\n");
}

int main(int argc, char **argv) {
  int c;

  while ((c = getopt(argc, argv, "hnc:t:m:d:")) != -1) {
    switch (c) {
    case 'c':
      clock_limit = strtoul(optarg, NULL, 0);
      break;
    case 't':
      time_limit = strtoul(optarg, NULL, 0);
      if (!clock_limit)
        clock_limit = time_limit;
      break;
    case 'm':
      memory_limit = strtoul(optarg, NULL, 0) * MEGABYTE;
      break;
    case 'd':
      dir = optarg;
      break;
    case 'n':
      disable_std = 1;
      break;
    case 'h':
      usage();
      exit(0);
    }
  }
  if (optind == argc) {
		usage();
    die("main: no executable name given");
  }
  vector = &argv[optind];
  run();
  terminate(-1);
	exit(ok ? 0 : 1);
}

/* 
 * vi: sw=2 ts=2 et ai
 */
