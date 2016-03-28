#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct1.h"

extern int DEBUG;

extern int sizeof_adj_xi;
extern int sizeof_adj_ni;
extern int sizeof_adj_nEna;
extern int sizeof_adj_pAti;
extern int sizeof_e_suff;

extern struct suff_info adj_xi_ar[];
extern struct suff_info adj_ni_ar[];
extern struct suff_info adj_nEna_ar[];
extern struct suff_info adj_pAti_ar[];
extern struct suff_info e_suff_info_ar[];

extern void get_derived_rt();

void
derived_adj_noun_heuristics(root,pdgm,DBM_FLAG,db_lex,ans_root,aux_verb)
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
int len,derived_root;
char suffix_2[3],suffix_3[4],suffix_4[5],suffix_5[6],suffix_6[7],suffix_7[8],suffix_10[11];
char tmp_root[SUFFWORDSIZE];
char offset_aux_str[SUFFWORDSIZE];

len = strlen(root);
strcpy(tmp_root,root);
if(len>10) strcpy(suffix_10 , root+len-10); else strcpy(suffix_10,"");
if(len>7)strcpy(suffix_7 , root+len-7); else strcpy(suffix_7,"");
if(len>6)strcpy(suffix_6 , root+len-6); else strcpy(suffix_6,"");
if(len>5)strcpy(suffix_5 , root+len-5); else strcpy(suffix_5,"");
if(len>4)strcpy(suffix_4 , root+len-4); else strcpy(suffix_4,"");
if(len>3)strcpy(suffix_3 , root+len-3); else strcpy(suffix_3,"");
if(len>2)strcpy(suffix_2 , root+len-2); else strcpy(suffix_2,"");

derived_root = 0;
ans_root[0] = '\0';

/* vAdEnavAdu Cases */

