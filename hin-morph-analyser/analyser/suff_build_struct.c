/**
 * FILE NAME : suff_build_struct.c 
 */

/** Function: suff_build_struct
 *  This function creates a table which contains suffix of the word, No of entries, 
 *  word size and position of the word
 *  It takes arguments: word of char array,ch_ar1 of 2 dimensional array and ch_ar2 is 
 *  object of suff_add_info structure
 *  Return: void
*/

#include <stdlib.h>

#include "stdio.h"
#include "string.h"
#include "defn.h"
#include "struct.h"
#include "morph_logger.h"

extern char *program_name;
extern FILE *log_file;

#define FUNCTION "suff_build_struct()"

void suff_build_struct(word,ch_ar1,ch_ar2)
 char word[SUFFWORDSIZE];                /* morph word */
 char ch_ar1[SmallArray][LargeArray];    /* suf word */
 struct suff_add_info ch_ar2[SmallArray];/* suffix structure which contains suffix word
                                              and added data pointer and number of entries */ 
  {
    char  tmp[SmallArray];		 /* temp word */
    int loop1,loop3,loop4; //,loop2;
    PRINT_LOG(log_file, "creating table containing suffix of the word, No of entries, word size and position of the word\n");

    loop1=0;
    while(ch_ar1[loop1][0] !='\0')       /* whiel suff is not null */
     {
       if(!strcmp(word,"0"))             /* compares word with null */
         strcpy(ch_ar2[loop1].suff,"");
       else
         strcpy(ch_ar2[loop1].suff,word);
       loop3=0;
       while(ch_ar1[loop1][loop3] != ',' && ch_ar1[loop1][loop3] != '\0') 
	{
	tmp[loop3] = ch_ar1[loop1][loop3];
	loop3++;
	}
         if(loop3>0)
           tmp[loop3] = '\0';
         else
           tmp[0] = '\0';
         strcpy(ch_ar2[loop1].add,tmp);
         loop3++;
         loop4 = loop3;
         loop3=0;
         while(ch_ar1[loop1][loop4] != ',' && ch_ar1[loop1][loop4] != '\0') tmp[loop3++] = ch_ar1[loop1][loop4++];
           if(loop3>0)
             tmp[loop3] = '\0';
           else
             tmp[0] = '\0';
           ch_ar2[loop1].ptr = atoi(tmp);
           loop4++;
           loop3=0;
           while(ch_ar1[loop1][loop4] != ',' && ch_ar1[loop1][loop4] != '\0') tmp[loop3++] = ch_ar1[loop1][loop4++];
             if(loop3>0)
               tmp[loop3] = '\0';
             else
               tmp[0] = '\0';
             ch_ar2[loop1].no_of_entries = atoi(tmp);
             loop1++;
     }
   strcpy(ch_ar2[loop1].suff,"#");
  }
