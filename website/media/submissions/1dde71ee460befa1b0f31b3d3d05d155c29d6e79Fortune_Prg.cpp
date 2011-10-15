/***
*iostream.h - definitions/declarations for iostream classes
*
*       Copyright (c) 1990-1997, Microsoft Corporation.  All rights reserved.
*
*Purpose:
*       This file defines the classes, values, macros, and functions
*       used by the iostream classes.
*       [AT&T C++]
*
*       [Public]
*
****/

#if     _MSC_VER > 1000
#pragma once
#endif

#ifdef  __cplusplus

#ifndef _INC_IOSTREAM
#define _INC_IOSTREAM

#if     !defined(_WIN32) && !defined(_MAC)
#error ERROR: Only Mac or Win32 targets supported!
#endif


#ifdef  _MSC_VER
// Currently, all MS C compilers for Win32 platforms default to 8 byte
// alignment.
#pragma pack(push,8)

#include <useoldio.h>

#endif  // _MSC_VER


/* Define _CRTIMP */

#ifndef _CRTIMP
#ifdef  _DLL
#define _CRTIMP __declspec(dllimport)
#else   /* ndef _DLL */
#define _CRTIMP
#endif  /* _DLL */
#endif  /* _CRTIMP */


typedef long streamoff, streampos;

#include <ios.h>                // Define ios.

#include <streamb.h>            // Define streambuf.

#include <istream.h>            // Define istream.

#include <ostream.h>            // Define ostream.

#ifdef  _MSC_VER
// C4514: "unreferenced inline function has been removed"
#pragma warning(disable:4514) // disable C4514 warning
// #pragma warning(default:4514)        // use this to reenable, if desired
#endif  // _MSC_VER

class _CRTIMP iostream : public istream, public ostream {
public:
        iostream(streambuf*);
        virtual ~iostream();
protected:
        iostream();
        iostream(const iostream&);
inline iostream& operator=(streambuf*);
inline iostream& operator=(iostream&);
private:
        iostream(ios&);
        iostream(istream&);
        iostream(ostream&);
};

inline iostream& iostream::operator=(streambuf* _sb) { istream::operator=(_sb); ostream::operator=(_sb); return *this; }

inline iostream& iostream::operator=(iostream& _strm) { return operator=(_strm.rdbuf()); }

class _CRTIMP Iostream_init {
public:
        Iostream_init();
        Iostream_init(ios &, int =0);   // treat as private
        ~Iostream_init();
};

// used internally
// static Iostream_init __iostreaminit; // initializes cin/cout/cerr/clog

#ifdef  _MSC_VER
// Restore previous packing
#pragma pack(pop)
#endif  // _MSC_VER

#endif  // _INC_IOSTREAM

#endif  /* __cplusplus */
/***
*stdlib.h - declarations/definitions for commonly used library functions
*
*       Copyright (c) 1985-1997, Microsoft Corporation. All rights reserved.
*
*Purpose:
*       This include file contains the function declarations for commonly
*       used library functions which either don't fit somewhere else, or,
*       cannot be declared in the normal place for other reasons.
*       [ANSI]
*
*       [Public]
*
****/

#if     _MSC_VER > 1000
#pragma once
#endif

#ifndef _INC_STDLIB
#define _INC_STDLIB

#if     !defined(_WIN32) && !defined(_MAC)
#error ERROR: Only Mac or Win32 targets supported!
#endif


#ifdef  _MSC_VER
/*
 * Currently, all MS C compilers for Win32 platforms default to 8 byte
 * alignment.
 */
#pragma pack(push,8)
#endif  /* _MSC_VER */

