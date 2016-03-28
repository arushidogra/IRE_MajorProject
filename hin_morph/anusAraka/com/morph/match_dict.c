#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct1.h"
#include <string.h>

extern int INFLTNL;
int
match_in_dict(guessed_root,pdgm,cat,offset,ans_table,ans_ar,k)
char guessed_root[SUFFWORDSIZE],pdgm[WORD_SIZE],cat[CATEGORYWORDSIZE];
int offset,*k;
struct lex_info ans_table[100];
struct ans_struct ans_ar[20];
{
int j,ans,len;
j=0;
ans=0;
while(ans_table[j].word[0] !='\0')
 {
if(!strcmp(ans_table[j].word,guessed_root) && !strcmp(ans_table[j].pdgm,pdgm) && !strcmp(ans_table[j].cat,cat))
 {
  len = strlen(ans_table[j].word);
  ans_ar[*k].root[0] = ans_table[j].priority;
  ans_ar[*k].root[1] = '\0';
  strcat(ans_ar[*k].root,"_");
  strcat(ans_ar[*k].root,ans_table[j].word);
  ans_ar[*k].root[len+2] = '\0';
  ans_ar[*k].offset = offset;
  strcpy(ans_ar[*k].aux_verb,"");
  strcpy(ans_ar[*k].pdgm,ans_table[j].pdgm);
  if(!INFLTNL) strcat(ans_ar[*k].pdgm,"_deri");
  (*k)++;
  ans = 1;
 }
 j++;
 }  
return ans;
}  
