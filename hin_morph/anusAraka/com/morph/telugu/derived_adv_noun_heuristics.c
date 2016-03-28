#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct1.h"

extern int DEBUG;

extern int sizeof_adv_xi;
extern int sizeof_e_suff;

extern struct suff_info adv_xi_ar[];
extern struct suff_info e_suff_info_ar[];

extern void get_derived_rt();

void
derived_adv_noun_heuristics(root,pdgm,DBM_FLAG,db_lex,ans_root,aux_verb)
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
char suffix_2[3],suffix_3[4],suffix_4[5],suffix_6[7],suffix_8[9],suffix_10[11];
char tmp_root[SUFFWORDSIZE];
char offset_aux_str[SUFFWORDSIZE];

len = strlen(root);
strcpy(tmp_root,root);
if(len>10)strcpy(suffix_10 , root+len-10); else strcpy(suffix_10,"");
if(len>8)strcpy(suffix_8 , root+len-8); else strcpy(suffix_8,"");
if(len>6)strcpy(suffix_6 , root+len-6); else strcpy(suffix_6,"");
if(len>4)strcpy(suffix_4 , root+len-4); else strcpy(suffix_4,"");
if(len>3)strcpy(suffix_3 , root+len-3); else strcpy(suffix_3,"");
if(len>2)strcpy(suffix_2 , root+len-2); else strcpy(suffix_2,"");

derived_root = 0;
ans_root[0] = '\0';

/*etappudu case */
if(((!strcmp(suffix_8,"etappudu")) || (!strcmp(suffix_6,"eppudu"))) && !strcmp(pdgm,"appudu") && ( ans_root[0] == '\0')) {
derived_root = 1;                                
len = strlen(root);
if(!strcmp(suffix_8,"etappudu")) root[len-7] = '\0';
if(!strcmp(suffix_6,"eppudu")) root[len-5] = '\0';
get_derived_rt(root,e_suff_info_ar->suffix,sizeof_e_suff,sizeof(e_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0')                       
{                                      
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adv_e_appudu");
}
}
/*etaMwasepu case */
if(((!strcmp(suffix_8,"eMwasepu")) || (!strcmp(suffix_10,"etaMwasepu"))) && !strcmp(pdgm,"munupu") && ( ans_root[0] == '\0')) {
derived_root = 1;                                
len = strlen(root);
if(!strcmp(suffix_8,"eMwasepu")) root[len-7] = '\0';
else if(!strcmp(suffix_10,"etaMwasepu")) root[len-9] = '\0';
get_derived_rt(root,e_suff_info_ar->suffix,sizeof_e_suff,sizeof(e_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0')                       
{                                      
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_adv_e_appudu");
}
}
/* vAdu Cases */
if((!strcmp(suffix_4,"vAdu")) && !strcmp(pdgm,"vAdu") && ( ans_root[0] == '\0')) {
derived_root = 1;
get_derived_rt(root,adv_xi_ar->suffix,sizeof_adv_xi,sizeof(adv_xi_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_vAdu");
}
}
/* axi Cases */
if((!strcmp(suffix_3,"axi")) && !strcmp(pdgm,"axi") && ( ans_root[0] == '\0')) {
root[len-3] = 'x';
root[len-2] = 'i';
root[len-1] = '\0';
derived_root = 1;
get_derived_rt(root,adv_xi_ar->suffix,sizeof_adv_xi,sizeof(adv_xi_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_xi");
}
}
if((!strcmp(suffix_2,"xi")) && !strcmp(pdgm,"axi") && ( ans_root[0] == '\0')) {
derived_root = 1;
get_derived_rt(root,adv_xi_ar->suffix,sizeof_adv_xi,sizeof(adv_xi_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_xi");
}
}

if(DEBUG && derived_root)
{
printf("%s\n",ans_root);
printf("%d\n",derived_root);
}

}
