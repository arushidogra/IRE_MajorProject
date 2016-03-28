/*******THIS PROGRAM CONVERTS .p FILES INTO REQUIRED FORMAT ******/
/*******IT'S INPUT IS Ca,Ce,Fe,.p FILES CREATED BY LINGUISTICS ***/
/************* & OUTPUT ARE feature_values & offset *******************/
/*****************************************************************/
#include <string.h>
#include <stdio.h>
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"

main(argc,argv)
int argc;
char *argv[];
{
FILE *suff_fp,*fpt,*fpt_ce,*Fe_fp,*map_fp;
FILE *fpt_fe_va,*fpt_off;
char word[WORD_SIZE],info[MAX_NO_OF_FICTITIOUS_CAT][WORD_SIZE],global_info[MAX_NO_OF_FICTITIOUS_CAT][WORD_SIZE];
char info_class_rev[MAX_NO_OF_FICTITIOUS_CAT][WORD_SIZE],last_word_found[WORD_SIZE];
char info_class[MAX_NO_OF_FICTITIOUS_CAT][WORD_SIZE],info_map[MAX_NO_OF_FICTITIOUS_CAT][WORD_SIZE];
char category[WORD_SIZE],name[LINE_SIZE],word1[WORD_SIZE];
int is_new_line,global,global_count,temp,info_count,count,no_count;
int tcases,counter,i,j,k,m,found,init;
int const_no,no[MAX_NO_OF_FICTITIOUS_CAT],no_rev[MAX_NO_OF_FICTITIOUS_CAT];
int offset;

int fun_count();
void search();
void prtn();


if ((fpt_ce = fopen("Ce","r")) == NULL)
{
	printf("ERROR : FILE Ce DOES NOT EXISTS\n");
exit(1);
}
if ((Fe_fp = fopen("Fe","r")) == NULL)
{
	printf("ERROR : FILE Fe DOES NOT EXISTS\n");
exit(1);
}
if ((map_fp = fopen("map_file","r")) == NULL)
 {
 printf("ERROR : FILE map_file DOES NOT EXISTS\n");
 exit(1);
 }
if ((fpt_off = fopen("offset","w")) == NULL)
{
	printf("ERROR : FILE offset can not be created\n");
exit(1);
}
if ((fpt_fe_va = fopen("feature_value","w")) == NULL)
{
	printf("ERROR : FILE offset can not be created\n");
exit(1);
}
getfileword(fpt_ce,name);
offset=0;
while(name[0]!='\0')
{
fprintf(fpt_off,"%s,%d,",name,offset);
if ((fpt = fopen("Ca","r")) == NULL)
{
	printf("ERROR : FILE Ca DOES NOT EXISTS\n");
exit(1);
}
search(fpt,name);
getfileword(fpt,category);
fclose(fpt);
is_new_line = FALSE;
global = TRUE;
global_count = 0;
m = 0;
while (global && !is_new_line)
{
	if (((temp = getfileword(fpt_ce,word)) == 0)||(temp == -1))
 		is_new_line = TRUE;
	else
	 {
                rewind(Fe_fp);
		search(Fe_fp,name);
       	 	if (fun_count(Fe_fp,last_word_found) == 1)
                 { 
                	rewind(map_fp);
			search(map_fp,word);
	 		getfileword(map_fp,word1);
        		strcpy(global_info[global_count++],last_word_found);
			strcpy(info_map[m++],word1);
		 } 	
        	else
           		global = FALSE;
 	 }
 }
 info_count = 0;
 while(!is_new_line) 
  {
        rewind(map_fp);
	strcpy(info[info_count],word);
	search(map_fp,word);
	getfileword(map_fp,word1);
	strcpy(info_map[m++],word1);
        ++info_count;
	if (getfileword(fpt_ce,word) <= 0)
        	is_new_line = TRUE;
  }
 --info_count;
 count = 0;
 no_count = 1;
 for ( i = info_count;i >= 0;--i)
  {
        rewind(Fe_fp);
        search(Fe_fp,info[i]);
        is_new_line = FALSE;
	const_no = no_count;
        while (!is_new_line)
	 {
 		if(getfileword(Fe_fp,info_class_rev[count]) > 0)
                 {
			no_rev[count++] = const_no;
                        no_count = no_count + const_no;
		 }
                else
                	is_new_line = TRUE;
         }
	no_count = no_count - const_no; 
  }
 --count;
tcases = no_count+1;
for(i = count;i >= 0;--i)
 {
	strcpy(info_class[count-i],info_class_rev[i]);
        no[count-i] = no_rev[i];
 }
if ((info_count == -1)&&(global_count == 0))
	fprintf(fpt_fe_va,"%s\n",category);
	
else
for(counter=1;counter<tcases;counter++)
{

			fprintf(fpt_fe_va,"%s ",category);
			prtn(fpt_fe_va,counter,count,global_info,global_count,info_class,info_map,no,tcases);
 }
fprintf(fpt_off,"%d\n",tcases);
getfileword(fpt_ce,name);
offset=offset+tcases-1;
}
/*fclose(suff_fp);*/
fclose(Fe_fp);
fclose(map_fp);
fclose(fpt_ce);
fclose(fpt_fe_va);
fclose(fpt_off);
}


void prtn(fpt,counter,count,global_info,global_count,cond,info,no,tcases)
FILE *fpt;
char global_info[MAX_NO_OF_FICTITIOUS_CAT][WORD_SIZE],cond[MAX_NO_OF_FICTITIOUS_CAT][WORD_SIZE],info[MAX_NO_OF_FICTITIOUS_CAT][WORD_SIZE];
int counter,count,global_count,no[MAX_NO_OF_FICTITIOUS_CAT],tcases;
{
int i,j,temp,temp1,sum,foundp,tot;

for (i = 0;i < global_count;++i)
fprintf(fpt,"%s %s ",info[i],global_info[i]); 
temp = counter % tcases;
temp1 = temp;
tot = tcases -  1;
j = i;
i = 0; 
while(i <= count) 
 {
	sum = 1;
     	foundp = 0;
     	while(sum <= (tot - no[i]))
     	 {
      		if ((sum <= temp1)&&(temp1 <sum +no[i]))
       		 {
        		fprintf(fpt,"%s %s ",info[j],cond[i]);
			++j;
        		foundp = 1;
       		 }
      		sum = sum + no[i];
      		++i;
         }
        if (!foundp)
         {
                fprintf(fpt,"%s %s ",info[j],cond[i]);
                ++j;
         }
        tot = no[i];
        ++i;
     	temp1 = temp%tot;
 }
fprintf(fpt,"\n");
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
			fgetline(next_word,fpt);
         }
 }

int fun_count(fpt,last_word)
FILE *fpt;
char last_word[WORD_SIZE];
{
int count = 0;
char word[WORD_SIZE];

strcpy(last_word,"\0");
while (getfileword(fpt,word) > 0)
 {
        strcpy(last_word,word);
        ++count;
 }
 return(count);
}

