#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"

void
get_pdgm_info(fp_pdgm,pdgm,cat,offset_ptr,fseek_ptr)
FILE *fp_pdgm;
char pdgm[WORD_SIZE],cat[20];
int *offset_ptr;
int *fseek_ptr;
{
char str[200];
int len,len1,offset;
fseek(fp_pdgm,*fseek_ptr,0);
fgets(str,90,fp_pdgm);
*fseek_ptr = *fseek_ptr + strlen(str);
for(len=0;str[len]!=',';len++)
pdgm[len]=str[len];
pdgm[len]='\0';
len++; /* To ignore ,*/
for(len1=len;str[len1]!=',';len1++)
cat[len1-len]=str[len1];
cat[len1-len]='\0';
while(!isdigit(str[len1])) len1++;
offset = 0;
while(isdigit(str[len1]))
   { 
    offset = offset *10+str[len1]-'0';
    len1++;
    }
*offset_ptr = offset;
}
