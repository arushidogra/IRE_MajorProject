/**
  * File Name : new_build_struct_hin.c 
  */

/** Function: build_struct
  * This function creates a specfic structure for the rootword,priority pdgm and
  * category. it copies the required data from the dictionary
  * It takes arguments: word of char array, ch_ar1 and ch_ar2 of 2 dimensional char arrays
  * Return : void 
  */ 


#include <string.h>
#include <stdlib.h>
#include "struct.h"

void build_struct(word,ch_ar1,ch_ar2)

   char word[SUFFWORDSIZE];                /* morph word */
   char ch_ar1[SmallArray][LargeArray];    /* */
   char ch_ar2[SmallArray][LargeArray];
     {
        struct lex_info *tag,dummy;        /* lexical structure contains info of word, 
                                              category,paradigm,priority .
                                              declared object pointer and dummy object */
        char * tag_dummy;                   /* dummy tag pointer */
        char  tmp[Lexsize];                 /* tmp word */
        int loop1,loop2,loop3,loop4;
        loop1=0;
        tag= (struct lex_info *)malloc(sizeof(struct lex_info));
        while(ch_ar1[loop1][0] !='\0') /* guessed suff to null */
	{
	   strcpy(tag->word,word);
	   loop3=0;
	   tag->priority=ch_ar1[loop1][loop3]; /* Currently priorities range between 0 to 9 */
	   loop3++;  /* To absorb priority */
	   loop3++;  /* To absorb " */      
	   loop3++;  /* To absorb , */             
	   loop3++;  /* To absorb " */      
	    /* executes when suff != " nad not equal to null */
	   while((ch_ar1[loop1][loop3] != '"') && (ch_ar1[loop1][loop3] != '\0'))
    	    {
		  tmp[loop3-4] = ch_ar1[loop1][loop3];
		   loop3++;
	    }
	   if(loop3>1)  /* checks for loop3 >1 */
 	      tmp[loop3-4] = '\0';
           else 
              tmp[0] = '\0';
	   strcpy(tag->pdgm,tmp);
	   loop3++;  /* To absorb " */      
	   loop3++; /*  To absorb , */
	   loop3++; /*  To absorb " */
	   loop4 = loop3;
	   loop3=0;
    	    /* executes when suff != " nad not equal to null */
	   while(ch_ar1[loop1][loop4] != '"' && ch_ar1[loop1][loop4] != '\0')
              tmp[loop3++] = ch_ar1[loop1][loop4++];
           if(loop3>1)
              tmp[loop3] = '\0';
           else 
              tmp[0] = '\0';
	   strcpy(tag->cat,tmp);
	  /*
	    sscanf(ch_ar1[i],"%s,%s",tag->pdgm,tag->cat);
	  */
	   tag_dummy = (char *)tag;
	   for(loop2=0;loop2<sizeof(dummy);loop2++)
	      ch_ar2[loop1][loop2] = tag_dummy[loop2];
	      loop1++;
	}
	strcpy(ch_ar2[loop1],"");
	}
