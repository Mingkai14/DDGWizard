#ifndef P2C_H
#define P2C_H


/* Header file for code generated by "p2c", the Pascal-to-C translator */

/* "p2c"  Copyright (C) 1989 Dave Gillespie, version 1.18.
 * This file may be copied, modified, etc. in any way.  It is not restricted
 * by the licence agreement accompanying p2c itself.
 */


#include <stdio.h>



/* If the following heuristic fails, compile -DBSD=0 for non-BSD systems,
   or -DBSD=1 for BSD systems. */

#ifdef M_XENIX
# define BSD 0
#endif

#ifdef FILE       /* a #define in BSD, a typedef in SYSV (hp-ux, at least) */
# ifndef BSD	  /*  (a convenient, but horrible kludge!) */
#  define BSD 1
# endif
#endif

#ifdef BSD
# if !BSD
#  undef BSD
# endif
#endif


#ifdef __STDC__
# include <stddef.h>
# include <stdlib.h>
# define HAS_STDLIB
# define __CAT__(a,b)a##b
#else
# ifndef BSD
#  include <memory.h>
# endif
# include <sys/types.h>
# define __ID__(a)a
# define __CAT__(a,b)__ID__(a)b
#endif


#ifdef BSD
# include <strings.h>
# define memcpy(a,b,n) (bcopy(b,a,n),a)
# define memcmp(a,b,n) bcmp(a,b,n)
# define strchr(s,c) index(s,c)
# define strrchr(s,c) rindex(s,c)
#else
# include <string.h>
#endif

#include <ctype.h>
#include <math.h>
#include <setjmp.h>
#include <assert.h>


typedef struct __p2c_jmp_buf {
    struct __p2c_jmp_buf *next;
    jmp_buf jbuf;
} __p2c_jmp_buf;


/* Warning: The following will not work if setjmp is used simultaneously.
   This also violates the ANSI restriction about using vars after longjmp,
   but a typical implementation of longjmp will get it right anyway. */

