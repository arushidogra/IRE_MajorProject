#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../c_data/defn.h"

int main()
{
FILE *fp1,*fp2,*fp3;
char suff[SUFFWORDSIZE],add[LEXWORDSIZE],pdgm[LEXWORDSIZE],cat[CATEGORYWORDSIZE];
int offset,ptr,i,pos,j,no_of_entries;
char str[90],suff_prv[SUFFWORDSIZE],add_prv[LEXWORDSIZE];
if((fp1=fopen("suff_info","r"))==NULL)
{
printf("Error in opening the file suff_info\n");
exit(0);
}
if((fp2=fopen("pdgm_offset_info","w"))==NULL)
{
printf("Error in opening the file pdgm_offset_info\n");
exit(0);
}
if((fp3=fopen("suff_info.c","w"))==NULL)
{
printf("Error in opening the file suff_info.c\n");
exit(0);
}
ptr=0;
fgets(str,90,fp1);
if(feof(fp1)) exit(0);
for(i=0;(str[i]!=' '&&str[i]!=',');i++)
         suff[i]=str[i];
         suff[i]='\0';
       while(str[i]==' ') i++; /* ignore all blanks*/
         pos = i+1; /* To ignore the comma */
j=0;
          for(i=pos;(str[i]!=' '&&str[i]!=',');i++)
             add[j++]=str[i];
             add[j]='\0';
      while(1)
      {
       fprintf(fp3,"{\"%s\",\"%s\",%d,",suff,add,ptr);
       strcpy(suff_prv,suff);
       strcpy(add_prv,add);
       no_of_entries = 0;
   while(!strcmp(suff,suff_prv) && !strcmp(add,add_prv))
      {
       while(str[i]==' ') i++; /* ignore all blanks*/
         pos = i+1; /* To ignore the comma */
	  j=0;
          for(i=pos;(str[i]!=' '&&str[i]!=',');i++)
             pdgm[j++]=str[i];
             pdgm[j]='\0';
       while(str[i]==' ') i++; /* ignore all blanks*/
         pos = i+1; /* To ignore the comma */
          j=0;
          for(i=pos;(str[i]!=' '&&str[i]!=',');i++)
             cat[j++]=str[i];
             cat[j]='\0';
       while(str[i]==' ') i++; /* ignore all blanks*/
         pos = i+1; /* To ignore the comma */
while(str[pos]==' ') pos++; /* ignore all blanks*/
          offset = 0;
             while(isdigit(str[pos]))
            {
             offset=offset*10+str[pos]-'0';
             pos++;
            }
fprintf(fp2,"%s,%s,%d\n",pdgm,cat,offset);
fgets(str,90,fp1);
for(i=0;(str[i]!=' '&&str[i]!=',');i++)
         suff[i]=str[i];
         suff[i]='\0';
       while(str[i]==' ') i++; /* ignore all blanks*/
         pos = i+1; /* To ignore the comma */
          j=0;
          for(i=pos;(str[i]!=' '&&str[i]!=',');i++)
             add[j++]=str[i];
             add[j]='\0';
          no_of_entries++;
if(feof(fp1)) break;
}
ptr = ftell(fp2);
fprintf(fp3,"%d},\n",no_of_entries);
if(feof(fp1)) break;
}
return 0;
}
