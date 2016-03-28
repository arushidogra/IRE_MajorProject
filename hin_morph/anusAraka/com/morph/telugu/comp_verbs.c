#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include <string.h>
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct1.h"

extern struct suff_info aux_info_ar[];
extern int sizeof_aux;
extern void comp_verb_heuristics();
extern void get_derived_rt();
extern int DEBUG;

int 
comp_verbs(root,pdgm,DBM_FLAG,db_lex,ans_root,aux_verb)
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
char aux_verbs[SUFFWORDSIZE];
char tmp_aux_verbs[SUFFWORDSIZE];
char cur_aux_str[SUFFWORDSIZE];
aux_verbs[0] = '\0';
tmp_aux_verbs[0] = '\0';
ans_root[0] = '\0';
comp_verb_heuristics(root,pdgm,tmp_aux_verbs);
if(strcmp(tmp_aux_verbs,""))
{
get_derived_rt(root,aux_info_ar->suffix,sizeof_aux,sizeof(aux_info_ar[0]),strcmp,DBM_FLAG,db_lex,"verb",ans_root,aux_verbs,cur_aux_str);
if(strcmp(ans_root,"")) 
{
if(!strcmp(cur_aux_str,tmp_aux_verbs))
{
if(strcmp(aux_verb,""))
{
strcat(aux_verbs,"_");
strcat(aux_verbs,aux_verb);
strcpy(aux_verb,aux_verbs);
}
else strcpy(aux_verb,aux_verbs);
}
else {
strcpy(ans_root,"");/*reinitialise  ans_root*/
if(DEBUG)
{
printf("heuristics string %s does not match with guessed_string %s \n",tmp_aux_verbs,aux_verb);
printf("aux_verb = %s\n aux_verbs = %s\n",aux_verb,aux_verbs);
}
return 0;
}
}
return 1;
}
return 0;
}