#ifndef FAKE_TRY
# define TRY(x)         do { __p2c_jmp_buf __try_jb;  \
			     __try_jb.next = __top_jb;  \
			     if (!setjmp((__top_jb = &__try_jb)->jbuf)) {
# define RECOVER(x)	__top_jb = __try_jb.next; } else {
# define RECOVER2(x,L)  __top_jb = __try_jb.next; } else {  \
			     if (0) { L: __top_jb = __try_jb.next; }
# define ENDTRY(x)      } } while (0) 
#else
# define TRY(x)         if (1) {
# define RECOVER(x)     } else do {
# define RECOVER2(x,L)  } else do { L: ;
# define ENDTRY(x)      } while (0)
#endif



#ifdef M_XENIX  /* avoid compiler bug */
# define SHORT_MAX  (32767)
# define SHORT_MIN  (-32768)
#endif


/* The following definitions work only on twos-complement machines */
#ifndef SHORT_MAX
# define SHORT_MAX  (((unsigned short) -1) >> 1)
# define SHORT_MIN  (~SHORT_MAX)
#endif

#ifndef INT_MAX
# define INT_MAX    (((unsigned int) -1) >> 1)
# define INT_MIN    (~INT_MAX)
#endif

#ifndef LONG_MAX
# define LONG_MAX   (((unsigned long) -1) >> 1)
# define LONG_MIN   (~LONG_MAX)
#endif

#ifndef SEEK_SET
# define SEEK_SET   0
# define SEEK_CUR   1
# define SEEK_END   2
#endif

#ifndef EXIT_SUCCESS
# define EXIT_SUCCESS  0
# define EXIT_FAILURE  1
#endif


#define SETBITS  32


#ifdef __STDC__
# define Signed     signed
# define Void       void      /* Void f() = procedure */
# ifndef Const
#  define Const     const
# endif
# ifndef Volatile
# define Volatile  volatile
# endif
# define PP(x)      x         /* function prototype */
# define PV()       (void)    /* null function prototype */
typedef void *Anyptr;
#else
# define Signed
# define Void       void
# ifndef Const
#  define Const
# endif
# ifndef Volatile
#  define Volatile
# endif
# define PP(x)      ()
# define PV()       ()
typedef char *Anyptr;
#endif

#ifdef __GNUC__
# define Inline     inline
#else
# define Inline
#endif

#define Register    register  /* Register variables */
#define Char        char      /* Characters (not bytes) */

#ifndef Static
# define Static     static    /* Private global funcs and vars */
#endif

#ifndef Local
# define Local      static    /* Nested functions */
#endif

typedef Signed   char schar;
typedef unsigned char uchar;
typedef unsigned char boolean;

#ifndef true
# define true    1
# define false   0
#endif


typedef struct {
    Anyptr proc, link;
} _PROCEDURE;

#ifndef _FNSIZE
# define _FNSIZE  120
#endif


extern Void    PASCAL_MAIN  PP( (int, Char **) );
extern Char    **P_argv;
extern int     P_argc;
extern short   P_escapecode;
extern int     P_ioresult;
extern __p2c_jmp_buf *__top_jb;


#ifdef P2C_H_PROTO   /* if you have Ansi C but non-prototyped header files */
extern Char    *strcat      PP( (Char *, Const Char *) );
extern Char    *strchr      PP( (Const Char *, int) );
extern int      strcmp      PP( (Const Char *, Const Char *) );
extern Char    *strcpy      PP( (Char *, Const Char *) );
extern size_t   strlen      PP( (Const Char *) );
extern Char    *strncat     PP( (Char *, Const Char *, size_t) );
extern int      strncmp     PP( (Const Char *, Const Char *, size_t) );
extern Char    *strncpy     PP( (Char *, Const Char *, size_t) );
extern Char    *strrchr     PP( (Const Char *, int) );

extern Anyptr   memchr      PP( (Const Anyptr, int, size_t) );
extern Anyptr   memmove     PP( (Anyptr, Const Anyptr, size_t) );
extern Anyptr   memset      PP( (Anyptr, int, size_t) );
#ifndef memcpy
extern Anyptr   memcpy      PP( (Anyptr, Const Anyptr, size_t) );
extern int      memcmp      PP( (Const Anyptr, Const Anyptr, size_t) );
#endif

extern int      atoi        PP( (Const Char *) );
extern double   atof        PP( (Const Char *) );
extern long     atol        PP( (Const Char *) );
extern double   strtod      PP( (Const Char *, Char **) );
extern long     strtol      PP( (Const Char *, Char **, int) );
#endif /*P2C_H_PROTO*/

#ifndef HAS_STDLIB
extern Anyptr   malloc      PP( (size_t) );
extern Void     free        PP( (Anyptr) );
#endif

extern int      _OutMem     PV();
extern int      _CaseCheck  PV();
extern int      _NilCheck   PV();
extern int	_Escape     PP( (int) );
extern int	_EscIO      PP( (int) );

extern long     ipow        PP( (long, long) );
extern Char    *strsub      PP( (Char *, Char *, int, int) );
extern Char    *strltrim    PP( (Char *) );
extern Char    *strrtrim    PP( (Char *) );
extern Char    *strrpt      PP( (Char *, Char *, int) );
extern Char    *strpad      PP( (Char *, Char *, int, int) );
extern int      strpos2     PP( (Char *, Char *, int) );
extern long     memavail    PV();
extern int      P_peek      PP( (FILE *) );
extern int      P_eof       PP( (FILE *) );
extern int      P_eoln      PP( (FILE *) );
extern Void     P_readpaoc  PP( (FILE *, Char *, int) );
extern Void     P_readlnpaoc PP( (FILE *, Char *, int) );
extern long     P_maxpos    PP( (FILE *) );
extern Char    *P_trimname  PP( (Char *, int) );
extern long    *P_setunion  PP( (long *, long *, long *) );
extern long    *P_setint    PP( (long *, long *, long *) );
extern long    *P_setdiff   PP( (long *, long *, long *) );
extern long    *P_setxor    PP( (long *, long *, long *) );
extern int      P_inset     PP( (unsigned, long *) );
extern int      P_setequal  PP( (long *, long *) );
extern int      P_subset    PP( (long *, long *) );
extern long    *P_addset    PP( (long *, unsigned) );
extern long    *P_addsetr   PP( (long *, unsigned, unsigned) );
extern long    *P_remset    PP( (long *, unsigned) );
extern long    *P_setcpy    PP( (long *, long *) );
extern long    *P_expset    PP( (long *, long) );
extern long     P_packset   PP( (long *) );
extern int      P_getcmdline PP( (int l, int h, Char *line) );
extern Void     TimeStamp   PP( (int *Day, int *Month, int *Year,
				 int *Hour, int *Min, int *Sec) );
extern Void	P_sun_argv  PP( (char *, int, int) );


/* I/O error handling */
#define _CHKIO(cond,ior,val,def)  ((cond) ? P_ioresult=0,(val)  \
					  : P_ioresult=(ior),(def))
#define _SETIO(cond,ior)          (P_ioresult = (cond) ? 0 : (ior))

/* Following defines are suitable for the HP Pascal operating system */
#define FileNotFound     10
#define FileNotOpen      13
#define FileWriteError   38
#define BadInputFormat   14
#define EndOfFile        30

/* Creating temporary files */
#if (defined(BSD) || defined(NO_TMPFILE)) && !defined(HAVE_TMPFILE)
# define tmpfile()  (fopen(tmpnam(NULL), "w+"))
#endif

/* File buffers */
#define FILEBUF(f,sc,type) sc int __CAT__(f,_BFLAGS);   \
			   sc type __CAT__(f,_BUFFER)

#define RESETBUF(f,type)   (__CAT__(f,_BFLAGS) = 1)
#define SETUPBUF(f,type)   (__CAT__(f,_BFLAGS) = 0)

