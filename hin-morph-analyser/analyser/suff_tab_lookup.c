/**
 * FILE NAME: suff_tab_lookup.c
 */

/** Function: dbm_suff_tab_lookup
 *  This function checks the suffix word is present in the suff file
 *  It takes arguments: word of char array and db a file pointer of DBM
 *  Return :char , returns suffix word 
*/


#include <string.h>
#include <stdio.h>
#include <gdbm.h>

/* HEADER FILES */
#include <fcntl.h>
#include "defn.h"
#include "struct.h"
#include "morph_logger.h"

extern char *program_name;
extern FILE *log_file;

#define FUNCTION "dbm_suff_tab_lookup()"
/**
 * Prototypes of the functions in this file with a file scope
 */

extern void suff_build_struct();

int dbm_suff_tab_lookup(word,db, ans_array)

char word[SUFFWORDSIZE];   /* morph word */
GDBM_FILE db;              /* GNU database manager includes dbm and ndb compatability and
                               db is used for opening file */
struct suff_add_info ans_array[SmallArray];

  {
    datum db_tag,db_out;   /* datum is function of gdbm , db_tag is key and db_out is content */
    int loop1,loop2;
    /* temp string , pointer for tmp_str , output word */
    char temp_str[BigArray], *ptr_tmp,ans_ar[SmallArray][LargeArray];

    //struct suff_add_info;    /* structure suff_add_info contains details of  suffix , added data
    //                            number of entries, and pointer */
    //char ans_ar1[100];       /* answer array */

// Compile issue solved in Ubuntu-32,64 bit and CentOS-32,64 bit and Fedora-32,64 etc.
   //struct suff_add_info ans_ar1[100];

    PRINT_LOG(log_file, "checking for the suffix word in the suff file\n");
   
    for(loop1=0;loop1<SmallArray;loop1++)    /* intialising suffix to null */
      for(loop2=0;loop2<SmallArray;loop2++)
       ans_ar[loop1][loop2] = '\0';
     db_tag.dptr = word;
     db_tag.dsize = strlen(word);
     db_out = gdbm_fetch(db,db_tag);    /* to search for some data */

/*if(db_out.dptr != '\0') changed for DOS */
     if(db_out.dsize != 0)               /* if size is not null */
 	{
	  strncpy(temp_str,db_out.dptr,db_out.dsize);
	  temp_str[db_out.dsize]='#';
	  temp_str[db_out.dsize+1]='\0';
	  strcpy(ans_ar[0],temp_str);
	  for(loop1=0;;)
	   {
	     if((ptr_tmp = strchr(ans_ar[loop1],'#')) == NULL)break;
	       *ptr_tmp = '\0';
	     strcpy(ans_ar[++loop1],ptr_tmp+1);
           }
        }
      else
         ans_ar[0][0] = '\0';
      suff_build_struct(word,ans_ar,ans_array);
 /*This function creates a specfic structure for the rootword,priority pdgm and
   category. it copies the required data from the dictionary*/
  //return ans_ar1;  //returns the morph word
  return db_out.dsize;
  }