#ifdef  __cplusplus
extern "C" {
#endif



/* Define _CRTIMP */

#ifndef _CRTIMP
#ifdef  _DLL
#define _CRTIMP __declspec(dllimport)
#else   /* ndef _DLL */
#define _CRTIMP
#endif  /* _DLL */
#endif  /* _CRTIMP */


/* Define __cdecl for non-Microsoft compilers */

#if     ( !defined(_MSC_VER) && !defined(__cdecl) )
#define __cdecl
#endif

/* Define _CRTAPI1 (for compatibility with the NT SDK) */

#ifndef _CRTAPI1
#if	_MSC_VER >= 800 && _M_IX86 >= 300
#define _CRTAPI1 __cdecl
#else
#define _CRTAPI1
#endif
#endif


#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif


#ifndef _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif


/* Define NULL pointer value */

#ifndef NULL
#ifdef __cplusplus
#define NULL    0
#else
#define NULL    ((void *)0)
#endif
#endif


/* Definition of the argument values for the exit() function */

#define EXIT_SUCCESS    0
#define EXIT_FAILURE    1


#ifndef _ONEXIT_T_DEFINED
typedef int (__cdecl * _onexit_t)(void);
#if     !__STDC__
/* Non-ANSI name for compatibility */
#define onexit_t _onexit_t
#endif
#define _ONEXIT_T_DEFINED
#endif


/* Data structure definitions for div and ldiv runtimes. */

#ifndef _DIV_T_DEFINED

typedef struct _div_t {
        int quot;
        int rem;
} div_t;

typedef struct _ldiv_t {
        long quot;
        long rem;
} ldiv_t;

#define _DIV_T_DEFINED
#endif


/* Maximum value that can be returned by the rand function. */

#define RAND_MAX 0x7fff

/*
 * Maximum number of bytes in multi-byte character in the current locale
 * (also defined in ctype.h).
 */
#ifndef MB_CUR_MAX
#define MB_CUR_MAX __mb_cur_max
_CRTIMP extern int __mb_cur_max;
#endif  /* MB_CUR_MAX */


/* Minimum and maximum macros */

#define __max(a,b)  (((a) > (b)) ? (a) : (b))
#define __min(a,b)  (((a) < (b)) ? (a) : (b))

/*
 * Sizes for buffers used by the _makepath() and _splitpath() functions.
 * note that the sizes include space for 0-terminator
 */
#ifndef _MAC
#define _MAX_PATH   260 /* max. length of full pathname */
#define _MAX_DRIVE  3   /* max. length of drive component */
#define _MAX_DIR    256 /* max. length of path component */
#define _MAX_FNAME  256 /* max. length of file name component */
#define _MAX_EXT    256 /* max. length of extension component */
#else   /* def _MAC */
#define _MAX_PATH   256 /* max. length of full pathname */
#define _MAX_DIR    32  /* max. length of path component */
#define _MAX_FNAME  64  /* max. length of file name component */
#endif  /* _MAC */

/*
 * Argument values for _set_error_mode().
 */
#define _OUT_TO_DEFAULT 0
#define _OUT_TO_STDERR  1
#define _OUT_TO_MSGBOX  2
#define _REPORT_ERRMODE 3


/* External variable declarations */

#if     (defined(_MT) || defined(_DLL)) && !defined(_MAC)
_CRTIMP int * __cdecl _errno(void);
_CRTIMP unsigned long * __cdecl __doserrno(void);
#define errno       (*_errno())
#define _doserrno   (*__doserrno())
#else   /* ndef _MT && ndef _DLL */
_CRTIMP extern int errno;               /* XENIX style error number */
_CRTIMP extern unsigned long _doserrno; /* OS system error value */
#endif  /* _MT || _DLL */


#ifdef  _MAC
_CRTIMP extern int  _macerrno;          /* OS system error value */
#endif


_CRTIMP extern char * _sys_errlist[];   /* perror error message table */
_CRTIMP extern int _sys_nerr;           /* # of entries in sys_errlist table */


#if     defined(_DLL) && defined(_M_IX86)

#define __argc      (*__p___argc())     /* count of cmd line args */
#define __argv      (*__p___argv())     /* pointer to table of cmd line args */
#define __wargv     (*__p___wargv())    /* pointer to table of wide cmd line args */
#define _environ    (*__p__environ())   /* pointer to environment table */
#ifdef _POSIX_
extern char ** environ;                 /* pointer to environment table */
#else
#ifndef _MAC
#define _wenviron   (*__p__wenviron())  /* pointer to wide environment table */
#endif  /* ndef _MAC */
#endif /* _POSIX_ */
#define _pgmptr     (*__p__pgmptr())    /* points to the module (EXE) name */
#ifndef _MAC
#define _wpgmptr    (*__p__wpgmptr())   /* points to the module (EXE) wide name */
#endif  /* ndef _MAC */

_CRTIMP int *          __cdecl __p___argc(void);
_CRTIMP char ***       __cdecl __p___argv(void);
_CRTIMP wchar_t ***    __cdecl __p___wargv(void);
_CRTIMP char ***       __cdecl __p__environ(void);
_CRTIMP wchar_t ***    __cdecl __p__wenviron(void);
_CRTIMP char **        __cdecl __p__pgmptr(void);
_CRTIMP wchar_t **     __cdecl __p__wpgmptr(void);


#else

_CRTIMP extern int __argc;          /* count of cmd line args */
_CRTIMP extern char ** __argv;      /* pointer to table of cmd line args */
#ifndef _MAC
_CRTIMP extern wchar_t ** __wargv;  /* pointer to table of wide cmd line args */
#endif  /* ndef _MAC */

#ifdef _POSIX_
extern char ** environ;             /* pointer to environment table */
#else
_CRTIMP extern char ** _environ;    /* pointer to environment table */
#ifndef _MAC
_CRTIMP extern wchar_t ** _wenviron;    /* pointer to wide environment table */
#endif  /* ndef _MAC */
#endif  /* _POSIX_ */

_CRTIMP extern char * _pgmptr;      /* points to the module (EXE) name */
#ifndef _MAC
_CRTIMP extern wchar_t * _wpgmptr;  /* points to the module (EXE) wide name */
#endif  /* ndef _MAC */

#endif


_CRTIMP extern int _fmode;          /* default file translation mode */
_CRTIMP extern int _fileinfo;       /* open file info mode (for spawn) */


/* Windows major/minor and O.S. version numbers */

_CRTIMP extern unsigned int _osver;
_CRTIMP extern unsigned int _winver;
_CRTIMP extern unsigned int _winmajor;
_CRTIMP extern unsigned int _winminor;


/* function prototypes */

#if     _MSC_VER >= 1200
_CRTIMP __declspec(noreturn) void   __cdecl abort(void);
_CRTIMP __declspec(noreturn) void   __cdecl exit(int);
#else
_CRTIMP void   __cdecl abort(void);
_CRTIMP void   __cdecl exit(int);
#endif

#if defined(_M_MRX000)
_CRTIMP int    __cdecl abs(int);
#else
        int    __cdecl abs(int);
#endif
        int    __cdecl atexit(void (__cdecl *)(void));
_CRTIMP double __cdecl atof(const char *);
_CRTIMP int    __cdecl atoi(const char *);
_CRTIMP long   __cdecl atol(const char *);
#ifdef  _M_M68K
_CRTIMP long double __cdecl _atold(const char *);
#endif
_CRTIMP void * __cdecl bsearch(const void *, const void *, size_t, size_t,
        int (__cdecl *)(const void *, const void *));
_CRTIMP void * __cdecl calloc(size_t, size_t);
_CRTIMP div_t  __cdecl div(int, int);
_CRTIMP void   __cdecl free(void *);
_CRTIMP char * __cdecl getenv(const char *);
_CRTIMP char * __cdecl _itoa(int, char *, int);
#if     _INTEGRAL_MAX_BITS >= 64
_CRTIMP char * __cdecl _i64toa(__int64, char *, int);
_CRTIMP char * __cdecl _ui64toa(unsigned __int64, char *, int);
_CRTIMP __int64 __cdecl _atoi64(const char *);
#endif
#if     defined(_M_MRX000)
_CRTIMP long __cdecl labs(long);
#else
        long __cdecl labs(long);
#endif
_CRTIMP ldiv_t __cdecl ldiv(long, long);
_CRTIMP char * __cdecl _ltoa(long, char *, int);
_CRTIMP void * __cdecl malloc(size_t);
_CRTIMP int    __cdecl mblen(const char *, size_t);
_CRTIMP size_t __cdecl _mbstrlen(const char *s);
_CRTIMP int    __cdecl mbtowc(wchar_t *, const char *, size_t);
_CRTIMP size_t __cdecl mbstowcs(wchar_t *, const char *, size_t);
_CRTIMP void   __cdecl qsort(void *, size_t, size_t, int (__cdecl *)
        (const void *, const void *));
_CRTIMP int    __cdecl rand(void);
_CRTIMP void * __cdecl realloc(void *, size_t);
_CRTIMP int    __cdecl _set_error_mode(int);
_CRTIMP void   __cdecl srand(unsigned int);
_CRTIMP double __cdecl strtod(const char *, char **);
_CRTIMP long   __cdecl strtol(const char *, char **, int);
#ifdef  _M_M68K
_CRTIMP long double __cdecl _strtold(const char *, char **);
#endif
_CRTIMP unsigned long __cdecl strtoul(const char *, char **, int);
#ifndef _MAC
_CRTIMP int    __cdecl system(const char *);
#endif
_CRTIMP char * __cdecl _ultoa(unsigned long, char *, int);
_CRTIMP int    __cdecl wctomb(char *, wchar_t);
_CRTIMP size_t __cdecl wcstombs(char *, const wchar_t *, size_t);


#ifndef _MAC
#ifndef _WSTDLIB_DEFINED

/* wide function prototypes, also declared in wchar.h  */

_CRTIMP wchar_t * __cdecl _itow (int, wchar_t *, int);
_CRTIMP wchar_t * __cdecl _ltow (long, wchar_t *, int);
_CRTIMP wchar_t * __cdecl _ultow (unsigned long, wchar_t *, int);
_CRTIMP double __cdecl wcstod(const wchar_t *, wchar_t **);
_CRTIMP long   __cdecl wcstol(const wchar_t *, wchar_t **, int);
_CRTIMP unsigned long __cdecl wcstoul(const wchar_t *, wchar_t **, int);
_CRTIMP wchar_t * __cdecl _wgetenv(const wchar_t *);
_CRTIMP int    __cdecl _wsystem(const wchar_t *);
_CRTIMP int __cdecl _wtoi(const wchar_t *);
_CRTIMP long __cdecl _wtol(const wchar_t *);
#if     _INTEGRAL_MAX_BITS >= 64
_CRTIMP wchar_t * __cdecl _i64tow(__int64, wchar_t *, int);
_CRTIMP wchar_t * __cdecl _ui64tow(unsigned __int64, wchar_t *, int);
_CRTIMP __int64   __cdecl _wtoi64(const wchar_t *);
#endif

#define _WSTDLIB_DEFINED
#endif
#endif  /* ndef _MAC */


#ifndef _POSIX_

_CRTIMP char * __cdecl _ecvt(double, int, int *, int *);
#if     _MSC_VER >= 1200
_CRTIMP __declspec(noreturn) void   __cdecl _exit(int);
#else
_CRTIMP void   __cdecl _exit(int);
#endif
_CRTIMP char * __cdecl _fcvt(double, int, int *, int *);
_CRTIMP char * __cdecl _fullpath(char *, const char *, size_t);
_CRTIMP char * __cdecl _gcvt(double, int, char *);
        unsigned long __cdecl _lrotl(unsigned long, int);
        unsigned long __cdecl _lrotr(unsigned long, int);
#ifndef _MAC
_CRTIMP void   __cdecl _makepath(char *, const char *, const char *, const char *,
        const char *);
#endif
        _onexit_t __cdecl _onexit(_onexit_t);
_CRTIMP void   __cdecl perror(const char *);
_CRTIMP int    __cdecl _putenv(const char *);
        unsigned int __cdecl _rotl(unsigned int, int);
        unsigned int __cdecl _rotr(unsigned int, int);
_CRTIMP void   __cdecl _searchenv(const char *, const char *, char *);
#ifndef _MAC
_CRTIMP void   __cdecl _splitpath(const char *, char *, char *, char *, char *);
#endif
_CRTIMP void   __cdecl _swab(char *, char *, int);

#ifndef _MAC
#ifndef _WSTDLIBP_DEFINED

/* wide function prototypes, also declared in wchar.h  */

_CRTIMP wchar_t * __cdecl _wfullpath(wchar_t *, const wchar_t *, size_t);
_CRTIMP void   __cdecl _wmakepath(wchar_t *, const wchar_t *, const wchar_t *, const wchar_t *,
        const wchar_t *);
_CRTIMP void   __cdecl _wperror(const wchar_t *);
_CRTIMP int    __cdecl _wputenv(const wchar_t *);
_CRTIMP void   __cdecl _wsearchenv(const wchar_t *, const wchar_t *, wchar_t *);
_CRTIMP void   __cdecl _wsplitpath(const wchar_t *, wchar_t *, wchar_t *, wchar_t *, wchar_t *);

#define _WSTDLIBP_DEFINED
#endif
#endif  /* ndef _MAC */

/* --------- The following functions are OBSOLETE --------- */
/* The Win32 API SetErrorMode, Beep and Sleep should be used instead. */
#ifndef _MAC
_CRTIMP void __cdecl _seterrormode(int);
_CRTIMP void __cdecl _beep(unsigned, unsigned);
_CRTIMP void __cdecl _sleep(unsigned long);
#endif  /* ndef _MAC */
/* --------- The preceding functions are OBSOLETE --------- */

#endif  /* _POSIX_ */


#if     !__STDC__
/* --------- The declarations below should not be in stdlib.h --------- */
/* --------- and will be removed in a future release. Include --------- */
/* --------- ctype.h to obtain these declarations.            --------- */
#ifndef tolower     /* tolower has been undefined - use function */
_CRTIMP int __cdecl tolower(int);
#endif  /* tolower */
#ifndef toupper     /* toupper has been undefined - use function */
_CRTIMP int __cdecl toupper(int);
#endif  /* toupper */
/* --------- The declarations above will be removed.          --------- */
#endif


#if     !__STDC__

#ifndef _POSIX_

/* Non-ANSI names for compatibility */

#ifndef __cplusplus
#define max(a,b)    (((a) > (b)) ? (a) : (b))
#define min(a,b)    (((a) < (b)) ? (a) : (b))
#endif

#define sys_errlist _sys_errlist
#define sys_nerr    _sys_nerr
#define environ     _environ

_CRTIMP char * __cdecl ecvt(double, int, int *, int *);
_CRTIMP char * __cdecl fcvt(double, int, int *, int *);
_CRTIMP char * __cdecl gcvt(double, int, char *);
_CRTIMP char * __cdecl itoa(int, char *, int);
_CRTIMP char * __cdecl ltoa(long, char *, int);
        onexit_t __cdecl onexit(onexit_t);
_CRTIMP int    __cdecl putenv(const char *);
_CRTIMP void   __cdecl swab(char *, char *, int);
_CRTIMP char * __cdecl ultoa(unsigned long, char *, int);

#endif  /* _POSIX_ */

#endif  /* __STDC__ */

#ifdef  __cplusplus
}

