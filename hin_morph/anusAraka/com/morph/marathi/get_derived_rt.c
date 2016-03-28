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
extern void dict_lookup();
extern void cp_to_struct();
extern void get_suff();
extern void vwl_harmony();

void
get_derived_rt(word,base,nel,width,compar,DBM_FLAG,db_lex,cat,ans_root)
char word[SUFFWORDSIZE],*base;
int nel,width,DBM_FLAG;
int (* compar)();
#ifdef GNU
GDBM_FILE db_lex;
#else
DBM *db_lex;
#endif

char ans_root[SUFFWORDSIZE],cat[20];
{
int len,l,pos1,j,i;
char suff[SUFFWORDSIZE],suffix_5[6],suffix_6[7];
char vwl_hrmn_wrd[SUFFWORDSIZE],proposed_root[SUFFWORDSIZE];

struct suff_info *tag_suff;
struct lex_info ans_table[100];
char ans_ar[100][2000];

ans_root[0] = '\0';
len = strlen(word);

if(len>5) strcpy(suffix_5 , word+len-5); else strcpy(suffix_5,"");
if(len>6) strcpy(suffix_6 , word+len-6); else strcpy(suffix_6,"");

if(!strcmp(suffix_5,"lelyA")) { i=5; strcpy(suff,"Aylel");}
else if(!strcmp(suffix_6,"NArYyA")) { i=6; strcpy(suff,"AyYrAN");}
else { i=0;strcpy(suff,"");}

for(l=len-i;l>=0;l--)
{
if (l != len-i) get_suff(word,suff,l);
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
  goto LAST;
 }
 j++;
 }  
if(index(tag_suff->pdgm,'?')) /* if it is a vwl_hrmn_pdgm modify the guessed root by changing the vowels so as to bring in vowel harmony */
{
 /*vwl_harmony(proposed_root,vwl_hrmn_wrd);*/
 vwl_harmony(proposed_root,tag_suff->pdgm,vwl_hrmn_wrd);
 if((vwl_hrmn_wrd[0] != '\0') && strcmp(proposed_root,vwl_hrmn_wrd))
 {
  dict_lookup(vwl_hrmn_wrd,DBM_FLAG,db_lex,lex_ar->word,sizeof_lex,sizeof(lex_ar[0]),strcmp,ans_ar);
 pos1 = 0;
  cp_to_struct_chk_pdgm(ans_ar,ans_table,&pos1,tag_suff->pdgm);
j=0;
while(ans_table[j].word[0] !='\0')
 {
if(!strcmp(ans_table[j].word,vwl_hrmn_wrd) && !strcmp(ans_table[j].pdgm,tag_suff->pdgm))
 {
  strcpy(ans_root,vwl_hrmn_wrd);
  goto LAST;
 }
 j++;
 }  
 }
 strcpy(proposed_root,vwl_hrmn_wrd); 
/* This is done,since if the rt is still not found, now this vwl_hrm_wrds
is to be serached in the derived_rt dict */
}
*tag_suff++;
}  
}
}
LAST:
if(DEBUG)
printf("get_derived_rt3:%s\n",ans_root);
}
