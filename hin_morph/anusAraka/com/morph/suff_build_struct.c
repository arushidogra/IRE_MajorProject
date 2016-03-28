#include "stdio.h"
#include "string.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"

void
suff_build_struct(word,ch_ar1,ch_ar2)
char word[SUFFWORDSIZE];
char ch_ar1[100][2000];
struct suff_add_info ch_ar2[100];
{
char  tmp[100];
int i,j,k,k1;
i=0;
while(ch_ar1[i][0] !='\0')
{
if(!strcmp(word,"0"))  strcpy(ch_ar2[i].suff,"");
else strcpy(ch_ar2[i].suff,word);
k=0;
while(ch_ar1[i][k] != ',' && ch_ar1[i][k] != '\0') tmp[k] = ch_ar1[i][k++];
if(k>0) tmp[k] = '\0';
else tmp[0] = '\0';
strcpy(ch_ar2[i].add,tmp);
k++;
k1 = k;
k=0;
while(ch_ar1[i][k1] != ',' && ch_ar1[i][k1] != '\0') tmp[k++] = ch_ar1[i][k1++];
if(k>0) tmp[k] = '\0';
else tmp[0] = '\0';
ch_ar2[i].ptr = atoi(tmp);
k1++;
k=0;
while(ch_ar1[i][k1] != ',' && ch_ar1[i][k1] != '\0') tmp[k++] = ch_ar1[i][k1++];
if(k>0) tmp[k] = '\0';
else tmp[0] = '\0';
ch_ar2[i].no_of_entries = atoi(tmp);
i++;
}
strcpy(ch_ar2[i].suff,"#");
}
