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
extern int sizeof_wunna_suff;
extern int sizeof_ani_suff;
extern int sizeof_ina_suff;
extern int sizeof_e_suff;

extern struct suff_info adaM_suff_info_ar[];
extern struct suff_info wunna_suff_info_ar[];
extern struct suff_info ani_suff_info_ar[];
extern struct suff_info ina_suff_info_ar[];
extern struct suff_info e_suff_info_ar[];

derived_roots_heuristics(root,pdgm,DBM_FLAG,db_lex,ans_root)
char root[SUFFWORDSIZE],pdgm[WORD_SIZE];
int DBM_FLAG;
#ifdef GNU
GDBM_FILE db_lex;
#else
DBM *db_lex;
#endif

char ans_root[SUFFWORDSIZE];
{
int len,derived_root;
char tmp_root[SUFFWORDSIZE];
char suffix_2[3],suffix_3[4],suffix_4[5],suffix_5[6],suffix_6[7],suffix_7[8],suffix_8[9],suffix_9[10];

strcpy(tmp_root,root);
len = strlen(root);

if(len>9) strcpy(suffix_9 , root+len-9); else strcpy(suffix_9,"");
if(len>9) strcpy(suffix_8 , root+len-8); else strcpy(suffix_8,"");
if(len>9) strcpy(suffix_7 , root+len-7); else strcpy(suffix_7,"");
if(len>9) strcpy(suffix_6 , root+len-6); else strcpy(suffix_6,"");
if(len>9) strcpy(suffix_5 , root+len-5); else strcpy(suffix_5,"");
if(len>9) strcpy(suffix_4 , root+len-4); else strcpy(suffix_4,"");
if(len>9) strcpy(suffix_3 , root+len-3); else strcpy(suffix_3,"");
if(len>9) strcpy(suffix_2 , root+len-2); else strcpy(suffix_2,"");

derived_root = 0;
ans_root[0] = '\0';
/* iMcu case */

if(!strcmp(suffix_4,"iMcu") && !strcmp(pdgm,"cUpiMcu")) {
derived_root = 1;
strncpy(ans_root,root,len-4);
ans_root[len-4] = '\0';
if(ans_root[0] != '\0') strcat(ans_root,"?_iMcu");
strcpy(root,tmp_root);
}

/* wunna Cases */

else if((!strcmp(suffix_9,"wunnavAdu") || !strcmp(suffix_9,"cunnavAdu")) && !strcmp(pdgm,"vAdu")) {
derived_root = 1;
get_derived_rt(root,wunna_suff_info_ar->suffix,sizeof_wunna_suff,sizeof(wunna_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_fin_dupf_vAdu");
}
else if((!strcmp(suffix_9,"wunnavAru") || !strcmp(suffix_9,"cunnavAru")) && !strcmp(pdgm,"vAru")) {
derived_root = 1;
get_derived_rt(root,wunna_suff_info_ar->suffix,sizeof_wunna_suff,sizeof(wunna_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_fin_dupf_vAru");
}
else if((!strcmp(suffix_8,"wunnaaxi") || !strcmp(suffix_8,"cunnaaxi")) && !strcmp(pdgm,"axi")) {
derived_root = 1;
len = strlen(root);
root[len-3] = 'x';
root[len-2] = 'i';
root[len-1] = '\0';
get_derived_rt(root,wunna_suff_info_ar->suffix,sizeof_wunna_suff,sizeof(wunna_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_fin_dupf_axi");
strcpy(root,tmp_root);
}
else if((!strcmp(suffix_7,"wunnaxi") || !strcmp(suffix_7,"cunnaxi")) && !strcmp(pdgm,"axi")) {
derived_root = 1;
get_derived_rt(root,wunna_suff_info_ar->suffix,sizeof_wunna_suff,sizeof(wunna_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_fin_dupf_axi");
}

/* ani cases */

else if(!strcmp(suffix_6,"nivAdu") && !strcmp(pdgm,"vAdu")) {
derived_root = 1;
get_derived_rt(root,ani_suff_info_ar->suffix,sizeof_ani_suff,sizeof(ani_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_fin_negp_vAdu");
}
else if(!strcmp(suffix_6,"nivAru") && !strcmp(pdgm,"vAru")) {
derived_root = 1;
get_derived_rt(root,ani_suff_info_ar->suffix,sizeof_ani_suff,sizeof(ani_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_fin_negp_vAru");
}
else if(!strcmp(suffix_4,"naxi") && !strcmp(pdgm,"axi")) {
derived_root = 1;
len = strlen(root);
root[len-3] = 'x';
root[len-2] = 'i';
root[len-1] = '\0';
get_derived_rt(root,ani_suff_info_ar->suffix,sizeof_ani_suff,sizeof(ani_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_fin_negp_axi");
strcpy(root,tmp_root);
}
else if(!strcmp(suffix_4,"naxi") && !strcmp(pdgm,"axi")) {
derived_root = 1;
get_derived_rt(root,ani_suff_info_ar->suffix,sizeof_ani_suff,sizeof(ani_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_fin_negp_axi");
}

/* ina cases */

else if((!strcmp(suffix_7,"inavAdu") || !strcmp(suffix_7,"nnavAdu")) && !strcmp(pdgm,"vAdu")) {
derived_root = 1;
get_derived_rt(root,ina_suff_info_ar->suffix,sizeof_ina_suff,sizeof(ina_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_fin_ptp_vAdu");
}
else if((!strcmp(suffix_7,"inavAru") || !strcmp(suffix_7,"nnavAru")) && !strcmp(pdgm,"vAru")) {
derived_root = 1;
get_derived_rt(root,ina_suff_info_ar->suffix,sizeof_ina_suff,sizeof(ina_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_fin_ptp_vAru");
}
else if((!strcmp(suffix_6,"inaaxi") || !strcmp(suffix_5,"nnaxi") ) && !strcmp(pdgm,"axi")) {
derived_root = 1;
len = strlen(root);
root[len-3] = 'x';
root[len-2] = 'i';
root[len-1] = '\0';
get_derived_rt(root,ina_suff_info_ar->suffix,sizeof_ina_suff,sizeof(ina_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_fin_ptp_axi");
strcpy(root,tmp_root);
}
else if(!strcmp(suffix_5,"inaxi") && !strcmp(pdgm,"axi")) {
derived_root = 1;
get_derived_rt(root,ina_suff_info_ar->suffix,sizeof_ina_suff,sizeof(ina_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_fin_ptp_axi");
}

/* e cases */

else if((!strcmp(suffix_5,"uvAdu") || !strcmp(suffix_5,"evAdu")) && !strcmp(pdgm,"vAdu")) {
derived_root = 1;
get_derived_rt(root,e_suff_info_ar->suffix,sizeof_e_suff,sizeof(e_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_fin_subj_vAdu");
}
else if((!strcmp(suffix_5,"uvAru") || !strcmp(suffix_5,"evAru")) && !strcmp(pdgm,"vAru")) {
derived_root = 1;
get_derived_rt(root,e_suff_info_ar->suffix,sizeof_e_suff,sizeof(e_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_fin_subj_vAru");
}
else if((!strcmp(suffix_5,"unaxi") || !strcmp(suffix_4,"eaxi")) && !strcmp(pdgm,"axi")) {
derived_root = 1;
len = strlen(root);
root[len-3] = 'x';
root[len-2] = 'i';
root[len-1] = '\0';
get_derived_rt(root,e_suff_info_ar->suffix,sizeof_e_suff,sizeof(e_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_fin_subj_axi");
strcpy(root,tmp_root);
}
else if(!strcmp(suffix_3,"exi") && !strcmp(pdgm,"axi")) {
derived_root = 1;
get_derived_rt(root,e_suff_info_ar->suffix,sizeof_e_suff,sizeof(e_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_fin_subj_axi");
}

/*adaM cases */

else if((!strcmp(suffix_4,"adaM") || (!strcmp(suffix_4,"ataM")) || !strcmp(suffix_5,"atamu") || !strcmp(suffix_5,"adamu") || !strcmp(suffix_4,"otaM") || !strcmp(suffix_4,"odaM") || !strcmp(suffix_5 ,"otamu") || !strcmp(suffix_5,"odamu") || !strcmp(suffix_4,"ddaM") || !strcmp(suffix_4,"ttaM")) && !strcmp(pdgm,"puswakaM")) {
derived_root = 1;
get_derived_rt(root,adaM_suff_info_ar->suffix,sizeof_adaM_suff,sizeof(adaM_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_adaM");
}
else if(!strcmp(suffix_3,"uta") && !strcmp(pdgm,"kota")) {
derived_root = 1;
get_derived_rt(root,adaM_suff_info_ar->suffix,sizeof_adaM_suff,sizeof(adaM_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,ans_root);
if(ans_root[0] != '\0') strcat(ans_root,"_adaM");
}


if(DEBUG && derived_root)
{
printf("%s\n",ans_root);
printf("%d\n",derived_root);
}

}
