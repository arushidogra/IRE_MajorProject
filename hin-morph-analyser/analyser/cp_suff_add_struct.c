
/**
 * File Name: cp_suff_add_struct 
*/

/** cp_suff_add_struct
 * This function adds the suffix to the root word
 * it takes arguments:
 * suff_add and ch_ar of char type 
 * Return : void 
 */

/* HEADER FILES */
#include <stdio.h>
#include "struct1.h"
#include "struct.h"
#include "morph_logger.h"
extern char *program_name;
extern FILE *log_file;
extern char *log_messg;

//#define FUNCTION "fun_close()"
#define FUNCTION "cp_suff_add_struct()"


void cp_suff_add_struct(suff_add,ch_ar)

char suff_add[SUFFWORDSIZE];  		/* suffix word */
char ch_ar[SUFFWORDSIZE];    		/* added to the root word */

 {
	struct suff_add_info dummy;     /* structure  contains details of suffix */
	int loop1,size;                 /* size of suffix */
		sprintf(log_messg, "INFO: Entering into cp_suff_add_struct() ");
		PRINT_LOG(log_file, log_messg);
	loop1=0;
	size=sizeof(dummy);
		/* if loop equal size. where size is size of  object dummmy of suff_add_info */
		for(loop1=0;loop1<size;loop1++) 
        	 suff_add[loop1]=*ch_ar++;      
		 	 sprintf(log_messg, "INFO: leaving cp_suff_add_struct() with suff as |%c|", suff_add[loop1]); 
			 PRINT_LOG(log_file, log_messg);

 }
