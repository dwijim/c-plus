/*
** Program GETKEY.C
**
** Illustrates how to fetch scan code from keyboard.
**
** H. Paul Roach, Morgan State University, July 30, '96
*/


//#include <stdio.h>                                            /* 1 */
//#include <conio.h>  /* for kbhit */                           /* 2 */
//#include <dos.h>                                              /* 3 */

#include "iostream" 
#include "ncurses.h"

                                                             /* 4 */
int getkey(void);                                             /* 5 */
                                                              /* 6 */
void main(void)                                               /* 7 */
{                                                             /* 8 */
   int key;                                                   /* 9 */
   while(1)                                                   /* 10 */
   {                                                          /* 11 */
      if (kbhit)                                              /* 12 */
      {                                                       /* 13 */
         key=getkey();                                        /* 14 */
         printf("%d %x\n", key, key);                         /* 15 */
      }                                                       /* 16 */
   }                                                          /* 17 */
}                                                             /* 18 */
                                                              /* 19 */
int getkey(void)                                              /* 20 */
{                                                             /* 21 */
   union REGS in, out;                                        /* 22 */
   in.h.ah = 0x08;                                            /* 23 */
   int86(0x21, &in, &out);                                    /* 24 */
   if (out.h.al == 0)                                         /* 25 */
   {                                                          /* 26 */
      return(getkey()+0x100);                                 /* 27 */
   }                                                          /* 28 */
   else                                                       /* 29 */
   {                                                          /* 30 */
      return(out.h.al);                                       /* 31 */
   }                                                          /* 32 */
}                                                             /* 33 */