#endif

#ifdef  _MSC_VER
#pragma pack(pop)
#endif  /* _MSC_VER */

#endif  /* _INC_STDLIB */

/***
*math.h - definitions and declarations for math library
*
*       Copyright (c) 1985-1997, Microsoft Corporation. All rights reserved.
*
*Purpose:
*       This file contains constant definitions and external subroutine
*       declarations for the math subroutine library.
*       [ANSI/System V]
*
*       [Public]
*
****/

#if     _MSC_VER > 1000
#pragma once
#endif

#ifndef _INC_MATH
#define _INC_MATH

#if     !defined(_WIN32) && !defined(_MAC)
#error ERROR: Only Mac or Win32 targets supported!
#endif


#ifdef  _MSC_VER
/*
 * Currently, all MS C compilers for Win32 platforms default to 8 byte
 * alignment.
 */
#pragma pack(push,8)
#endif  /* _MSC_VER */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __assembler /* Protect from assembler */

/* Define _CRTIMP */

#ifndef _CRTIMP
#ifdef  _DLL
#define _CRTIMP __declspec(dllimport)
#else   /* ndef _DLL */
#define _CRTIMP
#endif  /* _DLL */
#endif  /* _CRTIMP */


/* Define __cdecl for non-Microsoft compilers */

#if     ( !defined(_MSC_VER) && !defined(__cdecl) )
#define __cdecl
#endif

