#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct1.h"

extern int DEBUG;

extern int sizeof_adaM_suff;
extern int sizeof_wanaM_suff;
extern int sizeof_wunna_suff;
extern int sizeof_ani_suff;
extern int sizeof_ina_suff;
extern int sizeof_e_suff;
extern int sizeof_noun_Ena;
extern int sizeof_noun_lAMti;
extern int sizeof_noun_pron;
extern int sizeof_noun_nom;
extern int sizeof_gala_inf;
extern int sizeof_num_suff;
extern int sizeof_num_gaMta_suff;
extern int sizeof_adv_suff;
extern int sizeof_lex;

extern struct suff_info adaM_suff_info_ar[];
extern struct suff_info wanaM_suff_info_ar[];
extern struct suff_info wunna_suff_info_ar[];
extern struct suff_info ani_suff_info_ar[];
extern struct suff_info ina_suff_info_ar[];
extern struct suff_info e_suff_info_ar[];
extern struct suff_info noun_Ena_ar[];
extern struct suff_info noun_lAMti_ar[];
extern struct suff_info noun_pron_ar[];
extern struct suff_info noun_nom_ar[];
extern struct suff_info gala_inf_vrb_ar[];
extern struct suff_info num_suff_info_ar[];
extern struct suff_info num_gaMta_suff_info_ar[];
extern struct suff_info adv_suff_info_ar[];
extern struct lex_info lex_ar[];

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
char tmp_root[SUFFWORDSIZE],root_bak[SUFFWORDSIZE],offset_aux_str[SUFFWORDSIZE];
char suffix_1[2],suffix_2[3],suffix_3[4],suffix_4[5],suffix_5[6],suffix_6[7],suffix_7[8],suffix_8[9],suffix_9[10],suffix_10[11],suffix_11[12];
struct lex_info ans_table[100];
char ans_ar[100][2000];

strcpy(tmp_root,root);
len = strlen(root);

if(len>9) strcpy(suffix_9 , root+len-9); else strcpy(suffix_9,"");
if(len>8) strcpy(suffix_8 , root+len-8); else strcpy(suffix_8,"");
if(len>7)strcpy(suffix_7 , root+len-7); else strcpy(suffix_7,"");
if(len>6)strcpy(suffix_6 , root+len-6); else strcpy(suffix_6,"");
if(len>5)strcpy(suffix_5 , root+len-5); else strcpy(suffix_5,"");
if(len>4)strcpy(suffix_4 , root+len-4); else strcpy(suffix_4,"");
if(len>3)strcpy(suffix_3 , root+len-3); else strcpy(suffix_3,"");
if(len>2)strcpy(suffix_2 , root+len-2); else strcpy(suffix_2,"");
if(len>1)strcpy(suffix_1 , root+len-1); else strcpy(suffix_1,"");

derived_root = 0;
ans_root[0] = '\0';

