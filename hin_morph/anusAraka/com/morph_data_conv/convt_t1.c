/** THIS FILE CONVERTS GIVEN LEXICON INTO REQUIRED FORMAT **/
/*** IT'S INPUT IS LEXICON FILES CREATED BY LINGUISTICS IN FLAT FORMAT **/
/**************** IT'S OUTPUT IS IN lex.c FILE *******************/
/************************************************************************/
#include <stdio.h> 
#include <string.h>
#include "lext.h" 
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
main()   
{
int i,j,k,found;
char ch[WORD_SIZE],root[WORD_SIZE]; 
FILE *fpt1,*fpt2,*fopen(); 
 
fpt2 = fopen("lex.c","w");
for (i = 0;i< totalf;++i) 
 { 
   	if ((fpt1 = fopen(filename[i],"r")) == NULL)
  		printf("ERROR");
    	fgetline(root,fpt1);
        found = 0;
        if (root[0] = '\"')
        	found = 1; 
        if (found)
        	fprintf(fpt2,"%s,%s,\"\",\n",root,root);
        else
        	fprintf(fpt2,"\"%s\",\"%s\",\"\",\n",root,root);
        fgetline(ch,fpt1);
  	while(ch[0] != '\0')   
   	 { 
               if (found)
   			fprintf(fpt2,"%s,%s,\"\",\n",ch,root);
               else
   			fprintf(fpt2,"\"%s\",\"%s\",\"\",\n",ch,root);
               fgetline(ch,fpt1);
   	 } 
  	fclose(fpt1);
 } 
fclose(fpt2);
} 
 
