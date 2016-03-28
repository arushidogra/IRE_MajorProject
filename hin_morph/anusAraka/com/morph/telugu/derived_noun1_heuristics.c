#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct1.h"

extern int DEBUG;

extern int sizeof_yoVkka_suff;

extern struct suff_info noun_yoVkka_suff_info_ar[];
extern void get_derived_rt();

void
derived_noun1_heuristics(root,pdgm,DBM_FLAG,db_lex,ans_root,aux_verb)
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
char offset_aux_str[SUFFWORDSIZE];
char suffix_4[5],suffix_5[6],suffix_6[7];
char suffix_2[3],suffix_7[8],suffix_8[9];
char suffix_9[10],suffix_10[11],suffix_11[12];
char suffix_12[13],suffix_13[14];
char ans_ar[100][2000];
char root_bak[SUFFWORDSIZE];

len = strlen(root);
strcpy(root_bak,root);

if(len>2)strcpy(suffix_2 , root+len-2); else strcpy(suffix_2,"");
if(len>4)strcpy(suffix_4 , root+len-4); else strcpy(suffix_4,"");
if(len>5)strcpy(suffix_5 , root+len-5); else strcpy(suffix_5,"");
if(len>6)strcpy(suffix_6 , root+len-6); else strcpy(suffix_6,"");
if(len>7)strcpy(suffix_7 , root+len-7); else strcpy(suffix_7,"");
if(len>8)strcpy(suffix_8 , root+len-8); else strcpy(suffix_8,"");
if(len>9)strcpy(suffix_9 , root+len-9); else strcpy(suffix_9,"");
if(len>10)strcpy(suffix_10 , root+len-10); else strcpy(suffix_10,"");
if(len>11)strcpy(suffix_11 , root+len-11); else strcpy(suffix_11,"");
if(len>12)strcpy(suffix_12 , root+len-12); else strcpy(suffix_12,"");
if(len>13)strcpy(suffix_13 , root+len-13); else strcpy(suffix_13,"");

derived_root = 0;
ans_root[0] = '\0';


if(!strcmp(suffix_2,"lA") && !strcmp(pdgm,"ninna") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-2] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_lA");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_4,"mIxa") && !strcmp(pdgm,"akkada") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-4] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_mIxa");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_4,"aMwa") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-4] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_aMwa");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_4,"bEta") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-4] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_bEta");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_4,"cotu") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-4] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_cotu");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_4,"kAda") && !strcmp(pdgm,"akkada") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-4] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_kAda");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_4,"lona") && !strcmp(pdgm,"ninna") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-4] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_lona");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_4,"pEna") && !strcmp(pdgm,"akkada") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-4] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_pEna");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_4,"sepu") && !strcmp(pdgm,"munupu") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-4] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_sepu");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_5,"apudu") && !strcmp(pdgm,"appudu") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-5] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_apudu");
}
strcpy(root,root_bak);
}

if(!strcmp(suffix_5,"kiMxa") && !strcmp(pdgm,"akkada") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-5] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_kiMxa");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_5,"muMxu") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-5] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_muMxu");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_5,"ninna") && !strcmp(pdgm,"ninna") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-5] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_ninna");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_5,"pakka") && !strcmp(pdgm,"ninna") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-5] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_pakka");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_6,"aMwata") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-6] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_aMwata");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_6,"appudu") && !strcmp(pdgm,"appudu") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-6] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_appudu");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_6,"bayata") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-6] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_bayata");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_6,"civara") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-6] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_civara");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_6,"eVxata") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-6] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_eVxata");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_6,"eVxuta") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-6] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_eVxuta");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_6,"kriMxa") && !strcmp(pdgm,"akkada") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-6] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_kriMxa");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_6,"lopala") && !strcmp(pdgm,"ninna") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-6] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_lopala");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_6,"lopata") && !strcmp(pdgm,"akkada") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-6] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_lopata");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_6,"mIxata") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-6] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_mIxata");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_6,"munupu") && !strcmp(pdgm,"munupu") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-6] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_munupu");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_6,"nuxuta") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-6] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_nuxuta");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_6,"varaku") && !strcmp(pdgm,"munupu") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-6] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_varaku");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_7,"avawala") && !strcmp(pdgm,"akkada") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-7] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_avawala");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_7,"kiMxata") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-7] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_kiMxata");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_7,"moVxata") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-7] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_moVxata");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_7,"muMgita") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-7] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_muMgita");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_7,"muMxata") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-7] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_muMxata");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_7,"muMxuta") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-7] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_muMxuta");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_7,"noVsata") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-7] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_noVsata");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_7,"pakkana") && !strcmp(pdgm,"akkada") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-7] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_pakkana");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_7,"veVnaka") && !strcmp(pdgm,"ninna") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-7] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_veVnaka");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_7,"veVnuka") && !strcmp(pdgm,"ninna") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-7] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_veVnuka");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_7,"warvAwa") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-7] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_warvAwa");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_7,"xaggara") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-7] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_xaggara");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_7,"xaggira") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-7] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_xaggira");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_8,"kadapata") && !strcmp(pdgm,"akkada") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-8] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_kadapata");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_8,"padamata") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-8] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_padamata");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_8,"waravAwa") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-8] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_waravAwa");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_8,"waruvAwa") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-8] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_waruvAwa");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_8,"kriMxata") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-8] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_kriMxata");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_8,"poVxxuta") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-8] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_poVxxuta");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_9,"proVxxuta") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-9] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_proVxxuta");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_10,"cinnappudu") && !strcmp(pdgm,"appudu") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-10] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_cinnappudu");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_11,"cittacivara") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-11] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_cittacivara");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_11,"eVttaeVxuta") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-11] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_eVttaeVxuta");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_12,"cuttupakkala") && !strcmp(pdgm,"akkada") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-12] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_cuttupakkala");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_13,"cuttuprakkala") && !strcmp(pdgm,"akkada") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-13] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_cuttuprakkala");
}
strcpy(root,root_bak);
}
if(!strcmp(suffix_13,"moVttamoVxata") && !strcmp(pdgm,"moVxata") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-13] = '\0';
get_derived_rt(root,noun_yoVkka_suff_info_ar->suffix,sizeof_yoVkka_suff,sizeof(noun_yoVkka_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_moVttamoVxata");
}
strcpy(root,root_bak);
}
if(DEBUG && derived_root)
{
printf("%s\n",ans_root);
printf("%d\n",derived_root);
}

}