/* Define _CRTAPI1 (for compatibility with the NT SDK) */

#ifndef _CRTAPI1
#if	_MSC_VER >= 800 && _M_IX86 >= 300
#define _CRTAPI1 __cdecl
#else
#define _CRTAPI1
#endif
#endif


/* Definition of _exception struct - this struct is passed to the matherr
 * routine when a floating point exception is detected
 */

#ifndef _EXCEPTION_DEFINED
struct _exception {
        int type;       /* exception type - see below */
        char *name;     /* name of function where error occured */
        double arg1;    /* first argument to function */
        double arg2;    /* second argument (if any) to function */
        double retval;  /* value to be returned by function */
        } ;

#define _EXCEPTION_DEFINED
#endif


/* Definition of a _complex struct to be used by those who use cabs and
 * want type checking on their argument
 */

#ifndef _COMPLEX_DEFINED
struct _complex {
        double x,y; /* real and imaginary parts */
        } ;

#if     !__STDC__ && !defined (__cplusplus)
/* Non-ANSI name for compatibility */
#define complex _complex
#endif

#define _COMPLEX_DEFINED
#endif
#endif  /* __assembler */


/* Constant definitions for the exception type passed in the _exception struct
 */

#define _DOMAIN     1   /* argument domain error */
#define _SING       2   /* argument singularity */
#define _OVERFLOW   3   /* overflow range error */
#define _UNDERFLOW  4   /* underflow range error */
#define _TLOSS      5   /* total loss of precision */
#define _PLOSS      6   /* partial loss of precision */

#define EDOM        33
#define ERANGE      34


/* Definitions of _HUGE and HUGE_VAL - respectively the XENIX and ANSI names
 * for a value returned in case of error by a number of the floating point
 * math routines
 */
#ifndef __assembler /* Protect from assembler */
_CRTIMP extern double _HUGE;
#endif  /* __assembler */

#define HUGE_VAL _HUGE


/* Function prototypes */

