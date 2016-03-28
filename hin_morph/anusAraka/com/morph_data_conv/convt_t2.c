/** THIS FILE CONVERTS GIVEN LEXICON INTO REQUIRED FORMAT **/
/*** IT'S INPUT IS LEXICON FILES CREATED BY LINGUISTICS IN TABULAR FORMAT **/
/************************** IT'S OUTPUT IS IN lex.c FILE *******************/
/***************************************************************************/
#include <stdio.h> 
#include <string.h>
#include "lext.h" 
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
main()   
{
int i,j,k,ic,ir; 
char ch[WORD_SIZE],rt[LINE_SIZE],cat_info[LINE_SIZE];
char temp[WORD_SIZE],tempw[WORD_SIZE],tempr[WORD_SIZE],tempc[WORD_SIZE];
FILE *fpt1,*fpt2,*fopen(); 
 
fpt2 = fopen("lex.c","w");
for (i = 0;i< totalf;++i) 
 { 
	if ((fpt1 = fopen(filename[i],"r")) == NULL)
  		  printf("ERROR CAN NOT OPEN FILE %s\n",filename[i]);
    	fgets(cat_info,LINE_SIZE-1,fpt1);
  	while (fgets(ch,WORD_SIZE-1,fpt1) != NULL)
         {
               for (j = 0; ((ch[j] != ' ')&&(ch[j] != '\n'));++j)  
                    	tempw[j] = ch[j];
               for(i= j;i< WORD_SIZE;++i)
                    	tempw[i] = '\0';
               fgets(rt,LINE_SIZE-1,fpt1);
               ir = 0;
               ic = 0;
               while (rt[ir] != '\n')
                {
			for(j = ir;((rt[j]!=',')&&(rt[j]!='\n'));++j)
                       		tempr[j-ir] = rt[j];
                	for(i= j-ir;i< WORD_SIZE;++i)
                    		tempr[i] = '\0';
                	if (rt[j] != '\n')
                    		ir = j+1;
                	else
                    		ir = j;
                         
			for(k = ic;((cat_info[k]!=' ')&&(cat_info[k]!='\n'));++k)
                   		tempc[k-ic] = cat_info[k];
                	for(i= k-ic;i< WORD_SIZE;++i)
                    		tempc[i] = '\0';
                   	if (cat_info[k] != '\n')
                     		ic = k+1;
                   	else
                     		ic = k;
         		if ((char *)strcmp(tempr,"\"NW\"") != NULL)
                       		fprintf(fpt2,"%s,%s,\"%s\",\n",tempw,tempr,tempc);
			 }
		 }
  		fclose(fpt1);
	 } 
  	fclose(fpt2);
} 
 
