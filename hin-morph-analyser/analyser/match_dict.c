/**
 * File Name : match_dict.c
*/

 /** Function: match_dict
  * This function compares the guessed root, pdgm,cat in the dictionary file
  * It takes the arguments guessed_root of char array ,pdgm of char array ,cat of char array ,
  * offset of int type ,ans_table is object of lex_info structure ,
  * ans_ar is object of ans_struct and k is integer pointer
  * Return:int ,return matching word from dict 
  */


#include "defn.h"
#include "struct.h"
#include "struct1.h"
#include <string.h>

extern int INFLTNL;
int match_in_dict(guessed_root,pdgm,cat,offset,ans_table,ans_ar,loop3)

  /* guessed_root is estimated root,pdgm is paradigm,cat is category */
  char guessed_root[SUFFWORDSIZE],pdgm[WORD_SIZE],cat[CATEGORYWORDSIZE];

  /* offset is an offset value,loop3 is the position of word */
  int offset,*loop3;
  struct lex_info ans_table[SmallArray];  /*is table of cat,pdgm,priority and word */
  struct ans_struct ans_ar[Arraysize];    /* is structure of root word,auxilary word ,paradigm
                                             and offset value */
   {
	int loop2,ans,len;                /* len is length of word */
	loop2=0;
	ans=0;
	while(ans_table[loop2].word[0] !='\0') /* executes only when word is not null */
	 {
	   if(!strcmp(ans_table[loop2].word,guessed_root) && !strcmp
               (ans_table[loop2].pdgm,pdgm) && !strcmp(ans_table[loop2].cat,cat))
             /* checks string comparing for root pdgm cat with guessed ones */
 	      {
	 	  len = strlen(ans_table[loop2].word);
		  ans_ar[*loop3].root[0] = ans_table[loop2].priority;
		  ans_ar[*loop3].root[1] = '\0';
		//  strcat(ans_ar[*loop3].root,"_");
		  strcat(ans_ar[*loop3].root,ans_table[loop2].word);
		  ans_ar[*loop3].root[len+2] = '\0';	
		  ans_ar[*loop3].offset = offset;
		  strcpy(ans_ar[*loop3].aux_verb,"");
		  strcpy(ans_ar[*loop3].pdgm,ans_table[loop2].pdgm);
		  if(!INFLTNL)  /* if flag is true */
		     strcat(ans_ar[*loop3].pdgm,"_deri");
		  (*loop3)++;
		  ans = 1;
 	       }
	     loop2++;
	   }  
        return ans; 
     }  