#if     !defined(__assembler)   /* Protect from assembler */
#if     _M_MRX000
_CRTIMP int     __cdecl abs(int);
_CRTIMP double  __cdecl acos(double);
_CRTIMP double  __cdecl asin(double);
_CRTIMP double  __cdecl atan(double);
_CRTIMP double  __cdecl atan2(double, double);
_CRTIMP double  __cdecl cos(double);
_CRTIMP double  __cdecl cosh(double);
_CRTIMP double  __cdecl exp(double);
_CRTIMP double  __cdecl fabs(double);
_CRTIMP double  __cdecl fmod(double, double);
_CRTIMP long    __cdecl labs(long);
_CRTIMP double  __cdecl log(double);
_CRTIMP double  __cdecl log10(double);
_CRTIMP double  __cdecl pow(double, double);
_CRTIMP double  __cdecl sin(double);
_CRTIMP double  __cdecl sinh(double);
_CRTIMP double  __cdecl tan(double);
_CRTIMP double  __cdecl tanh(double);
_CRTIMP double  __cdecl sqrt(double);
#else
        int     __cdecl abs(int);
        double  __cdecl acos(double);
        double  __cdecl asin(double);
        double  __cdecl atan(double);
        double  __cdecl atan2(double, double);
        double  __cdecl cos(double);
        double  __cdecl cosh(double);
        double  __cdecl exp(double);
        double  __cdecl fabs(double);
        double  __cdecl fmod(double, double);
        long    __cdecl labs(long);
        double  __cdecl log(double);
        double  __cdecl log10(double);
        double  __cdecl pow(double, double);
        double  __cdecl sin(double);
        double  __cdecl sinh(double);
        double  __cdecl tan(double);
        double  __cdecl tanh(double);
        double  __cdecl sqrt(double);
#endif
_CRTIMP double  __cdecl atof(const char *);
_CRTIMP double  __cdecl _cabs(struct _complex);
#if     defined(_M_ALPHA)
        double  __cdecl ceil(double);
        double  __cdecl floor(double);
#else
_CRTIMP double  __cdecl ceil(double);
_CRTIMP double  __cdecl floor(double);
#endif
_CRTIMP double  __cdecl frexp(double, int *);
_CRTIMP double  __cdecl _hypot(double, double);
_CRTIMP double  __cdecl _j0(double);
_CRTIMP double  __cdecl _j1(double);
_CRTIMP double  __cdecl _jn(int, double);
_CRTIMP double  __cdecl ldexp(double, int);
        int     __cdecl _matherr(struct _exception *);
_CRTIMP double  __cdecl modf(double, double *);

_CRTIMP double  __cdecl _y0(double);
_CRTIMP double  __cdecl _y1(double);
_CRTIMP double  __cdecl _yn(int, double);


#if     defined(_M_MRX000)

/* MIPS fast prototypes for float */
/* ANSI C, 4.5 Mathematics        */

/* 4.5.2 Trigonometric functions */

_CRTIMP float  __cdecl acosf( float );
_CRTIMP float  __cdecl asinf( float );
_CRTIMP float  __cdecl atanf( float );
_CRTIMP float  __cdecl atan2f( float , float );
_CRTIMP float  __cdecl cosf( float );
_CRTIMP float  __cdecl sinf( float );
_CRTIMP float  __cdecl tanf( float );

/* 4.5.3 Hyperbolic functions */
_CRTIMP float  __cdecl coshf( float );
_CRTIMP float  __cdecl sinhf( float );
_CRTIMP float  __cdecl tanhf( float );

/* 4.5.4 Exponential and logarithmic functions */
_CRTIMP float  __cdecl expf( float );
_CRTIMP float  __cdecl logf( float );
_CRTIMP float  __cdecl log10f( float );
_CRTIMP float  __cdecl modff( float , float* );

/* 4.5.5 Power functions */
_CRTIMP float  __cdecl powf( float , float );
        float  __cdecl sqrtf( float );

/* 4.5.6 Nearest integer, absolute value, and remainder functions */
        float  __cdecl ceilf( float );
        float  __cdecl fabsf( float );
        float  __cdecl floorf( float );
_CRTIMP float  __cdecl fmodf( float , float );

_CRTIMP float  __cdecl hypotf(float, float);

#endif  /* _M_MRX000 */

#if     defined(_M_ALPHA)

/* ALPHA fast prototypes for float */
/* ANSI C, 4.5 Mathematics        */

/* 4.5.2 Trigonometric functions */

        float  __cdecl acosf( float );
        float  __cdecl asinf( float );
        float  __cdecl atanf( float );
        float  __cdecl atan2f( float , float );
        float  __cdecl cosf( float );
        float  __cdecl sinf( float );
        float  __cdecl tanf( float );

/* 4.5.3 Hyperbolic functions */
        float  __cdecl coshf( float );
        float  __cdecl sinhf( float );
        float  __cdecl tanhf( float );

/* 4.5.4 Exponential and logarithmic functions */
        float  __cdecl expf( float );
        float  __cdecl logf( float );
        float  __cdecl log10f( float );
_CRTIMP float  __cdecl modff( float , float* );

/* 4.5.5 Power functions */
        float  __cdecl powf( float , float );
        float  __cdecl sqrtf( float );

/* 4.5.6 Nearest integer, absolute value, and remainder functions */
        float  __cdecl ceilf( float );
        float  __cdecl fabsf( float );
        float  __cdecl floorf( float );
        float  __cdecl fmodf( float , float );

_CRTIMP float  __cdecl _hypotf(float, float);

#endif  /* _M_ALPHA */

#if     !defined(_M_M68K)
/* Macros defining long double functions to be their double counterparts
 * (long double is synonymous with double in this implementation).
 */