if((!strcmp(suffix_6,"emuMxu")) && !strcmp(pdgm,"meku") && ( ans_root[0] == '\0')) {
derived_root = 1;                                
len = strlen(root);
root[len-5] = '\0';
get_derived_rt(root,e_suff_info_ar->suffix,sizeof_e_suff,sizeof(e_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0')                       
{                                      
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_muMxu");
}
}
if(!strcmp(suffix_6,"gawweV") && !strcmp(pdgm,"peVtteV") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
get_derived_rt(root,noun_pron_ar->suffix,sizeof_noun_pron,sizeof(noun_pron_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_gawweV");
}
}
if(!strcmp(suffix_5,"Ayana") && !strcmp(pdgm,"Ayana") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
get_derived_rt(root,noun_pron_ar->suffix,sizeof_noun_pron,sizeof(noun_pron_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_Ayana");
}
}
if(!strcmp(suffix_4,"gAru") && !strcmp(pdgm,"vAru") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
get_derived_rt(root,noun_pron_ar->suffix,sizeof_noun_pron,sizeof(noun_pron_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_gAru");
}
}

if(!strcmp(suffix_4,"gAdu") && !strcmp(pdgm,"vAdu") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
get_derived_rt(root,noun_pron_ar->suffix,sizeof_noun_pron,sizeof(noun_pron_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_gAdu");
}
}

if(!strcmp(suffix_4,"guru") && !strcmp(pdgm,"vAru") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
get_derived_rt(root,num_suff_info_ar->suffix,sizeof_num_suff,sizeof(num_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_maMxi");
}
}

if(!strcmp(suffix_5,"maMxi") && !strcmp(pdgm,"maMxi") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
get_derived_rt(root,num_suff_info_ar->suffix,sizeof_num_suff,sizeof(num_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_maMxi");
}
}

if(!strcmp(pdgm,"maMxi") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
get_derived_rt(root,num_gaMta_suff_info_ar->suffix,sizeof_num_gaMta_suff,sizeof(num_gaMta_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_maMxi");
}
} 

if(!strcmp(suffix_7,"muppAvu") && !strcmp(pdgm,"meku") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
get_derived_rt(root,num_suff_info_ar->suffix,sizeof_num_suff,sizeof(num_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_muppAvu");
}
}

if((!strcmp(suffix_5,"MpAvu") || !strcmp(suffix_5,"MbAvu")) && !strcmp(pdgm,"meku") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
get_derived_rt(root,num_suff_info_ar->suffix,sizeof_num_suff,sizeof(num_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_MpAvu");
}
}

if(!strcmp(suffix_5,"nnara") && !strcmp(pdgm,"kota") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
get_derived_rt(root,num_suff_info_ar->suffix,sizeof_num_suff,sizeof(num_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_ara");
}
}

if(!strcmp(suffix_5,"gaMta") && !strcmp(pdgm,"kota") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
get_derived_rt(root,num_suff_info_ar->suffix,sizeof_num_suff,sizeof(num_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_gaMta");
}
}

if(!strcmp(suffix_4,"iMti") && !strcmp(pdgm,"koti") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
get_derived_rt(root,num_suff_info_ar->suffix,sizeof_num_suff,sizeof(num_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_gaMta");
}
}

/* wunna Cases */

if((!strcmp(suffix_9,"tunnavAdu") || !strcmp(suffix_9,"wunnavAdu") || !strcmp(suffix_9,"cunnavAdu")) && !strcmp(pdgm,"vAdu")) {
derived_root = 1;
get_derived_rt(root,wunna_suff_info_ar->suffix,sizeof_wunna_suff,sizeof(wunna_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_fin_dupf_vAdu");
}
}
else if((!strcmp(suffix_9,"tunnavAru") || !strcmp(suffix_9,"wunnavAru") || !strcmp(suffix_9,"cunnavAru")) && !strcmp(pdgm,"vAru")) {
derived_root = 1;
get_derived_rt(root,wunna_suff_info_ar->suffix,sizeof_wunna_suff,sizeof(wunna_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_fin_dupf_vAru");
}
}
else if((!strcmp(suffix_11,"tunnavAlYlu") || !strcmp(suffix_11,"wunnavAlYlu") || !strcmp(suffix_11,"cunnavAlYlu")) && !strcmp(pdgm,"vAlYlu")) {
derived_root = 1;
root[len-4] = 'r';
root[len-3] = 'u';
root[len-2] = '\0';
get_derived_rt(root,wunna_suff_info_ar->suffix,sizeof_wunna_suff,sizeof(wunna_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_fin_dupf_vAlYlu");
}
}
else if((!strcmp(suffix_8,"tunnaaxi") || !strcmp(suffix_8,"wunnaaxi") || !strcmp(suffix_8,"cunnaaxi")) && !strcmp(pdgm,"axi")) {
derived_root = 1;
len = strlen(root);
root[len-3] = 'x';
root[len-2] = 'i';
root[len-1] = '\0';
get_derived_rt(root,wunna_suff_info_ar->suffix,sizeof_wunna_suff,sizeof(wunna_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_fin_dupf_axi");
}
strcpy(root,tmp_root);
}
else if((!strcmp(suffix_7,"tunnaxi") || !strcmp(suffix_7,"wunnaxi") || !strcmp(suffix_7,"cunnaxi")) && !strcmp(pdgm,"axi")) {
derived_root = 1;
get_derived_rt(root,wunna_suff_info_ar->suffix,sizeof_wunna_suff,sizeof(wunna_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_fin_dupf_axi");
}
}

/* ani cases */

else if(!strcmp(suffix_6,"nivAdu") && !strcmp(pdgm,"vAdu")) {
derived_root = 1;
get_derived_rt(root,ani_suff_info_ar->suffix,sizeof_ani_suff,sizeof(ani_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_neg_adjl_vAdu");
}
}
else if(!strcmp(suffix_6,"nivAru") && !strcmp(pdgm,"vAru")) {
derived_root = 1;
get_derived_rt(root,ani_suff_info_ar->suffix,sizeof_ani_suff,sizeof(ani_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_neg_adjl_vAru");
}
}
else if(!strcmp(suffix_8,"nivAlYlu") && !strcmp(pdgm,"vAlYlu")) {
derived_root = 1;
root[len-4] = 'r';
root[len-3] = 'u';
root[len-2] = '\0';
get_derived_rt(root,ani_suff_info_ar->suffix,sizeof_ani_suff,sizeof(ani_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_neg_adjl_vAlYlu");
}
}
else if(!strcmp(suffix_5,"niaxi") && !strcmp(pdgm,"axi")) { /*anaaxi->aniaxi */
derived_root = 1;
len = strlen(root);
root[len-3] = 'x';
root[len-2] = 'i';
root[len-1] = '\0';
get_derived_rt(root,ani_suff_info_ar->suffix,sizeof_ani_suff,sizeof(ani_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_neg_adjl_axi");
}
strcpy(root,tmp_root);
}
else if(!strcmp(suffix_4,"nixi") && !strcmp(pdgm,"axi")) { /*anaxi->anixi */
derived_root = 1;
get_derived_rt(root,ani_suff_info_ar->suffix,sizeof_ani_suff,sizeof(ani_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_neg_adjl_axi");
}
}

/* ina cases */

else if((!strcmp(suffix_7,"inavAdu") || !strcmp(suffix_7,"nnavAdu")) && !strcmp(pdgm,"vAdu")) {
derived_root = 1;
get_derived_rt(root,ina_suff_info_ar->suffix,sizeof_ina_suff,sizeof(ina_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_fin_ptp_vAdu");
}
}
else if((!strcmp(suffix_7,"inavAru") || !strcmp(suffix_7,"nnavAru")) && !strcmp(pdgm,"vAru")) {
derived_root = 1;
get_derived_rt(root,ina_suff_info_ar->suffix,sizeof_ina_suff,sizeof(ina_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_fin_ptp_vAru");
}
}
else if((!strcmp(suffix_9,"inavAlYlu") || !strcmp(suffix_9,"nnavAlYlu")) && !strcmp(pdgm,"vAlYlu")) {
derived_root = 1;
root[len-4] = 'r';
root[len-3] = 'u';
root[len-2] = '\0';
get_derived_rt(root,ina_suff_info_ar->suffix,sizeof_ina_suff,sizeof(ina_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_fin_ptp_vAlYlu");
}
}
else if(!strcmp(suffix_6,"inaaxi") && !strcmp(pdgm,"axi")) {
derived_root = 1;
len = strlen(root);
root[len-3] = 'x';
root[len-2] = 'i';
root[len-1] = '\0';
get_derived_rt(root,ina_suff_info_ar->suffix,sizeof_ina_suff,sizeof(ina_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_fin_ptp_axi");
}
strcpy(root,tmp_root);
}
else if(!strcmp(suffix_4,"Maxi") && !strcmp(pdgm,"axi")) {
derived_root = 1;
len = strlen(root);
root[len-4] = 'n'; /* vacciMxAniki -> vacciMaxi + ki -> vaccinaxi + ki */
get_derived_rt(root,ina_suff_info_ar->suffix,sizeof_ina_suff,sizeof(ina_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_fin_ptp_axi");
}
strcpy(root,tmp_root);
}
else if((!strcmp(suffix_5,"inaxi") || !strcmp(suffix_5,"nnaxi")) && !strcmp(pdgm,"axi")) {
derived_root = 1;
get_derived_rt(root,ina_suff_info_ar->suffix,sizeof_ina_suff,sizeof(ina_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_fin_ptp_axi");
}
}

/* e cases */

else if(!strcmp(suffix_5,"evAdu") && !strcmp(pdgm,"vAdu")) {
derived_root = 1;
get_derived_rt(root,e_suff_info_ar->suffix,sizeof_e_suff,sizeof(e_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_fin_subj_vAdu");
}
}
else if(!strcmp(suffix_5,"evAru") && !strcmp(pdgm,"vAru")) {
derived_root = 1;
get_derived_rt(root,e_suff_info_ar->suffix,sizeof_e_suff,sizeof(e_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_fin_subj_vAru");
}
}
else if(!strcmp(suffix_7,"evAlYlu") && !strcmp(pdgm,"vAlYlu")) {
derived_root = 1;
root[len-4] = 'r';
root[len-3] = 'u';
root[len-2] = '\0';
get_derived_rt(root,e_suff_info_ar->suffix,sizeof_e_suff,sizeof(e_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_fin_subj_vAlYlu");
}
}
else if(!strcmp(suffix_4,"eaxi") && !strcmp(pdgm,"axi")) {
derived_root = 1;
len = strlen(root);
root[len-3] = 'x';
root[len-2] = 'i';
root[len-1] = '\0';
get_derived_rt(root,e_suff_info_ar->suffix,sizeof_e_suff,sizeof(e_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
strcpy(root,tmp_root);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_fin_subj_axi");
}
}
else if(!strcmp(suffix_3,"exi") && !strcmp(pdgm,"axi")) {
derived_root = 1;
get_derived_rt(root,e_suff_info_ar->suffix,sizeof_e_suff,sizeof(e_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_fin_subj_axi");
}
}

/*adaM cases */

else if((!strcmp(suffix_4,"adaM") || (!strcmp(suffix_4,"ataM")) || !strcmp(suffix_5,"atamu") || !strcmp(suffix_5,"adamu") || !strcmp(suffix_4,"otaM") || !strcmp(suffix_4,"odaM") || !strcmp(suffix_5 ,"otamu") || !strcmp(suffix_5,"odamu") || !strcmp(suffix_4,"ddaM") || !strcmp(suffix_4,"ttaM")) && !strcmp(pdgm,"puswakaM")) {
derived_root = 1;
get_derived_rt(root,adaM_suff_info_ar->suffix,sizeof_adaM_suff,sizeof(adaM_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adaM");
}
}
else if(!strcmp(suffix_3,"uta") && !strcmp(pdgm,"kota")) {
derived_root = 1;
get_derived_rt(root,adaM_suff_info_ar->suffix,sizeof_adaM_suff,sizeof(adaM_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adaM");
}
}
/* wanaM case */
else if((!strcmp(suffix_5,"wanaM") || !strcmp(suffix_5,"xanaM")) && !strcmp(pdgm,"puswakaM")) {
derived_root = 1;
get_derived_rt(root,wanaM_suff_info_ar->suffix,sizeof_wanaM_suff,sizeof(wanaM_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_wanaM");
}
}
if(!strcmp(suffix_6,"galaxi") && !strcmp(pdgm,"axi") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-6] = '\0';
get_derived_rt(root,noun_nom_ar->suffix,sizeof_noun_nom,sizeof(noun_nom_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_gala_xi");
}
else
{
get_derived_rt(root,gala_inf_vrb_ar->suffix,sizeof_gala_inf,sizeof(gala_inf_vrb_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_gala_xi");
}
}
strcpy(root,tmp_root);
}
if(!strcmp(suffix_7,"galaaxi") && !strcmp(pdgm,"axi") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-7] = '\0';
get_derived_rt(root,noun_nom_ar->suffix,sizeof_noun_nom,sizeof(noun_nom_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_gala_xi");
}
else
{
get_derived_rt(root,gala_inf_vrb_ar->suffix,sizeof_gala_inf,sizeof(gala_inf_vrb_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_gala_xi");
}
}
strcpy(root,tmp_root);
}
if(!strcmp(suffix_8,"galavAdu") && !strcmp(pdgm,"vAdu") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-8] = '\0';
get_derived_rt(root,noun_nom_ar->suffix,sizeof_noun_nom,sizeof(noun_nom_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_gala_vAdu");
}
else
{
get_derived_rt(root,gala_inf_vrb_ar->suffix,sizeof_gala_inf,sizeof(gala_inf_vrb_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_gala_vAdu");
}
}
strcpy(root,tmp_root);
}
if(!strcmp(suffix_8,"galavAru") && !strcmp(pdgm,"vAru") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-8] = '\0';
get_derived_rt(root,noun_nom_ar->suffix,sizeof_noun_nom,sizeof(noun_nom_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_gala_vAru");
}
else
{
get_derived_rt(root,gala_inf_vrb_ar->suffix,sizeof_gala_inf,sizeof(gala_inf_vrb_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_gala_vAru");
}
}
strcpy(root,tmp_root);
}
if(!strcmp(suffix_3,"axi") && !strcmp(pdgm,"axi") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-3] = 'x';
root[len-2] = 'i';
root[len-1] = '\0';
strcpy(root_bak,root);
get_derived_rt(root,noun_pron_ar->suffix,sizeof_noun_pron,sizeof(noun_pron_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_xi");
}
else
{
strcpy(root,root_bak);
root[len-3] = '\0';
get_derived_rt(root,noun_Ena_ar->suffix,sizeof_noun_Ena,sizeof(noun_Ena_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_Ena_xi");
}
else
{
strcpy(root,root_bak);
get_derived_rt(root,noun_lAMti_ar->suffix,sizeof_noun_lAMti,sizeof(noun_lAMti_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_lAMti_xi");
}
else
{
strcpy(root,root_bak);
get_derived_rt(root,num_suff_info_ar->suffix,sizeof_num_suff,sizeof(num_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_xi");
}
else
{
strcpy(root,root_bak);
get_derived_rt(root,adv_suff_info_ar->suffix,sizeof_adv_suff,sizeof(adv_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_xi");
}
}
}
}
}
strcpy(root,tmp_root);
}
if(!strcmp(suffix_2,"xi") && !strcmp(pdgm,"axi") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
strcpy(root_bak,root);
get_derived_rt(root,noun_pron_ar->suffix,sizeof_noun_pron,sizeof(noun_pron_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_xi");
}
else
{
root[len-2] = '\0';
get_derived_rt(root,noun_Ena_ar->suffix,sizeof_noun_Ena,sizeof(noun_Ena_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_Ena_xi");
}
else
{
strcpy(root,root_bak);
root[len-2] = '\0';
get_derived_rt(root,noun_lAMti_ar->suffix,sizeof_noun_lAMti,sizeof(noun_lAMti_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_lAMti_xi");
}
else
{
strcpy(root,root_bak);
root[len-2] = '\0';
get_derived_rt(root,num_suff_info_ar->suffix,sizeof_num_suff,sizeof(num_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_xi");
}
else
{
strcpy(root,root_bak);
root[len-2] = '\0';
get_derived_rt(root,adv_suff_info_ar->suffix,sizeof_adv_suff,sizeof(adv_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_xi");
}
}
}
}
}
strcpy(root,tmp_root);
}
if(!strcmp(suffix_4,"vAdu") && !strcmp(pdgm,"vAdu") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
strcpy(root_bak,root);
get_derived_rt(root,noun_pron_ar->suffix,sizeof_noun_pron,sizeof(noun_pron_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_vAdu");
}
else
{
strcpy(root,root_bak);
root[len-4] = '\0';
get_derived_rt(root,noun_Ena_ar->suffix,sizeof_noun_Ena,sizeof(noun_Ena_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_Ena_vAdu");
}
else
{
strcpy(root,root_bak);
root[len-4] = '\0';
get_derived_rt(root,noun_lAMti_ar->suffix,sizeof_noun_lAMti,sizeof(noun_lAMti_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_lAMti_vAdu");
}
else
{
strcpy(root,root_bak);
root[len-4] = '\0';
get_derived_rt(root,num_suff_info_ar->suffix,sizeof_num_suff,sizeof(num_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_vAdu");
}
else
{
strcpy(root,root_bak);
root[len-4] = '\0';
get_derived_rt(root,adv_suff_info_ar->suffix,sizeof_adv_suff,sizeof(adv_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_vAdu");
}
}
}
}
}
strcpy(root,tmp_root);
}
if(!strcmp(suffix_4,"vAru") && !strcmp(pdgm,"vAru") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
strcpy(root_bak,root);
get_derived_rt(root,noun_pron_ar->suffix,sizeof_noun_pron,sizeof(noun_pron_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_vAru");
}
else
{
strcpy(root,root_bak);
root[len-4] = '\0';
get_derived_rt(root,noun_Ena_ar->suffix,sizeof_noun_Ena,sizeof(noun_Ena_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_Ena_vAru");
}
else
{
strcpy(root,root_bak);
root[len-4] = '\0';
get_derived_rt(root,noun_lAMti_ar->suffix,sizeof_noun_lAMti,sizeof(noun_lAMti_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_lAMti_vAru");
}
else
{
strcpy(root,root_bak);
root[len-4] = '\0';
get_derived_rt(root,num_suff_info_ar->suffix,sizeof_num_suff,sizeof(num_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_vAru");
}
else
{
strcpy(root,root_bak);
root[len-4] = '\0';
get_derived_rt(root,adv_suff_info_ar->suffix,sizeof_adv_suff,sizeof(adv_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_vAru");
}
}
}
}
}
strcpy(root,tmp_root);
}
if(!strcmp(suffix_6,"vAlYlu") && !strcmp(pdgm,"vAlYlu") && (ans_root[0] == '\0')) {
derived_root = 1;
root[len-4] = 'r';
root[len-3] = 'u';
root[len-2] = '\0';
len = strlen(root);
strcpy(root_bak,root);
get_derived_rt(root,noun_pron_ar->suffix,sizeof_noun_pron,sizeof(noun_pron_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_vAlYlu");
}
else
{
strcpy(root,root_bak);
root[len-4] = '\0';
root[len-4] = 'r';
root[len-3] = 'u';
root[len-2] = '\0';
get_derived_rt(root,noun_Ena_ar->suffix,sizeof_noun_Ena,sizeof(noun_Ena_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_Ena_vAlYlu");
}
else
{
strcpy(root,root_bak);
root[len-4] = '\0';
root[len-4] = 'r';
root[len-3] = 'u';
root[len-2] = '\0';
get_derived_rt(root,noun_lAMti_ar->suffix,sizeof_noun_lAMti,sizeof(noun_lAMti_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_lAMti_vAlYlu");
}
else
{
strcpy(root,root_bak);
root[len-4] = '\0';
root[len-4] = 'r';
root[len-3] = 'u';
root[len-2] = '\0';
get_derived_rt(root,num_suff_info_ar->suffix,sizeof_num_suff,sizeof(num_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_vAlYlu");
}
else
{
strcpy(root,root_bak);
root[len-4] = '\0';
get_derived_rt(root,adv_suff_info_ar->suffix,sizeof_adv_suff,sizeof(adv_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_vAlYlu");
}
}
}
}
}
strcpy(root,tmp_root);
}
if(!strcmp(suffix_6,"gAlYlu") && !strcmp(pdgm,"vAlYlu") && (ans_root[0] == '\0')) {
derived_root = 1;
root[len-4] = 'd';
root[len-3] = 'u';
root[len-2] = '\0';
len = strlen(root);
strcpy(root_bak,root);
get_derived_rt(root,noun_pron_ar->suffix,sizeof_noun_pron,sizeof(noun_pron_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_gAlYlu");
}
strcpy(root,tmp_root);
}

/* Nouns derived from Adjs:

/* Nouns derived from Adjs:
SreRTa -> SreRTaM/SreRTurAlu/SreRTudu
*/

if(!strcmp(suffix_1,"M") && !strcmp(pdgm,"puswakaM") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-1] = '\0'; /* drop last M */
dict_lookup(root,DBM_FLAG,db_lex,lex_ar->word,sizeof_lex,sizeof(lex_ar[0]),strcmp,ans_ar);
pos1 = 0;
cp_to_struct(ans_ar,ans_table,&pos1);
j=0;
while(ans_table[j].word[0] !='\0')
 {
if(!strcmp(ans_table[j].word,root) && !strcmp(ans_table[j].pdgm,"SreRTa"))
 {
  strcpy(ans_root,root);
  goto LAST1;
 }
 j++;
 }  
LAST1:
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_n");
}
}

if(!strcmp(suffix_5,"urAlu") && !strcmp(pdgm,"velu") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-5] = 'a'; /* drop last urAlu & add a to change it to adj */
root[len-4] = '\0';
dict_lookup(root,DBM_FLAG,db_lex,lex_ar->word,sizeof_lex,sizeof(lex_ar[0]),strcmp,ans_ar);
pos1 = 0;
cp_to_struct(ans_ar,ans_table,&pos1);
j=0;
while(ans_table[j].word[0] !='\0')
 {
if(!strcmp(ans_table[j].word,root) && !strcmp(ans_table[j].pdgm,"SreRTa"))
 {
  strcpy(ans_root,root);
  goto LAST2;
 }
 j++;
 }  
LAST2:
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_f");
}
}
if(!strcmp(suffix_3,"udu") && !strcmp(pdgm,"snehiwudu") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
root[len-3] = 'a'; /* drop last udu & add a to change it to adj */
root[len-2] = '\0';
dict_lookup(root,DBM_FLAG,db_lex,lex_ar->word,sizeof_lex,sizeof(lex_ar[0]),strcmp,ans_ar);
pos1 = 0;
cp_to_struct(ans_ar,ans_table,&pos1);
j=0;
while(ans_table[j].word[0] !='\0')
 {
if(!strcmp(ans_table[j].word,root) && !strcmp(ans_table[j].pdgm,"SreRTa"))
 {
  strcpy(ans_root,root);
  goto LAST3;
 }
 j++;
 }  
LAST3:
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_m");
}
}
else
if(DEBUG && derived_root)
{
printf("%s\n",ans_root);
printf("%d\n",derived_root);
}

}
