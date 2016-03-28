#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct1.h"

extern int DEBUG;
extern void get_derived_rt();
extern int sizeof_adj_suff;
extern int sizeof_adjl_ppl_suff;
extern int sizeof_adjl_ppl1_suff;
extern int sizeof_pron_noun_suff;
extern struct suff_info adj_suff_info_ar[];
extern struct suff_info adjl_ppl_suff_info_ar[];
extern struct suff_info adjl_ppl1_suff_info_ar[];
extern struct suff_info pron_noun_suff_info_ar[];

void
derived_noun_heuristics(root,pdgm,DBM_FLAG,db_suff,db_lex,ans_root,aux_verb)
char root[SUFFWORDSIZE],pdgm[WORD_SIZE];
int DBM_FLAG;
#ifdef GNU
GDBM_FILE db_lex,db_suff;
#else
DBM *db_lex,*db_suff;
#endif

char ans_root[SUFFWORDSIZE];
char aux_verb[SUFFWORDSIZE];
{
int len,derived_root,pos1,j;
char tmp_root[SUFFWORDSIZE],root_bak[SUFFWORDSIZE],offset_aux_str[SUFFWORDSIZE];
char suffix_2[3],suffix_3[4],suffix_5[6],suffix_6[7];
struct lex_info ans_table[100];
char ans_ar[100][2000];

strcpy(tmp_root,root);
len = strlen(root);

if(len>6)strcpy(suffix_6 , root+len-6); else strcpy(suffix_6,"");
if(len>5)strcpy(suffix_5 , root+len-5); else strcpy(suffix_5,"");
if(len>3)strcpy(suffix_3 , root+len-3); else strcpy(suffix_3,"");
if(len>2)strcpy(suffix_2 , root+len-2); else strcpy(suffix_2,"");

derived_root = 0;
ans_root[0] = '\0';
strcpy(root_bak,root);

if(!strcmp(suffix_5,"avanu") && !strcmp(pdgm,"avanu") && (ans_root[0] == '\0')) {
strcpy(root,root_bak);
derived_root = 1;
get_derived_rt(root,adj_suff_info_ar->suffix,sizeof_adj_suff,sizeof(adj_suff_info_ar[0]),strcmp,DBM_FLAG,db_suff,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_avanu");
}
else
{
strcpy(root,root_bak);
len = strlen(root);
root[len-4] = '\0';
get_derived_rt(root,adjl_ppl_suff_info_ar->suffix,sizeof_adjl_ppl_suff,sizeof(adjl_ppl_suff_info_ar[0]),strcmp,DBM_FLAG,db_suff,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
/*strcat(ans_root,offset_aux_str);*/
strcat(ans_root,"_avanu");
}
else{
strcpy(root,root_bak);
get_derived_rt(root,pron_noun_suff_info_ar->suffix,sizeof_pron_noun_suff,sizeof(pron_noun_suff_info_ar[0]),strcmp,DBM_FLAG,db_suff,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_avanu");
}
}
}
}
else if(!strcmp(suffix_6,"avalYu") && !strcmp(pdgm,"avalYu") && (ans_root[0] == '\0')) {
strcpy(root,root_bak);
derived_root = 1;
get_derived_rt(root,adj_suff_info_ar->suffix,sizeof_adj_suff,sizeof(adj_suff_info_ar[0]),strcmp,DBM_FLAG,db_suff,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_avalYu");
}
else
{
strcpy(root,root_bak);
len = strlen(root);
root[len-5] = '\0';
get_derived_rt(root,adjl_ppl_suff_info_ar->suffix,sizeof_adjl_ppl_suff,sizeof(adjl_ppl_suff_info_ar[0]),strcmp,DBM_FLAG,db_suff,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
/* strcat(ans_root,offset_aux_str); */
strcat(ans_root,"_avalYu");
}
else{
strcpy(root,root_bak);
get_derived_rt(root,pron_noun_suff_info_ar->suffix,sizeof_pron_noun_suff,sizeof(pron_noun_suff_info_ar[0]),strcmp,DBM_FLAG,db_suff,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
/* strcat(ans_root,offset_aux_str); */
strcat(ans_root,"_avalYu");
}
}
}
}
else if(!strcmp(suffix_3,"axu") && !strcmp(pdgm,"axu") && (ans_root[0] == '\0')) {
strcpy(root,root_bak);
derived_root = 1;
get_derived_rt(root,adj_suff_info_ar->suffix,sizeof_adj_suff,sizeof(adj_suff_info_ar[0]),strcmp,DBM_FLAG,db_suff,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_axu");
}
else
{
strcpy(root,root_bak);
len = strlen(root);
root[len-2] = '\0';
get_derived_rt(root,adjl_ppl_suff_info_ar->suffix,sizeof_adjl_ppl_suff,sizeof(adjl_ppl_suff_info_ar[0]),strcmp,DBM_FLAG,db_suff,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
/* strcat(ans_root,offset_aux_str);*/
strcat(ans_root,"_axu");
}
else{
strcpy(root,root_bak);
get_derived_rt(root,pron_noun_suff_info_ar->suffix,sizeof_pron_noun_suff,sizeof(pron_noun_suff_info_ar[0]),strcmp,DBM_FLAG,db_suff,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
/* strcat(ans_root,offset_aux_str);*/
strcat(ans_root,"_axu");
}
}
}
}
else if(!strcmp(suffix_3,"lYu") && !strcmp(pdgm,"avalYu") && (ans_root[0] == '\0')) {
strcpy(root,root_bak);
derived_root = 1;
get_derived_rt(root,adj_suff_info_ar->suffix,sizeof_adj_suff,sizeof(adj_suff_info_ar[0]),strcmp,DBM_FLAG,db_suff,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_avalYu");
}
else{
strcpy(root,root_bak);
get_derived_rt(root,pron_noun_suff_info_ar->suffix,sizeof_pron_noun_suff,sizeof(pron_noun_suff_info_ar[0]),strcmp,DBM_FLAG,db_suff,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_avalYu");
}
}
}
else if(!strcmp(pdgm,"puswaka") && (ans_root[0] == '\0')) {
/* This is put in comments: to avoid wrong the mo analysis:
ASriwa : ASriwa_axu{n na eka *1*}
strcpy(root,root_bak);
derived_root = 1;
strcat(root,"vu");
get_derived_rt(root,adj_suff_info_ar->suffix,sizeof_adj_suff,sizeof(adj_suff_info_ar[0]),strcmp,DBM_FLAG,db_suff,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_axu");
}
else{
*/
strcpy(root,root_bak);
strcat(root,"vu");
/*get_derived_rt(root,pron_noun_suff_info_ar->suffix,sizeof_pron_noun_suff,sizeof(pron_noun_suff_info_ar[0]),strcmp,DBM_FLAG,db_suff,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
*/
get_derived_rt(root,adj_suff_info_ar->suffix,sizeof_adj_suff,sizeof(adj_suff_info_ar[0]),strcmp,DBM_FLAG,db_suff,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_axu");
}
/*
}
*/
}
else if(!strcmp(suffix_2,"nu") && !strcmp(pdgm,"avanu") && (ans_root[0] == '\0')) {
strcpy(root,root_bak);
derived_root = 1;
get_derived_rt(root,adj_suff_info_ar->suffix,sizeof_adj_suff,sizeof(adj_suff_info_ar[0]),strcmp,DBM_FLAG,db_suff,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_avanu");
}
else{
strcpy(root,root_bak);
get_derived_rt(root,pron_noun_suff_info_ar->suffix,sizeof_pron_noun_suff,sizeof(pron_noun_suff_info_ar[0]),strcmp,DBM_FLAG,db_suff,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_avanu");
}
}
}
else if(!strcmp(pdgm,"axu") && (ans_root[0] == '\0')) {
strcpy(root,root_bak);
derived_root = 1;
get_derived_rt(root,adjl_ppl1_suff_info_ar->suffix,sizeof_adjl_ppl1_suff,sizeof(adjl_ppl1_suff_info_ar[0]),strcmp,DBM_FLAG,db_suff,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
/* strcat(ans_root,offset_aux_str);*/
strcat(ans_root,"_axu");
}
}

if(DEBUG && derived_root)
{
printf("%s\n",ans_root);
printf("%d\n",derived_root);
}

}
