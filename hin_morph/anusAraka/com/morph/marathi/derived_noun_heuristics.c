#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct1.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/marathi/morph/c_data/const.h"

extern int DEBUG;

extern int sizeof_NArA_suff;
extern int sizeof_lelA_suff;
extern int sizeof_num_suff;
extern int sizeof_lex;
extern int sizeof_adj_suff;

extern struct suff_info lelA_suff_info_ar[];
extern struct suff_info NArA_suff_info_ar[];
extern struct suff_info num_suff_info_ar[];
extern struct suff_info adj_suff_info_ar[];

extern struct lex_info lex_ar[];

extern void dict_lookup();
extern void cp_to_struct();
extern void get_derived_rt();

void
derived_noun_heuristics(root,pdgm,DBM_FLAG,db_lex,ans_root,aux_verb)
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
char suffix_2[3],suffix_3[4],suffix_4[5],suffix_5[6],suffix_6[7];

struct lex_info ans_table[100];
char ans_ar[100][2000];

strcpy(tmp_root,root);
len = strlen(root);

if(len>2) strcpy(suffix_2 , root+len-2); else strcpy(suffix_2,"");
if(len>3) strcpy(suffix_3 , root+len-3); else strcpy(suffix_3,"");
if(len>4) strcpy(suffix_4 , root+len-4); else strcpy(suffix_4,"");
if(len>5) strcpy(suffix_5 , root+len-5); else strcpy(suffix_5,"");
if(len>6) strcpy(suffix_6 , root+len-6); else strcpy(suffix_6,"");

derived_root = 0;
ans_root[0] = '\0';

if(!strcmp(suffix_4,"yANe") && !strcmp(pdgm,"BAMde")) {
derived_root = 1;
root[len-4] = 'e';
root[len-3] = '\0';
dict_lookup(root,DBM_FLAG,db_lex,lex_ar->word,sizeof_lex,sizeof(lex_ar[0]),strcmp,ans_ar);
pos1 = 0;
cp_to_struct(ans_ar,ans_table,&pos1);
j=0;
while(ans_table[j].word[0] !='\0')
 {
if(!strcmp(ans_table[j].word,root) && !strcmp(ans_table[j].pdgm,"le"))
 {
  strcpy(ans_root,root);
  strcat(ans_root,"_Ne");
  goto LAST;
 }
 j++;
 }  
}
if(!strcmp(suffix_3,"iNe") && !strcmp(pdgm,"BAMde") && ans_root[0] == '\0') {
derived_root = 1;
root[len-3] = 'I';
root[len-2] = '\0';
dict_lookup(root,DBM_FLAG,db_lex,lex_ar->word,sizeof_lex,sizeof(lex_ar[0]),strcmp,ans_ar);
pos1 = 0;
cp_to_struct(ans_ar,ans_table,&pos1);
j=0;
while(ans_table[j].word[0] !='\0')
 {
if(!strcmp(ans_table[j].word,root) && (!strcmp(ans_table[j].pdgm,"pI") || !strcmp(ans_table[j].pdgm,"lihI")))
 {
  strcpy(ans_root,root);
  strcat(ans_root,"_Ne");
  goto LAST;
 }
 j++;
 }  
}
if(!strcmp(suffix_3,"iNe") && !strcmp(pdgm,"BAMde") && ans_root[0] == '\0') {
derived_root = 1;
root[len-3] = 'a';
root[len-2] = '\0';
dict_lookup(root,DBM_FLAG,db_lex,lex_ar->word,sizeof_lex,sizeof(lex_ar[0]),strcmp,ans_ar);
pos1 = 0;
cp_to_struct(ans_ar,ans_table,&pos1);
j=0;
while(ans_table[j].word[0] !='\0')
 {
if(!strcmp(ans_table[j].word,root) && !strcmp(ans_table[j].pdgm,"basava"))
 {
  strcpy(ans_root,root);
  strcat(ans_root,"_Ne");
  goto LAST;
 }
 j++;
 }  
}
if(!strcmp(suffix_2,"Ne") && !strcmp(pdgm,"BAMde") && ans_root[0] == '\0') {
derived_root = 1;
root[len-2] = '\0';
dict_lookup(root,DBM_FLAG,db_lex,lex_ar->word,sizeof_lex,sizeof(lex_ar[0]),strcmp,ans_ar);
pos1 = 0;
cp_to_struct(ans_ar,ans_table,&pos1);
j=0;
while(ans_table[j].word[0] !='\0')
 {
if(!strcmp(ans_table[j].word,root)) 
 {
  strcpy(ans_root,root);
  strcat(ans_root,"_Ne");
  goto LAST;
 }
 j++;
 }  
}