if((!strcmp(suffix_10,"vAdEnavAdu")) && !strcmp(pdgm,"vAdu")) {
root[len-7] = 'u';
root[len-6] = '\0';
derived_root = 1;
get_derived_rt(root,adj_ni_ar->suffix,sizeof_adj_ni,sizeof(adj_ni_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_ni_vAdu_Ena_vAdu");
}
else{
get_derived_rt(root,adj_xi_ar->suffix,sizeof_adj_xi,sizeof(adj_xi_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_vAdu_Ena_vAdu");
}
}
strcpy(root,tmp_root);
}
/* vArEnavAru Cases */
if((!strcmp(suffix_10,"vArEnavAru")) && !strcmp(pdgm,"vAru")) {
root[len-7] = 'u';
root[len-6] = '\0';
derived_root = 1;
get_derived_rt(root,adj_ni_ar->suffix,sizeof_adj_ni,sizeof(adj_ni_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_ni_vAru_Ena_vAru");
}
else{
get_derived_rt(root,adj_xi_ar->suffix,sizeof_adj_xi,sizeof(adj_xi_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_vAru_Ena_vAru");
}
}
strcpy(root,tmp_root);
}
/* xEnaxi Cases */
if((!strcmp(suffix_7,"xEnaaxi")) && !strcmp(pdgm,"axi")) {
root[len-6] = 'i';
root[len-5] = '\0';
derived_root = 1;
get_derived_rt(root,adj_ni_ar->suffix,sizeof_adj_ni,sizeof(adj_ni_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_ni_xi_Ena_xi");
}
else{
get_derived_rt(root,adj_xi_ar->suffix,sizeof_adj_xi,sizeof(adj_xi_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0')
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_xi_Ena_xi");
}
}
strcpy(root,tmp_root);
}
if((!strcmp(suffix_6,"xEnaxi")) && !strcmp(pdgm,"axi")) {
root[len-5] = 'i';
root[len-4] = '\0';
derived_root = 1;
get_derived_rt(root,adj_ni_ar->suffix,sizeof_adj_ni,sizeof(adj_ni_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_ni_xi_Ena_xi");
}
else{
get_derived_rt(root,adj_xi_ar->suffix,sizeof_adj_xi,sizeof(adj_xi_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_xi_Ena_xi");
}
}
strcpy(root,tmp_root);
}
/* EnvAru Cases */

if((!strcmp(suffix_7,"EnavAru")) && !strcmp(pdgm,"vAru") && ( ans_root[0] == '\0')) {
derived_root = 1;
get_derived_rt(root,adj_nEna_ar->suffix,sizeof_adj_nEna,sizeof(adj_nEna_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_nEna_vAru");
}
strcpy(root,tmp_root);
}
/* EnavAdu Cases */
if((!strcmp(suffix_7,"EnavAdu")) && !strcmp(pdgm,"vAdu") && ( ans_root[0] == '\0')) {
derived_root = 1;
get_derived_rt(root,adj_nEna_ar->suffix,sizeof_adj_nEna,sizeof(adj_nEna_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_nEna_vAdu");
}
strcpy(root,tmp_root);
}
/* Enaxi Cases */
if((!strcmp(suffix_6,"Enaaxi")) && !strcmp(pdgm,"axi") && ( ans_root[0] == '\0')) {
root[len-3] = 'x';
root[len-2] = 'i';
root[len-1] = '\0';
derived_root = 1;
get_derived_rt(root,adj_nEna_ar->suffix,sizeof_adj_nEna,sizeof(adj_nEna_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_nEna_xi");
}
strcpy(root,tmp_root);
}
if((!strcmp(suffix_5,"Enaxi")) && !strcmp(pdgm,"axi") && ( ans_root[0] == '\0')) {
derived_root = 1;
get_derived_rt(root,adj_nEna_ar->suffix,sizeof_adj_nEna,sizeof(adj_nEna_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_nEna_xi");
}
strcpy(root,tmp_root);
}
/* pAtixi Cases */
if((!strcmp(suffix_7,"pAtiaxi")) && !strcmp(pdgm,"axi") && ( ans_root[0] == '\0')) {
root[len-3] = 'x';
root[len-2] = 'i';
root[len-1] = '\0';
derived_root = 1;
get_derived_rt(root,adj_pAti_ar->suffix,sizeof_adj_pAti,sizeof(adj_pAti_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_pAti_xi");
}
strcpy(root,tmp_root);
}
if((!strcmp(suffix_6,"pAtixi")) && !strcmp(pdgm,"axi") && ( ans_root[0] == '\0')) {
derived_root = 1;
get_derived_rt(root,adj_pAti_ar->suffix,sizeof_adj_pAti,sizeof(adj_pAti_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_pAti_xi");
}
strcpy(root,tmp_root);
}
/* vAdu Cases */
if((!strcmp(suffix_4,"vAdu")) && !strcmp(pdgm,"vAdu") && ( ans_root[0] == '\0')) {
derived_root = 1;
get_derived_rt(root,adj_ni_ar->suffix,sizeof_adj_ni,sizeof(adj_ni_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_ni_vAdu");
}
else{
get_derived_rt(root,adj_xi_ar->suffix,sizeof_adj_xi,sizeof(adj_xi_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_vAdu");
}
}
strcpy(root,tmp_root);
}
/* vAru Cases */
if((!strcmp(suffix_4,"vAru")) && !strcmp(pdgm,"vAru") && ( ans_root[0] == '\0')) {
derived_root = 1;
get_derived_rt(root,adj_ni_ar->suffix,sizeof_adj_ni,sizeof(adj_ni_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_ni_vAru");
}
else{
get_derived_rt(root,adj_xi_ar->suffix,sizeof_adj_xi,sizeof(adj_xi_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_vAru");
}
}
strcpy(root,tmp_root);
}
/* axi Cases */
if((!strcmp(suffix_3,"axi")) && !strcmp(pdgm,"axi") && ( ans_root[0] == '\0')) {
root[len-3] = 'x';
root[len-2] = 'i';
root[len-1] = '\0';
derived_root = 1;
get_derived_rt(root,adj_ni_ar->suffix,sizeof_adj_ni,sizeof(adj_ni_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_ni_xi");
}
else{
get_derived_rt(root,adj_xi_ar->suffix,sizeof_adj_xi,sizeof(adj_xi_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_xi");
}
}
strcpy(root,tmp_root);
}
if((!strcmp(suffix_2,"xi")) && !strcmp(pdgm,"axi") && ( ans_root[0] == '\0')) {
derived_root = 1;
get_derived_rt(root,adj_ni_ar->suffix,sizeof_adj_ni,sizeof(adj_ni_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_ni_xi");
}
else{
get_derived_rt(root,adj_xi_ar->suffix,sizeof_adj_xi,sizeof(adj_xi_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_xi");
}
}
strcpy(root,tmp_root);
}
if((!strcmp(suffix_10,"etatuvaMti")) && !strcmp(pdgm,"maMci") && ( ans_root[0] == '\0')) {
derived_root = 1;                                
len = strlen(root);
root[len-9] = '\0';
get_derived_rt(root,e_suff_info_ar->suffix,sizeof_e_suff,sizeof(e_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0')                       
{                                      
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adj_e_tatuvaMti");
}
}

if(DEBUG && derived_root)
{
printf("%s\n",ans_root);
printf("%d\n",derived_root);
}

}