#ifndef __cplusplus
#define acosl(x)    ((long double)acos((double)(x)))
#define asinl(x)    ((long double)asin((double)(x)))
#define atanl(x)    ((long double)atan((double)(x)))
#define atan2l(x,y) ((long double)atan2((double)(x), (double)(y)))
#define _cabsl      _cabs
#define ceill(x)    ((long double)ceil((double)(x)))
#define cosl(x)     ((long double)cos((double)(x)))
#define coshl(x)    ((long double)cosh((double)(x)))
#define expl(x)     ((long double)exp((double)(x)))
#define fabsl(x)    ((long double)fabs((double)(x)))
#define floorl(x)   ((long double)floor((double)(x)))
#define fmodl(x,y)  ((long double)fmod((double)(x), (double)(y)))
#define frexpl(x,y) ((long double)frexp((double)(x), (y)))
#define _hypotl(x,y)    ((long double)_hypot((double)(x), (double)(y)))
#define ldexpl(x,y) ((long double)ldexp((double)(x), (y)))
#define logl(x)     ((long double)log((double)(x)))
#define log10l(x)   ((long double)log10((double)(x)))
#define _matherrl   _matherr
#define modfl(x,y)  ((long double)modf((double)(x), (double *)(y)))
#define powl(x,y)   ((long double)pow((double)(x), (double)(y)))
#define sinl(x)     ((long double)sin((double)(x)))
#define sinhl(x)    ((long double)sinh((double)(x)))
#define sqrtl(x)    ((long double)sqrt((double)(x)))
#define tanl(x)     ((long double)tan((double)(x)))
#define tanhl(x)    ((long double)tanh((double)(x)))
#else   /* __cplusplus */
inline long double acosl(long double _X)
        {return (acos((double)_X)); }
inline long double asinl(long double _X)
        {return (asin((double)_X)); }
inline long double atanl(long double _X)
        {return (atan((double)_X)); }
inline long double atan2l(long double _X, long double _Y)
        {return (atan2((double)_X, (double)_Y)); }
inline long double ceill(long double _X)
        {return (ceil((double)_X)); }
inline long double cosl(long double _X)
        {return (cos((double)_X)); }
inline long double coshl(long double _X)
        {return (cosh((double)_X)); }
inline long double expl(long double _X)
        {return (exp((double)_X)); }
inline long double fabsl(long double _X)
        {return (fabs((double)_X)); }
inline long double floorl(long double _X)
        {return (floor((double)_X)); }
inline long double fmodl(long double _X, long double _Y)
        {return (fmod((double)_X, (double)_Y)); }
inline long double frexpl(long double _X, int *_Y)
        {return (frexp((double)_X, _Y)); }
inline long double ldexpl(long double _X, int _Y)
        {return (ldexp((double)_X, _Y)); }
inline long double logl(long double _X)
        {return (log((double)_X)); }
inline long double log10l(long double _X)
        {return (log10((double)_X)); }
inline long double modfl(long double _X, long double *_Y)
        {double _Di, _Df = modf((double)_X, &_Di);
        *_Y = (long double)_Di;
        return (_Df); }
inline long double powl(long double _X, long double _Y)
        {return (pow((double)_X, (double)_Y)); }
inline long double sinl(long double _X)
        {return (sin((double)_X)); }
inline long double sinhl(long double _X)
        {return (sinh((double)_X)); }
inline long double sqrtl(long double _X)
        {return (sqrt((double)_X)); }
inline long double tanl(long double _X)
        {return (tan((double)_X)); }
inline long double tanhl(long double _X)
        {return (tanh((double)_X)); }

inline float frexpf(float _X, int *_Y)
        {return ((float)frexp((double)_X, _Y)); }
inline float ldexpf(float _X, int _Y)
        {return ((float)ldexp((double)_X, _Y)); }
#if     !defined(_M_MRX000) && !defined(_M_ALPHA)
inline float acosf(float _X)
        {return ((float)acos((double)_X)); }
inline float asinf(float _X)
        {return ((float)asin((double)_X)); }
inline float atanf(float _X)
        {return ((float)atan((double)_X)); }
inline float atan2f(float _X, float _Y)
        {return ((float)atan2((double)_X, (double)_Y)); }
inline float ceilf(float _X)
        {return ((float)ceil((double)_X)); }
inline float cosf(float _X)
        {return ((float)cos((double)_X)); }
inline float coshf(float _X)
        {return ((float)cosh((double)_X)); }
inline float expf(float _X)
        {return ((float)exp((double)_X)); }
inline float fabsf(float _X)
        {return ((float)fabs((double)_X)); }
inline float floorf(float _X)
        {return ((float)floor((double)_X)); }
inline float fmodf(float _X, float _Y)
        {return ((float)fmod((double)_X, (double)_Y)); }
inline float logf(float _X)
        {return ((float)log((double)_X)); }
inline float log10f(float _X)
        {return ((float)log10((double)_X)); }
inline float modff(float _X, float *_Y)
        { double _Di, _Df = modf((double)_X, &_Di);
        *_Y = (float)_Di;
        return ((float)_Df); }
inline float powf(float _X, float _Y)
        {return ((float)pow((double)_X, (double)_Y)); }
inline float sinf(float _X)
        {return ((float)sin((double)_X)); }
inline float sinhf(float _X)
        {return ((float)sinh((double)_X)); }
inline float sqrtf(float _X)
        {return ((float)sqrt((double)_X)); }
inline float tanf(float _X)
        {return ((float)tan((double)_X)); }
inline float tanhf(float _X)
        {return ((float)tanh((double)_X)); }
#endif  /* !defined(_M_MRX000) && !defined(_M_ALPHA) */
#endif  /* __cplusplus */
#endif  /* _M_M68K */
#endif  /* __assembler */

#if     !__STDC__

/* Non-ANSI names for compatibility */

#define DOMAIN      _DOMAIN
#define SING        _SING
#define OVERFLOW    _OVERFLOW
#define UNDERFLOW   _UNDERFLOW
#define TLOSS       _TLOSS
#define PLOSS       _PLOSS

#ifndef _MAC
#define matherr     _matherr
#endif  /* ndef _MAC */

#ifndef __assembler /* Protect from assembler */

_CRTIMP extern double HUGE;

_CRTIMP double  __cdecl cabs(struct _complex);
_CRTIMP double  __cdecl hypot(double, double);
_CRTIMP double  __cdecl j0(double);
_CRTIMP double  __cdecl j1(double);
_CRTIMP double  __cdecl jn(int, double);
        int     __cdecl matherr(struct _exception *);
