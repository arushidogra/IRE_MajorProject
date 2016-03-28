#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"

extern void derived_noun_heuristics();
extern int DEBUG_NEW;

match_in_hypothetical_dict(root,pdgm,cat,DBM_FLAG,db_lex,ans_root,aux_verb)
char root[SUFFWORDSIZE],pdgm[WORD_SIZE],cat[CATEGORYWORDSIZE];
int DBM_FLAG;
#ifdef GNU
GDBM_FILE db_lex;
#else
DBM *db_lex;
#endif

char ans_root[SUFFWORDSIZE];
char aux_verb[SUFFWORDSIZE];
{
char aux_v[SUFFWORDSIZE];
ans_root[0] = '\0';
aux_verb[0] = '\0';
aux_v[0] = '\0';
if(!strcmp(cat,"noun")){
derived_noun_heuristics(root,pdgm,DBM_FLAG,db_lex,ans_root,aux_verb);
}
/*
if(DEBUG_NEW == 2) 
{
if(ans_root[0] != '\0') { 
printf("derived noun root = %s\n",ans_root);
}
}
else if(DEBUG_NEW) DEBUG_NEW++;
*/
}
