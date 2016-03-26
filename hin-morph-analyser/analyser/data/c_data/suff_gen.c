/*******THIS PROGRAM CONVERTS .p FILES INTO REQUIRED FORMAT ******/
/*******IT'S INPUT IS Ca,Ce,Fe,.p FILES CREATED BY LINGUISTICS ***/
/************* & OUTPUT IS suff_info *******************/
/*****************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../c_data/info.h"
#include "../c_data/defn.h"

void search();
int find();
void reverse();
extern int getfileword();

int main(argc,argv)
int argc;
char *argv[];
{
FILE *tfile_fp,*fpt_suff,*fpt_off;
char name[LINE_SIZE];
int tcases,ind,counter,i,j,k,found,init; //,suff_size;
int offset;
char ch[LINE_SIZE],rt[LINE_SIZE],string1[LINE_SIZE],suffix[LINE_SIZE];
char wa[WORD_SIZE];

if ((fpt_suff = fopen("suff_info","w")) == NULL)
 	printf("ERROR CAN NOT WRITE ON FILE suff_info\n");
for (ind = 0;ind < totfile;++ind)
{
if ((tfile_fp = fopen(filename[ind],"r")) == NULL)
 {
 	printf("ERROR : FILE %s DOES NOT EXISTS\n",filename[ind]);
       	exit(1);
 }
getfileword(tfile_fp,name); /* get the category name */
fgets(ch,LINE_SIZE-1,tfile_fp); /* ignore the new line after the  name of the category */
if ((fpt_off = fopen("offset","r")) == NULL)
 {
	printf("ERROR : FILE offset DOES NOT EXISTS\n");
        exit(1);
 }
search(fpt_off,name); /* what does search return, if name is not found ?*/
fscanf(fpt_off,",%d,%d\n",&offset,&tcases); /* get the offset & total no of cases  for this category */
fclose(fpt_off);
counter = 0;
for (j = 0; j < LINE_SIZE;++j)
	rt[0] = '\0';
fgets(ch,LINE_SIZE-1,tfile_fp);
if (ch[0] == '\"')
 	init = 1;
else
 	init = 0;
{
while(!feof(tfile_fp))
 {
 	if ((counter % tcases) == 0)
  	 {
		for (i = init;((ch[i] != '\"') && (ch[i] != '\n'));++i)
 			rt[i-init] = ch[i];
  			rt[i-init] = '\0';
 	 }
	else
	if (!index(ch,'-')) 
	 {
 		strcpy(string1,"\0");
 		i = init;
 		found = 1;
 		while (found == 1)
		 {
 			k = i;
 			while((ch[i]!='/')&&(ch[i]!='\"')&&(ch[i]!='\n'))
			 {
				string1[i-k] = ch[i];
   				++i;
			 }
			if (ch[i] != '/')
				found = 0;
			for (j=i-k;j<=LINE_SIZE-1;++j)
 				string1[j] = '\0';
			//suff_size =
                        find(string1,rt,suffix,wa);
			fprintf(fpt_suff,"%s,%s,%s,",suffix,wa,rt);
			if (!strcmp(argv[1],"1"))
	   			fprintf(fpt_suff,",");
			else
			if (!strcmp(argv[1],"2"))
	   			fprintf(fpt_suff,"%s,",name);
			fprintf(fpt_suff,"%d\n",offset+counter);
			i = i + 1;
  				string1[0] = '\0';
		 } /*End of '/' while */
	 } /* END OF '-' IF */
        if(counter==tcases-1) counter=0; else counter++;
	fgets(ch,LINE_SIZE-1,tfile_fp);
 }
}
fclose(tfile_fp);
}
fclose(fpt_suff);
return 0;
}



int find(string,rt,suff,wa)
char string[LINE_SIZE],rt[LINE_SIZE],suff[LINE_SIZE],wa[WORD_SIZE];
{
int i = 0,j,k,l,suff_size;

for(j = 0;j < LINE_SIZE;++j) suff[j] = '\0';
for(j = 0;j < WORD_SIZE;++j) wa[j] = '\0';

k=0;
while (((rt[i] == string[k]) || (rt[i] == '?')) && (rt[i]!= '\0')) {

/* Here ? is for a global checking Vowel Harmony  Added for telugu
Originally it was 
while ((rt[i] == string[i])&&(rt[i]!= '\0'))
*/
/* This has been modified to account for the change U->va in Marathi, as in pAUla->pAvalAwa */
        if((string[k+1] == 'a') && (string[k] == 'v') && (rt[i] == '?')) ++k;

/* This has been modified to account for the change xx->x in Marathi, as in axxala->axalA */
        if((string[k+1] == 'a') && (rt[i] == '?') && (rt[i+1] == '?')) ++i;
    	++i; ++k;
}
j = k;
while ((string[k] != '\n')&& (string[k] != '\0') && (string[k] != ' '))
 {
	suff[k-j] = string[k];
   	++k;
 }
k = k - j;
suff_size = k;
for (l = k;l <= LINE_SIZE-1; ++l)
 	suff[l] = '\0';
reverse(suff);
j = i;
while ((rt[i] != '\0') && (rt[i] != '\n') && (rt[i] != ' '))
 {
	wa[i-j] = rt[i];
   	++i;
 }
for (k = i-j;k<= WORD_SIZE-1;++k)
	wa[k] = '\0';
return(suff_size); 
}
void search(fpt,word)
FILE *fpt;
char word[WORD_SIZE];
{
int srch = FALSE;
char next_word[LINE_SIZE];

while ((!feof(fpt)) && !srch)
	if (getfileword(fpt,next_word) > 0)
         {
        	if(strcmp(word,next_word) == 0)
			srch = TRUE;
		else
			fgets(next_word,LINE_SIZE-1,fpt);
         }
 }

void reverse(s)
char *s;
{
int c,i,j;
for(i=0,j=strlen(s)-1;i<j;i++,j--)
{
c=s[i];
s[i]=s[j];
s[j]=c;
}
}