_CRTIMP double  __cdecl y0(double);
_CRTIMP double  __cdecl y1(double);
_CRTIMP double  __cdecl yn(int, double);

#endif  /* __assembler */

#endif  /* __STDC__ */

#ifdef  _M_M68K
/* definition of _exceptionl struct - this struct is passed to the _matherrl
 * routine when a floating point exception is detected in a long double routine
 */

#ifndef _LD_EXCEPTION_DEFINED

struct _exceptionl {
        int type;           /* exception type - see below */
        char *name;         /* name of function where error occured */
        long double arg1;   /* first argument to function */
        long double arg2;   /* second argument (if any) to function */
        long double retval; /* value to be returned by function */
} ;
#define _LD_EXCEPTION_DEFINED
#endif


/* definition of a _complexl struct to be used by those who use _cabsl and
 * want type checking on their argument
 */

#ifndef _LD_COMPLEX_DEFINED
struct _complexl {
        long double x,y;    /* real and imaginary parts */
} ;
#define _LD_COMPLEX_DEFINED
#endif


long double  __cdecl acosl(long double);
long double  __cdecl asinl(long double);
long double  __cdecl atanl(long double);
long double  __cdecl atan2l(long double, long double);
long double  __cdecl _atold(const char  *);
long double  __cdecl _cabsl(struct _complexl);
long double  __cdecl ceill(long double);
long double  __cdecl cosl(long double);
long double  __cdecl coshl(long double);
long double  __cdecl expl(long double);
long double  __cdecl fabsl(long double);
long double  __cdecl floorl(long double);
long double  __cdecl fmodl(long double, long double);
long double  __cdecl frexpl(long double, int  *);
long double  __cdecl _hypotl(long double, long double);
long double  __cdecl _j0l(long double);
long double  __cdecl _j1l(long double);
long double  __cdecl _jnl(int, long double);
long double  __cdecl ldexpl(long double, int);
long double  __cdecl logl(long double);
long double  __cdecl log10l(long double);
int          __cdecl _matherrl(struct _exceptionl  *);
long double  __cdecl modfl(long double, long double  *);
long double  __cdecl powl(long double, long double);
long double  __cdecl sinl(long double);
long double  __cdecl sinhl(long double);
long double  __cdecl sqrtl(long double);
long double  __cdecl tanl(long double);
long double  __cdecl tanhl(long double);
long double  __cdecl _y0l(long double);
long double  __cdecl _y1l(long double);
long double  __cdecl _ynl(int, long double);

#endif  /* _M_M68K */


#ifdef  __cplusplus
}

#if     !defined(_M_M68K)


template<class _Ty> inline
        _Ty _Pow_int(_Ty _X, int _Y)
        {unsigned int _N;
        if (_Y >= 0)
                _N = _Y;
        else
                _N = -_Y;
        for (_Ty _Z = _Ty(1); ; _X *= _X)
                {if ((_N & 1) != 0)
                        _Z *= _X;
                if ((_N >>= 1) == 0)
                        return (_Y < 0 ? _Ty(1) / _Z : _Z); }}

#ifndef _MSC_EXTENSIONS

inline long __cdecl abs(long _X)
        {return (labs(_X)); }
inline double __cdecl abs(double _X)
        {return (fabs(_X)); }
inline double __cdecl pow(double _X, int _Y)
        {return (_Pow_int(_X, _Y)); }
inline double __cdecl pow(int _X, int _Y)
        {return (_Pow_int(_X, _Y)); }
inline float __cdecl abs(float _X)
        {return (fabsf(_X)); }
inline float __cdecl acos(float _X)
        {return (acosf(_X)); }
inline float __cdecl asin(float _X)
        {return (asinf(_X)); }
inline float __cdecl atan(float _X)
        {return (atanf(_X)); }
inline float __cdecl atan2(float _Y, float _X)
        {return (atan2f(_Y, _X)); }
inline float __cdecl ceil(float _X)
        {return (ceilf(_X)); }
inline float __cdecl cos(float _X)
        {return (cosf(_X)); }
inline float __cdecl cosh(float _X)
        {return (coshf(_X)); }
inline float __cdecl exp(float _X)
        {return (expf(_X)); }
inline float __cdecl fabs(float _X)
        {return (fabsf(_X)); }
inline float __cdecl floor(float _X)
        {return (floorf(_X)); }
inline float __cdecl fmod(float _X, float _Y)
        {return (fmodf(_X, _Y)); }
inline float __cdecl frexp(float _X, int * _Y)
        {return (frexpf(_X, _Y)); }
inline float __cdecl ldexp(float _X, int _Y)
        {return (ldexpf(_X, _Y)); }
inline float __cdecl log(float _X)
        {return (logf(_X)); }
inline float __cdecl log10(float _X)
        {return (log10f(_X)); }
inline float __cdecl modf(float _X, float * _Y)
        {return (modff(_X, _Y)); }
inline float __cdecl pow(float _X, float _Y)
        {return (powf(_X, _Y)); }
inline float __cdecl pow(float _X, int _Y)
        {return (_Pow_int(_X, _Y)); }
inline float __cdecl sin(float _X)
        {return (sinf(_X)); }
inline float __cdecl sinh(float _X)
        {return (sinhf(_X)); }
inline float __cdecl sqrt(float _X)
        {return (sqrtf(_X)); }
inline float __cdecl tan(float _X)
        {return (tanf(_X)); }
inline float __cdecl tanh(float _X)
        {return (tanhf(_X)); }
inline long double __cdecl abs(long double _X)
        {return (fabsl(_X)); }
inline long double __cdecl acos(long double _X)
        {return (acosl(_X)); }
inline long double __cdecl asin(long double _X)
        {return (asinl(_X)); }
