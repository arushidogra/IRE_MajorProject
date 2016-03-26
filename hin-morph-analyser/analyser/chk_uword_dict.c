/**
 * File Name:chk_uword_dict.c 
*/

/** chk_uword_dict
 * This function checks the Unkown word is present in the UDictionaryor not
 * It takes arguments:
 * word of char type ,base of char type, width of char type, nel of int type, 
 * answer of char type, compar is function with int return type,
 * DBM_FLAG of iint type and 
 * db object of DBM
 * Return void
 */


#include <string.h>
#include <stdio.h>
#include <gdbm.h>

#include <fcntl.h>
#include "defn.h"
#include "struct1.h"
#include "morph_logger.h"

extern char *program_name;
extern FILE *log_file;
extern char *log_messg;

//#define FUNCTION "fun_close()"
#define FUNCTION "my_blk_bsearch()"

/**
 * Prototypes of the functions in this file with a file scope 
 */

extern char * my_blk_bsearch();

void chk_uword_dict(word,base,nel,width,compar,answer,DBM_FLAG,db)

char base[WORD_SIZE],word[WORD_SIZE];     /* base address of the table, word is input word */
int nel,width;				  /* nel is table size and table width */
int (*compar)();
char answer[BigArray];                    /* answer is the word after search */
int DBM_FLAG;				  /* global dictionary flag ,if 1 then dictionary
                                              is there */
GDBM_FILE db;				  /* GNU database manager includes dbm and ndb
                                             compatability and db is used for opening file */
{
   datum db_tag,db_out;   		  /* datum is function of gdbm , db_tag is key and 
                                             db_out is content */
   struct uword_dict *tag_out;		  /* uword_dict structure contains source language and 
                                             target language words */
   int loop1;
        PRINT_LOG(log_file, "checking whether  the Unkown word is present in the UDictionary or not\n");

 	sprintf(log_messg, "INFO: Entering into chk_uword_dict() to check |%s| ", word); PRINT_LOG(log_file, log_messg);

      for(loop1=0;loop1<BigArray;loop1++)/* if loop1 is not equal to null */
         answer[loop1] = '\0';
      if(DBM_FLAG)                         /* If DBM_FLAG is true */
 	{
          db_tag.dptr = word;
	  db_tag.dsize = strlen(word);
	  db_out = gdbm_fetch(db,db_tag);
	/* if(db_out.dptr != '\0')  changed since it does not work on DOS */
	   if(db_out.dsize != 0)       /* if morph size is not equal zero */
	    {
		strncpy(answer,db_out.dptr,db_out.dsize);
		answer[db_out.dsize] = '\0';
            }
	   else                   /* if zero then answer is null */
                answer[0]='\0';
 	  }
	   else
	    { 
                   /* This function returns the ptr to the location of the
                     key in the table, if it is present  else returns a null */
	      tag_out = (struct uword_dict *)my_blk_bsearch(word,base,nel,width,compar); 
	      if(tag_out != '\0')  /* if tag_out is not equal to null copy tl_word to answer */
	         strcpy(answer,tag_out->tl_word);
	      else        /* answer is equal to null */
                  answer[0]='\0';
             }
 	sprintf(log_messg, "INFO: leaving  chk_uword_dict()  |%s| ", word); PRINT_LOG(log_file, log_messg);
}
