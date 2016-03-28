#include <string.h>
#include <stdio.h>
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"

extern struct order_info order[MAX_NO_OF_CAT];
extern char fe_info[][INFOSIZE];
extern int FOR_USER;
extern int ALWAYS_DEFAULT_PARADIGM;
extern int DEFAULT_PARADIGM;

void
resufun_hori(root,pdgm,offset,aux_verb)
char root[WORD_SIZE];
char pdgm[SUFFWORDSIZE];
int offset;
char aux_verb[SUFFWORDSIZE];
{
int i,j,k,l,m;
int len_fe_info,not_found,no_of_features;
char category[WORD_SIZE];
char feature[MAX_NO_OF_CAT][WORD_SIZE],feature_value[MAX_NO_OF_CAT][WORD_SIZE];

len_fe_info = strlen(fe_info[offset-1]);
for(i = 0;((fe_info[offset-1][i] != ' ')&&(fe_info[offset-1][i] !='\"')&&(fe_info[offset-1][i] != '\0'));++i)
     category[i] = fe_info[offset-1][i];
category[i] = '\0';
if(FOR_USER) printf("ROOT:");
printf("%s{",root);
if(FOR_USER) printf("PDGM:");
	printf("%s ",pdgm);
if(FOR_USER) printf("CAT:");
	printf("%s ",category);
j=i+1;
k=0;
while(j<len_fe_info) 
{
  for(i=j;(i<len_fe_info && fe_info[offset-1][i] != ' '); i++)
      feature[k][i-j] = fe_info[offset-1][i];
  feature[k][i-j] = '\0';
  j=i+1;
  for(i=j;(i<len_fe_info && fe_info[offset-1][i] != ' '); i++)
      feature_value[k][i-j] = fe_info[offset-1][i];
  feature_value[k][i-j] = '\0';
  j=i+1;
  k++;
}
no_of_features=k;
l=0;
while(strcmp(order[l].category,category)) l++;
m=0;
while(order[l].feature[m][0] != '\0')
{
not_found=1;
for(k=0;(k<no_of_features && not_found);k++)
{
	/* Above line added by AMBA, in order to retain the info that the field was empty 02-10-2000 */
	if((!strcmp(order[l].feature[m],"tam")  || !strcmp(order[l].feature[m],"parsarg")) && !strcmp(order[l].feature[m],feature[k]))
        {
	if(strcmp(aux_verb,""))
	{
		if(FOR_USER) printf("TAM:");
        	printf("*");
        	printf("%s_",aux_verb);
   		printf("%s",feature_value[k]);
   		printf("* ");
   		not_found = 0;
	}
              else  
	        { 
		   if(FOR_USER) printf("TAM:");
                   printf("*");
                   printf("%s",feature_value[k]);
                   printf("* ");
   		   not_found = 0;
                }
        }
/* Tam & parsarg are already taken care of. Also 'case & gender' in the case of nouns is of no use 
Removed for Hindi ;
Restored by AMBA on 03/10/2000, since the tam, parsarg were repested twice.*/
   if (!strcmp(order[l].feature[m],feature[k]) && strcmp(order[l].feature[m],"tam") && strcmp(order[l].feature[m],"parsarg"))  
   if (!strcmp(order[l].feature[m],feature[k]))
    {
        if(FOR_USER) printf("%s:",feature[k]);
        printf("%s ",feature_value[k]);
   	not_found = 0;
    } 
}
if(not_found) printf(" ");
m++;
}
printf("}");
}

