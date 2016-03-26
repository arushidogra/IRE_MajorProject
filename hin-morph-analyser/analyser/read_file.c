/** 
 * FILE NAME: read_file.c
*/

/** Function:fun_read   and fun_close
 *  These functions are used for 
 *  1: Reads the input word 
 *  2: Checks the end of the input conditions
 *  3: if null the file exits
 *   fun_read() takes arguments 
 *   fun_close takes arguments:fpt,fp_suff db1,db2 are FILE pointers and swit
 *   and DBM_FLAG are of int type
 *   Return : int for fun_Read() and void for fun_close
 */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <gdbm.h>
 
/* HEADER FILES */
#include "defn.h"

#include "morph_logger.h"

extern char *program_name;
extern FILE *log_file;
extern char *log_messg;

extern int YES_NO;  /* for answer is exists or not */  

/**********THIS FUNCTION CHECKS END OF INPUT CONDITIONS *****/
//#define FUNCTION "fun_close()"
// void fun_close(fpt,fp_suff,swit,DBM_FLAG,db1,db2)
void fun_close(fp_suff,swit,DBM_FLAG,db1,db2)
GDBM_FILE db1,db2;

//FILE *fpt,*fp_suff;    /* file pointers for dict and suff */
FILE *fp_suff;    /* file pointers for dict and suff */
int swit,DBM_FLAG;     /* switch and database manager flag */
{
     // if (swit == 0)
       //         fclose(fpt);
        if (DBM_FLAG == 1)
	      {
                gdbm_close(db1);
                gdbm_close(db2);
	      }
        fclose(fp_suff);
//        exit(1);
}



/***********THIS FUNCTION READS INPUT WORD ***************/
#define FUNCTION "fun_read()"
int fun_read(morph,word)

//char num_str[Morphsize];    /* number string used for SSF format */

char morph[Morphsize];      /* morph word */
char word[100];
{
int loop1,loop2,loop3;
int c;                     /* reads the next character from  stream  and  returns  
                              it  as  an unsigned char cast to an int */
//char * line = NULL;
//size_t len = 0;
//ssize_t read;

PRINT_LOG(log_file,"Reading the input word\n");

loop2=0;
loop3=0;
//scanf("%s" ,num_str);
//c=getc(stdin);
c=(int)word[loop3];

sprintf(log_messg,"INFO: index is |%d|", loop3); PRINT_LOG(log_file,log_messg);
	
//&& (c != EOF))   /* executes when c is not alpha numeric and end of file */
while (!isalnum(c)) {

	loop3++;
	if(loop3) {	
		break;
	}
/*if(c=='?'){printf("%c",c);}
	if(c=='.'){printf("%c",c);}
        if(c == '\n') {printf("%c",c);}

	if(YES_NO) 
          printf("%c",c);
        c = getc(stdin);*/
	if(YES_NO)
	printf("%c",c);
	c= (int)word[loop3];

sprintf(log_messg,"INFO: at last line of 1st while |%d|", loop3); PRINT_LOG(log_file,log_messg);
} 
sprintf(log_messg,"INFO: out of while |%d|", loop3); PRINT_LOG(log_file,log_messg);

/* executes when c is alpha numeric */
while(isalnum(c)||ispunct(c)) {	
	loop3++;
       morph[loop2] = c; loop2++;
      // c = getc(stdin); 
	c=(int)word[loop3];
sprintf(log_messg,"INFO: at last line of 2nd while |%d|", loop3); PRINT_LOG(log_file,log_messg);
} 
for (loop1 = loop2;loop1< Morphsize;++loop1) {
	 loop3++;
      morph[loop1] = '\0';
//sprintf(log_messg,"INFO: at last line of 1st for |%d|", loop3); PRINT_LOG(log_file,log_messg);
}
//	ungetc(c,stdin);
//sprintf(log_messg,"INFO: before return(), last read word is |%s|", morph); PRINT_LOG(log_file,log_messg);
return(c);

}