#define GETFBUF(f,type)    (*((__CAT__(f,_BFLAGS) == 1 &&   \
			       ((__CAT__(f,_BFLAGS) = 2),   \
				fread(&__CAT__(f,_BUFFER),  \
				      sizeof(type),1,(f)))),\
			      &__CAT__(f,_BUFFER)))
#define AGETFBUF(f,type)   ((__CAT__(f,_BFLAGS) == 1 &&   \
			     ((__CAT__(f,_BFLAGS) = 2),   \
			      fread(&__CAT__(f,_BUFFER),  \
				    sizeof(type),1,(f)))),\
			    __CAT__(f,_BUFFER))

#define PUTFBUF(f,type,v)  (GETFBUF(f,type) = (v))
#define CPUTFBUF(f,v)      (PUTFBUF(f,char,v))
#define APUTFBUF(f,type,v) (memcpy(GETFBUF(f,type), (v),  \
				   sizeof(__CAT__(f,_BUFFER))))

#define GET(f,type)        (__CAT__(f,_BFLAGS) == 1 ?   \
			    fread(&__CAT__(f,_BUFFER),sizeof(type),1,(f)) :  \
			    (__CAT__(f,_BFLAGS) = 1))

#define PUT(f,type)        (fwrite(&__CAT__(f,_BUFFER),sizeof(type),1,(f)),  \
			    (__CAT__(f,_BFLAGS) = 0))
#define CPUT(f)            (PUT(f,char))

#define BUFEOF(f)	   (__CAT__(f,_BFLAGS) != 2 && P_eof(f))
#define BUFFPOS(f)	   (ftell(f) - (__CAT__(f,_BFLAGS) == 2))

typedef struct {
    FILE *f;
    FILEBUF(f,,Char);
    Char name[_FNSIZE];
} _TEXT;

/* Memory allocation */
#ifdef __GCC__
# define Malloc(n)  (malloc(n) ?: (Anyptr)_OutMem())
#else
extern Anyptr __MallocTemp__;
# define Malloc(n)  ((__MallocTemp__ = malloc(n)) ? __MallocTemp__ : (Anyptr)_OutMem())
#endif
#define FreeR(p)    (free((Anyptr)(p)))    /* used if arg is an rvalue */
#define Free(p)     (free((Anyptr)(p)), (p)=NULL)

/* sign extension */
#define SEXT(x,n)   ((x) | -(((x) & (1L<<((n)-1))) << 1))

/* packed arrays */   /* BEWARE: these are untested! */
#define P_getbits_UB(a,i,n,L)   ((int)((a)[(i)>>(L)-(n)] >>   \
				       (((~(i))&((1<<(L)-(n))-1)) << (n)) &  \
				       (1<<(1<<(n)))-1))

#define P_getbits_SB(a,i,n,L)   ((int)((a)[(i)>>(L)-(n)] <<   \
				       (16 - ((((~(i))&((1<<(L)-(n))-1))+1) <<\
					      (n)) >> (16-(1<<(n))))))

#define P_putbits_UB(a,i,x,n,L) ((a)[(i)>>(L)-(n)] |=   \
				 (x) << (((~(i))&((1<<(L)-(n))-1)) << (n)))

#define P_putbits_SB(a,i,x,n,L) ((a)[(i)>>(L)-(n)] |=   \
				 ((x) & (1<<(1<<(n)))-1) <<   \
				 (((~(i))&((1<<(L)-(n))-1)) << (n)))

#define P_clrbits_B(a,i,n,L)    ((a)[(i)>>(L)-(n)] &=   \
				 ~( ((1<<(1<<(n)))-1) <<   \
				   (((~(i))&((1<<(L)-(n))-1)) << (n))) )

/* small packed arrays */
#define P_getbits_US(v,i,n)     ((int)((v) >> ((i)<<(n)) & (1<<(1<<(n)))-1))
#define P_getbits_SS(v,i,n)     ((int)((long)(v) << (SETBITS - (((i)+1) << (n))) >> (SETBITS-(1<<(n)))))
#define P_putbits_US(v,i,x,n)   ((v) |= (x) << ((i) << (n)))
#define P_putbits_SS(v,i,x,n)   ((v) |= ((x) & (1<<(1<<(n)))-1) << ((i)<<(n)))
#define P_clrbits_S(v,i,n)      ((v) &= ~( ((1<<(1<<(n)))-1) << ((i)<<(n)) ))

#define P_max(a,b)   ((a) > (b) ? (a) : (b))
#define P_min(a,b)   ((a) < (b) ? (a) : (b))


/* Fix toupper/tolower on Suns and other stupid BSD systems */
#ifdef toupper
# undef toupper
# undef tolower
# define toupper(c)   my_toupper(c)
# define tolower(c)   my_tolower(c)
#endif

#ifndef _toupper
# if 'A' == 65 && 'a' == 97
#  define _toupper(c)  ((c)-'a'+'A')
#  define _tolower(c)  ((c)-'A'+'a')
# else
#  define _toupper(c)  toupper(c)
#  define _tolower(c)  tolower(c)
# endif
#endif


#endif    /* P2C_H */



/* End. */


