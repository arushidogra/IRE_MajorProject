/**
 * File Name :print.c 
 */

/** Function: resufun
 * This function prints the root, pdgm,priority ,category
 * It takes arguments: root of char array, pdgm of char array ,offset of int type and aux_verb of * char array
 * Return :void 
 */

#include <string.h>
#include <stdio.h>
#include "struct.h"
#include "morph_logger.h"

extern FILE *log_file;
extern char *program_name;

#define FUNCTION "resufun()"

//extern struct order_info order[MAX_NO_OF_CAT];     
extern struct order_ssf_info order[MAX_NO_OF_CAT];
/*The function order gives descrption of category-enumerator-file based on feature-enumerator-file*/
extern char fe_info[][INFOSIZE];	/* fe info */
extern int FOR_USER;                    /* for user friendly output */
extern int ALWAYS_DEFAULT_PARADIGM;     /* considering only default paradigm even 
                                           paradigm is present */
extern int DEFAULT_PARADIGM;            /* neglect when paradigm is found */

void resufun(char *root,char *pdgm,int offset,char *aux_verb)

//char root[WORD_SIZE];                   /* root word */
//char pdgm[SUFFWORDSIZE];                /* paradigm */
//int offset;                             /* offset value */
//char aux_verb[SUFFWORDSIZE];            /* auxilary verb */

 {
   int loop1,loop2,loop3,loop4,loop5;
   int len_fe_info,not_found,no_of_features;/* length of fe,root not found, number of features */
   char category[WORD_SIZE];             /* category */
   /* feature and feature value of word */
   char feature[MAX_NO_OF_CAT][WORD_SIZE],feature_value[MAX_NO_OF_CAT][WORD_SIZE];
    PRINT_LOG(log_file, "printing  the root,pdgm,priority,category");

   len_fe_info = strlen(fe_info[offset-1]);
     /* executs only when fe_info not equal to null */
   for(loop1 = 0;((fe_info[offset-1][loop1] != ' ')&&(fe_info[offset-1][loop1] !='\"')&&(fe_info[offset-1][loop1] != '\0'));++loop1)
       category[loop1] = fe_info[offset-1][loop1];
    
   category[loop1] = '\0';
   if(FOR_USER) /* to check for user friendly output  for category */
     {
      printf("@category: ");
      printf("%s@\n",category);
      }
   else
      printf("%s\n",category);
   if(FOR_USER)/* to check for user friendly output  for root */
      printf("@root:@ ");
   printf("%s\n",root);
 /* if(ALWAYS_DEFAULT_PARADIGM || DEFAULT_PARADIGM)
      {
	if(FOR_USER)
 	printf("INFO: ");
	printf("my_pdgm\n");
	}
  */
   loop2=loop1+1;
   loop3=0;
   while(loop2<len_fe_info)  /* executes when loop2 lessthan length of fe info */
     {
      for(loop1=loop2;(loop1<len_fe_info && fe_info[offset-1][loop1] != ' '); loop1++)                   feature[loop3][loop1-loop2] = fe_info[offset-1][loop1];
      feature[loop3][loop1-loop2] = '\0';
      loop2=loop1+1;
      for(loop1=loop2;(loop1<len_fe_info && fe_info[offset-1][loop1] != ' '); loop1++)
         feature_value[loop3][loop1-loop2] = fe_info[offset-1][loop1];
      feature_value[loop3][loop1-loop2] = '\0';
      loop2=loop1+1;
      loop3++;
     }
   no_of_features=loop3;
   loop4=0;
   while(strcmp(order[loop4].category,category)) /* executes when order.category and guessed category are same */
        loop4++;
 	loop5=0;
	while(order[loop4].feature[loop5][0] != '\0') /* executes when order.feature not null */
	{
	  not_found=1;
	  for(loop3=0;(loop3<no_of_features && not_found);loop3++) /* checks for loop3 less than no of features */
            {
	     if(!strcmp(order[loop4].feature[loop5],feature[loop3])) /*executes when  order.feature and guessed feature are not same */
	       {
	  	 if(FOR_USER)  /* executes when user friendly output */
		   {
	             printf("@%s :",feature[loop3]);
		     printf("%s@\n",feature_value[loop3]);
		    }
		  else
		      printf("%s\n",feature_value[loop3]);
		  not_found = 0;
		 }
               }
             if(not_found)   /* not_found is true */
               {
                if(FOR_USER)/* gets user friendly output when FOR_USER is true */
                  printf("@%s :@",order[loop4].feature[loop5]);
                 printf("\n");
                }
              loop5++;
            }
 }
