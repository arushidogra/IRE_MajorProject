/**
 * FILE NAME : fgetword.c 
*/

/** FUNCTION getfileword(fp,word)
 * This function fetches the next word from the current line
 * of the specified file. It returns the length of the word if aword is read;
 * otherwise returns 0 for '\n'(previous word read was the last word in the 
 * line), or returns -1 for '\0'(previous word read was the last word in input).
 * It takes arguments fp file pointer, word of char type, delimitor of char type
 * Return : void 
 */

#include <stdio.h>
#include <ctype.h>
#include "morph_logger.h"

extern char *program_name;
extern FILE *log_file;
#define FUNCTION "fgetword()"

void fgetword(fp,word,delimitor)

 FILE *fp;        	/* file pointer */
 char *word;      	/* char pointer to the morph word */
 char delimitor;  	/* deilmitor  */
  {
    int c;		/* c is return the character read as an unsigned char cast to an int */
    int loop1 = 0;
     c=getc(fp);
   /* checks for end of file or it is delimitor or not equal to new line */
	//PRINT_LOG(log_file, " Fetching the next word from the current line");
     while ((c != EOF) && ( c != delimitor) && ( c !='\n'))  
       	 {
           if(c!=' ') word[loop1++] = c; /* ignore blanks */
             c = getc(fp);
	 }
    word[loop1] = '\0';
  }