if(!strcmp(suffix_2,"Se") && !strcmp(pdgm,"kavI") && ans_root[0] == '\0') {
derived_root = 1;
get_derived_rt(root,num_suff_info_ar->suffix,sizeof_num_suff,sizeof(num_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root);
if(ans_root[0] != '\0')
{
  strcat(ans_root,"_Se");
  goto LAST;
}
}

if(!strcmp(suffix_2,"vA") && !strcmp(pdgm,"kALA") && ans_root[0] == '\0') {
derived_root = 1;
get_derived_rt(root,num_suff_info_ar->suffix,sizeof_num_suff,sizeof(num_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root);
if(ans_root[0] != '\0')
{
  strcat(ans_root,"_vA");
  goto LAST;
}
}

if(!strcmp(suffix_4,"jaNa") && !strcmp(pdgm,"hAwa") && ans_root[0] == '\0') {
derived_root = 1;
get_derived_rt(root,num_suff_info_ar->suffix,sizeof_num_suff,sizeof(num_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root);
if(ans_root[0] != '\0')
{
  strcat(ans_root,"_jaNa");
  goto LAST;
}
}

if(!strcmp(suffix_4,"jaNI") && !strcmp(pdgm,"kavI") && ans_root[0] == '\0') {
derived_root = 1;
get_derived_rt(root,num_suff_info_ar->suffix,sizeof_num_suff,sizeof(num_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root);
if(ans_root[0] != '\0')
{
  strcat(ans_root,"_jaNI");
  goto LAST;
}
}
if(!strcmp(pdgm,"raswA") && (root[len-1] == 'A') && ans_root[0] == '\0') {
derived_root = 1;
get_derived_rt(root,adj_suff_info_ar->suffix,sizeof_adj_suff,sizeof(adj_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root);
if(ans_root[0] != '\0')
{
  strcat(ans_root,"_adj_m");
  goto LAST;
}
}
if((!strcmp(suffix_2,"sA") || !strcmp(suffix_3,"SyA")) && !strcmp(pdgm,"sahA") && ans_root[0] == '\0') {
derived_root = 1;
get_derived_rt(root,adj_suff_info_ar->suffix,sizeof_adj_suff,sizeof(adj_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root);
if(ans_root[0] != '\0')
{
  strcat(ans_root,"_adj_m");
  goto LAST;
}
}
if(!strcmp(pdgm,"kavI") && (root[len-1] == 'I') && ans_root[0] == '\0') {
derived_root = 1;
get_derived_rt(root,adj_suff_info_ar->suffix,sizeof_adj_suff,sizeof(adj_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root);
if(ans_root[0] != '\0')
{
  strcat(ans_root,"_adj_f");
  goto LAST;
}
}
if(!strcmp(pdgm,"BAMde") && (root[len-1] == 'e') && ans_root[0] == '\0') {
derived_root = 1;
get_derived_rt(root,adj_suff_info_ar->suffix,sizeof_adj_suff,sizeof(adj_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root);
if(ans_root[0] != '\0')
{
  strcat(ans_root,"_adj_n");
  goto LAST;
}
}

if(!strcmp(suffix_2,"SA") && !strcmp(pdgm,"kavI") && ans_root[0] == '\0') {
derived_root = 1;
get_derived_rt(root,adj_suff_info_ar->suffix,sizeof_adj_suff,sizeof(adj_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root);
if(ans_root[0] != '\0')
{
  strcat(ans_root,"_adj_n");
  goto LAST;
}
}

if(!strcmp(suffix_2,"yA") && !strcmp(pdgm,"kavI") && ans_root[0] == '\0') {
derived_root = 1;
get_derived_rt(root,adj_suff_info_ar->suffix,sizeof_adj_suff,sizeof(adj_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root);
if(ans_root[0] != '\0')
{
  strcat(ans_root,"_adj_n");
  goto LAST;
}
}
if(!strcmp(suffix_6,"NArYyA") && !strcmp(pdgm,"puwaNyA") && ans_root[0] == '\0') {
derived_root = 1;
get_derived_rt(root,NArA_suff_info_ar->suffix,sizeof_NArA_suff,sizeof(NArA_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root);
if(ans_root[0] != '\0')
{
  strcat(ans_root,"_NArYyA");
  goto LAST;
}
}
if(!strcmp(suffix_5,"lelyA") && !strcmp(pdgm,"puwaNyA") && ans_root[0] == '\0') {
derived_root = 1;
get_derived_rt(root,lelA_suff_info_ar->suffix,sizeof_lelA_suff,sizeof(lelA_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root);
if(ans_root[0] != '\0')
{
  strcat(ans_root,"_lelyA");
  goto LAST;
}
}

LAST:
if(DEBUG && derived_root)
{
printf("%s\n",ans_root);
printf("%d\n",derived_root);
}
}