inline long double __cdecl atan(long double _X)
        {return (atanl(_X)); }
inline long double __cdecl atan2(long double _Y, long double _X)
        {return (atan2l(_Y, _X)); }
inline long double __cdecl ceil(long double _X)
        {return (ceill(_X)); }
inline long double __cdecl cos(long double _X)
        {return (cosl(_X)); }
inline long double __cdecl cosh(long double _X)
        {return (coshl(_X)); }
inline long double __cdecl exp(long double _X)
        {return (expl(_X)); }
inline long double __cdecl fabs(long double _X)
        {return (fabsl(_X)); }
inline long double __cdecl floor(long double _X)
        {return (floorl(_X)); }
inline long double __cdecl fmod(long double _X, long double _Y)
        {return (fmodl(_X, _Y)); }
inline long double __cdecl frexp(long double _X, int * _Y)
        {return (frexpl(_X, _Y)); }
inline long double __cdecl ldexp(long double _X, int _Y)
        {return (ldexpl(_X, _Y)); }
inline long double __cdecl log(long double _X)
        {return (logl(_X)); }
inline long double __cdecl log10(long double _X)
        {return (log10l(_X)); }
inline long double __cdecl modf(long double _X, long double * _Y)
        {return (modfl(_X, _Y)); }
inline long double __cdecl pow(long double _X, long double _Y)
        {return (powl(_X, _Y)); }
inline long double __cdecl pow(long double _X, int _Y)
        {return (_Pow_int(_X, _Y)); }
inline long double __cdecl sin(long double _X)
        {return (sinl(_X)); }
inline long double __cdecl sinh(long double _X)
        {return (sinhl(_X)); }
inline long double __cdecl sqrt(long double _X)
        {return (sqrtl(_X)); }
inline long double __cdecl tan(long double _X)
        {return (tanl(_X)); }
inline long double __cdecl tanh(long double _X)
        {return (tanhl(_X)); }

#endif  /* _MSC_EXTENSIONS */ 
#endif  /* _M_M68K */ 
#endif  /* __cplusplus */

#ifdef  _MSC_VER
#pragma pack(pop)
#endif  /* _MSC_VER */

#endif  /* _INC_MATH */
/***
*conio.h - console and port I/O declarations
*
*       Copyright (c) 1985-1997, Microsoft Corporation. All rights reserved.
*
*Purpose:
*       This include file contains the function declarations for
*       the MS C V2.03 compatible console I/O routines.
*
*       [Public]
*
****/

#if     _MSC_VER > 1000
#pragma once
#endif

#ifndef _INC_CONIO
#define _INC_CONIO

#if     !defined(_WIN32) && !defined(_MAC)
#error ERROR: Only Mac or Win32 targets supported!
#endif


#ifndef _MAC

#ifdef __cplusplus
extern "C" {
#endif



/* Define _CRTIMP */

#ifndef _CRTIMP
#ifdef  _DLL
#define _CRTIMP __declspec(dllimport)
#else   /* ndef _DLL */
#define _CRTIMP
#endif  /* _DLL */
#endif  /* _CRTIMP */


/* Define __cdecl for non-Microsoft compilers */

#if     ( !defined(_MSC_VER) && !defined(__cdecl) )
#define __cdecl
#endif

/* Define _CRTAPI1 (for compatibility with the NT SDK) */

#ifndef _CRTAPI1
#if	_MSC_VER >= 800 && _M_IX86 >= 300
#define _CRTAPI1 __cdecl
#else
#define _CRTAPI1
#endif
#endif

/* Function prototypes */

_CRTIMP char * __cdecl _cgets(char *);
_CRTIMP int __cdecl _cprintf(const char *, ...);
_CRTIMP int __cdecl _cputs(const char *);
_CRTIMP int __cdecl _cscanf(const char *, ...);
_CRTIMP int __cdecl _getch(void);
_CRTIMP int __cdecl _getche(void);
#ifdef  _M_IX86
int __cdecl _inp(unsigned short);
unsigned short __cdecl _inpw(unsigned short);
unsigned long __cdecl _inpd(unsigned short);
#endif  /* _M_IX86 */
_CRTIMP int __cdecl _kbhit(void);
#ifdef  _M_IX86
int __cdecl _outp(unsigned short, int);
unsigned short __cdecl _outpw(unsigned short, unsigned short);
unsigned long __cdecl _outpd(unsigned short, unsigned long);
#endif  /* _M_IX86 */
_CRTIMP int __cdecl _putch(int);
_CRTIMP int __cdecl _ungetch(int);


#if     !__STDC__

/* Non-ANSI names for compatibility */

_CRTIMP char * __cdecl cgets(char *);
_CRTIMP int __cdecl cprintf(const char *, ...);
_CRTIMP int __cdecl cputs(const char *);
_CRTIMP int __cdecl cscanf(const char *, ...);
#ifdef  _M_IX86
int __cdecl inp(unsigned short);
unsigned short __cdecl inpw(unsigned short);
#endif  /* _M_IX86 */
_CRTIMP int __cdecl getch(void);
_CRTIMP int __cdecl getche(void);
_CRTIMP int __cdecl kbhit(void);
#ifdef  _M_IX86
int __cdecl outp(unsigned short, int);
unsigned short __cdecl outpw(unsigned short, unsigned short);
#endif  /* _M_IX86 */
_CRTIMP int __cdecl putch(int);
_CRTIMP int __cdecl ungetch(int);

#endif  /* __STDC__ */

#ifdef  __cplusplus
}
#endif

#endif  /* _MAC */

#endif  /* _INC_CONIO */

int main()
{
double d,a,b,k,x;
cin>>d;cout<<endl;
cin>>a;cin>>k;
cin>>b;cin>>k;
x=pow(b,d);
cout<<x;
cout<<endl;
cout<<pow(x,d);
return(0);
getche();
}
 