#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"


extern struct lex_info lex_ar[];
extern int sizeof_lex;
extern int DEBUG;
extern char * my_blk_bsearch();
extern void get_suff();
extern void dict_lookup();
extern void cp_to_struct();
extern void cp_to_struct_chk_pdgm();
extern void match_in_hypothetical_dict();
extern void vwl_harmony();

void
get_derived_rt(word,base,nel,width,compar,DBM_FLAG,db_suff,db_lex,cat,ans_root,aux_verb,offset_aux_str)
char word[SUFFWORDSIZE],*base;
int nel,width,DBM_FLAG;
int (* compar)();
#ifdef GNU
GDBM_FILE db_lex,db_suff;
#else
DBM *db_lex,*db_suff;
#endif

char ans_root[SUFFWORDSIZE],cat[20];
char aux_verb[SUFFWORDSIZE];
char offset_aux_str[SUFFWORDSIZE];
{
int len,l,pos1,j;
char suff[SUFFWORDSIZE];
char proposed_root[SUFFWORDSIZE],vwl_hrmn_wrd[SUFFWORDSIZE];
char aux_v[SUFFWORDSIZE];

struct suff_info *tag_suff;
struct lex_info ans_table[100];
char ans_ar[100][2000];

ans_root[0] = '\0';
aux_v[0] = '\0';
len = strlen(word);
for(l=len;l>=0;l--)
{
if(l==len) suff[0] = '\0';
else get_suff(word,suff,l);
tag_suff = (struct suff_info *) my_blk_bsearch(suff,base,nel,width,compar);
if(tag_suff != '\0')
{
while(!strcmp(tag_suff->suffix,suff))
{
strncpy(proposed_root,word,l);
proposed_root[l]='\0';
if(DEBUG)
printf ("get_derived_rt1: %s\n",proposed_root);
strcat(proposed_root,tag_suff->add);
dict_lookup(proposed_root,DBM_FLAG,db_lex,lex_ar->word,sizeof_lex,sizeof(lex_ar[0]),strcmp,ans_ar);
pos1 = 0;
cp_to_struct(ans_ar,ans_table,&pos1);
j=0;
while(ans_table[j].word[0] !='\0')
 {
if(!strcmp(ans_table[j].word,proposed_root) && !strcmp(ans_table[j].pdgm,tag_suff->pdgm))
 {
  strcpy(ans_root,proposed_root);
  name_comp_offset(tag_suff->offset,aux_v);
  strcpy(offset_aux_str,aux_v);
if((aux_verb[0] != '\0') && (aux_v[0] != '\0'))
 {
 strcat(aux_v,"_");
 strcat(aux_v,aux_verb);
 strcpy(aux_verb,aux_v);
 }
if((aux_verb[0] == '\0') && (aux_v[0] != '\0'))
 {
 strcpy(aux_verb,aux_v);
 }
  goto LAST;
 }
 j++;
 }  
/* If still answer not found check whether proposed root itself  is a derived root */
if(suff[0] != '\0') /* condition added to avoid infinite loop */
{
if(DEBUG)
printf ("get_derived_rt2: %s\n",proposed_root);
match_in_hypothetical_dict(proposed_root,tag_suff->pdgm,cat,DBM_FLAG,db_suff,db_lex,ans_root,aux_v);
if(ans_root[0] != '\0')
{
if((aux_verb[0] != '\0') && (aux_v[0] != '\0'))
 {
 strcat(aux_v,"_");
 strcat(aux_v,aux_verb);
 strcpy(aux_verb,aux_v);
 }
if((aux_verb[0] == '\0') && (aux_v[0] != '\0'))
 {
 strcpy(aux_verb,aux_v);
 }
name_comp_offset(tag_suff->offset,aux_v);
strcpy(offset_aux_str,aux_v);
if(aux_v[0] != '\0'){
strcat(aux_verb,"_");
strcat(aux_verb,aux_v);
}
goto LAST;
}
}  
*tag_suff++;
}  
}
}
LAST:
if(DEBUG)
printf("get_derived_rt3:%s\n",ans_root);
}
