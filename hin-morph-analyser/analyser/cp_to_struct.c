/**
 * FILE Name :cp_to_struct.c
*/


/** cp_to_struct 
 * This function copies data ie Priority , pdgm,cat,word to the structure
 * The arguments: 
 * ch_ar of char type, struct_ar object of the structure lex_info and 
 * integer pointer
 * Return : void 
 */

/* HEADER FILES */
#include <stdio.h>
#include <string.h>
#include "struct.h"
#include "morph_logger.h"

extern char *program_name;
extern FILE *log_file;

#define FUNCTION "cp_to_struct()"


void  cp_to_struct(ch_ar,struct_ar,loop1)

  char ch_ar[SmallArray][LargeArray];    /* suffix to be added */
  struct lex_info struct_ar[SmallArray]; /* gives lexical info of suffix */
  int *loop1;
   {
    struct lex_info *tag;  		/* lexical info of a word, ie cat,pdgm suff, root */                        
	int loop2;
        PRINT_LOG(log_file, "Copying data Priority ,PDGM,CAT,WORD to the structure \n");

	loop2=0;
	while(ch_ar[loop2][0] !='\0')   /* if ch_ar is not equal to zero */
	{
          tag = ( struct lex_info *) ch_ar[loop2];
	  strcpy(struct_ar[*loop1].word,tag->word);
          strcpy(struct_ar[*loop1].pdgm,tag->pdgm);
	  strcpy(struct_ar[*loop1].cat,tag->cat);
//	  struct_ar[*loop1].priority=tag->priority;
	  (*loop1)++;
	  loop2++;
	 }
	struct_ar[*loop1].word[0] = '\0';
    }
