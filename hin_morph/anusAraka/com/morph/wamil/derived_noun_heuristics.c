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
extern int sizeof_adjl_ppl_suff;
extern struct suff_info adjl_ppl_suff_info_ar[];

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
char suffix_2[3],suffix_3[4],suffix_4[5],suffix_5[6],suffix_6[7],suffix_7[8],suffix_8[9];
struct lex_info ans_table[100];
char ans_ar[100][2000];

strcpy(tmp_root,root);
len = strlen(root);

if(len>8)strcpy(suffix_8 , root+len-8); else strcpy(suffix_8,"");
if(len>7)strcpy(suffix_7 , root+len-7); else strcpy(suffix_7,"");
if(len>6)strcpy(suffix_6 , root+len-6); else strcpy(suffix_6,"");
if(len>5)strcpy(suffix_5 , root+len-5); else strcpy(suffix_5,"");
if(len>4)strcpy(suffix_4 , root+len-4); else strcpy(suffix_4,"");
if(len>3)strcpy(suffix_3 , root+len-3); else strcpy(suffix_3,"");
if(len>2)strcpy(suffix_2 , root+len-2); else strcpy(suffix_2,"");

derived_root = 0;
ans_root[0] = '\0';
strcpy(root_bak,root);

if(!strcmp(suffix_5,"avanY") && !strcmp(pdgm,"avanY") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
get_derived_rt(root,adjl_ppl_suff_info_ar->suffix,sizeof_adjl_ppl_suff,sizeof(adjl_ppl_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_avanY");
}
}
if(!strcmp(suffix_4,"avar") && !strcmp(pdgm,"avar") && (ans_root[0] == '\0')) {
derived_root = 1;
len = strlen(root);
get_derived_rt(root,adjl_ppl_suff_info_ar->suffix,sizeof_adjl_ppl_suff,sizeof(adjl_ppl_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_avar");
}
}
if(!strcmp(suffix_8,"avarkalY") && !strcmp(pdgm,"avar") && (ans_root[0] == '\0')) {
strcpy(root,root_bak);
derived_root = 1;
len = strlen(root);
root[len-4] = '\0';
get_derived_rt(root,adjl_ppl_suff_info_ar->suffix,sizeof_adjl_ppl_suff,sizeof(adjl_ppl_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_avar");
}
}
else if(!strcmp(suffix_5,"avalY") && !strcmp(pdgm,"avalY") && (ans_root[0] == '\0')) {
strcpy(root,root_bak);
derived_root = 1;
len = strlen(root);
get_derived_rt(root,adjl_ppl_suff_info_ar->suffix,sizeof_adjl_ppl_suff,sizeof(adjl_ppl_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_avalY");
}
}
else if(!strcmp(suffix_3,"awu") && !strcmp(pdgm,"awu") && (ans_root[0] == '\0')) {
strcpy(root,root_bak);
derived_root = 1;
len = strlen(root);
get_derived_rt(root,adjl_ppl_suff_info_ar->suffix,sizeof_adjl_ppl_suff,sizeof(adjl_ppl_suff_info_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,aux_verb,offset_aux_str);
if(ans_root[0] != '\0') 
{
if(aux_verb[0] != '\0') { strcat(ans_root,"_"); strcat(ans_root,aux_verb);strcpy(aux_verb,"");}
strcat(ans_root,"_axu");
}
}

if(DEBUG && derived_root)
{
printf("%s\n",ans_root);
printf("%d\n",derived_root);
}

}
