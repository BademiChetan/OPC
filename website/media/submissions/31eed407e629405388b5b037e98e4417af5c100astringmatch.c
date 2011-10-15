#include <stdio.h>
#include <string.h>

char * hey_copy(char * string, int M, int K);

int main() {
  int T;
  int i, j, k;
  int N, M, K, num_query, len_temp, count, len;
  char string[50000];
  char buffer[50000];
  char buffer_temp[50000];
  
  scanf("%d", &T);
  for(i=0;i<T;i++) {
    scanf("%d", &N);
    scanf("%s", string);
    scanf("%d", &num_query);
    for(j=0;j<num_query;j++) {
      scanf("%d %d", &M, &K);
      strcpy(buffer,hey_copy(string, M, K));
      count=0;
      for(k=0;k<(sizeof(string)/sizeof(int));k++) {
        strcpy(buffer_temp, hey_copy(string, k, K));
        if(!strncmp(buffer, buffer_temp, K)) count++;
      }
      printf("%d\n", count);
    }
  }
  return 0;
}

char * hey_copy(char * string, int M, int K) {
  int i;
  static char buffer[50000];
  for(i=0;i<K;i++) {
    buffer[i]=string[M+i];
  }
  buffer[i]='\0';
  
  return buffer;
}
    
    
    
