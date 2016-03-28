#include <stdio.h>
#include <string.h>
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"


void
cp_to_struct(ch_ar,struct_ar,i)
char ch_ar[100][2000];
struct lex_info struct_ar[100];
int *i;
{
struct lex_info *tag;
int j;
j=0;
while(ch_ar[j][0] !='\0')
{
tag = ( struct lex_info *) ch_ar[j];
strcpy(struct_ar[*i].word,tag->word);
strcpy(struct_ar[*i].pdgm,tag->pdgm);
strcpy(struct_ar[*i].cat,tag->cat);
struct_ar[*i].priority=tag->priority;
(*i)++;
j++;
}
struct_ar[*i].word[0] = '\0';
}
