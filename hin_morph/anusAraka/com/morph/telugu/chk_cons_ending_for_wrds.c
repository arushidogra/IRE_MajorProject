#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct1.h"

extern int DEBUG;
extern int sizeof_lex;
extern struct lex_info lex_ar[];

void
chk_cons_ending_for_wrds(root,pdgm,DBM_FLAG,db_lex,ans_root,aux_verb)
char root[SUFFWORDSIZE],pdgm[WORD_SIZE];
int DBM_FLAG;
#ifdef GNU
GDBM_FILE db_lex;
#else
DBM *db_lex;
#endif

char ans_root[SUFFWORDSIZE];
char aux_verb[SUFFWORDSIZE];
{
int len,derived_root,pos1,j;
char tmp_root[SUFFWORDSIZE];
struct lex_info ans_table[100];
char ans_ar[100][2000];

strcpy(tmp_root,root);
len = strlen(root);

if((root[len-1] == 'u') && !strcmp(pdgm,"meku")) 
{
root[len-1] = '\0';
dict_lookup(root,DBM_FLAG,db_lex,lex_ar->word,sizeof_lex,sizeof(lex_ar[0]),strcmp,ans_ar);
pos1 = 0;
cp_to_struct(ans_ar,ans_table,&pos1);
j=0;
while(ans_table[j].word[0] !='\0')
 {
if(!strcmp(ans_table[j].word,root) && !strcmp(ans_table[j].pdgm,"rikRA"))
 {
  strcpy(ans_root,root);
  goto LAST;
 }
 j++;
 }  
LAST:
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_u");
}
else
{
if(DEBUG && derived_root)
{
printf("%s\n",ans_root);
printf("%d\n",derived_root);
}
root[len-1] = 'u'; /* restore back the character */
}
}
}
