/**
 * File Name : get_pdgm_info.c
 */


/** Function : get_pdgm_info
 * This function sets the position for the required pdgm, cat, offset in the specified file
 * It takes arguments: fp_pdgm a file pointer, pdgm of char array,cat of char array, offset_ptr
 * of integet pointer and fseek_ptr of integer pointer  
 * Return: void
 */ 
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "defn.h"
#include "morph_logger.h"

extern char *program_name;
extern FILE *log_file;

#define FUNCTION "get_pdgm_info()"

void get_pdgm_info(fp_pdgm,pdgm,cat,offset_ptr,fseek_ptr)

  FILE *fp_pdgm;                        /* file pointer for paradigm files */
  char pdgm[WORD_SIZE],cat[Arraysize];  /* paradigm and category of words  */
  int *offset_ptr;                      /* offset pointer of integer type */
  int *fseek_ptr;
  {
	char str[BigArray];             /* string ie word */
	int len,len1,offset;            /* size of word ,
                                           offset is for case ie direct or indirect etc */
        PRINT_LOG(log_file, " settting the position for the required pdgm, cat, offset in the specified file");
	fseek(fp_pdgm,*fseek_ptr,0);
	fgets(str,90,fp_pdgm);
	/** fseek_ptr = *fseek_ptr + strlen(str); */
	*fseek_ptr = ftell(fp_pdgm);
	for(len=0;str[len]!=',';len++)/* checks for len character is not equal to ',' paradigm */
 	  pdgm[len]=str[len];
        pdgm[len]='\0';
        len++; /* To ignore ','*/
	for(len1=len;str[len1]!=',';len1++)/* checks for len1 is not equal to ',' for category */
	  cat[len1-len]=str[len1];
	cat[len1-len]='\0';
	while(!isdigit(str[len1]))  /* isdigit is not true */
             len1++;
	offset = 0;
	while(isdigit(str[len1]))  /* isdigit is true */
	   { 
	       offset = offset *10+str[len1]-'0';
	       len1++;
	    }
	*offset_ptr = offset;
   }
