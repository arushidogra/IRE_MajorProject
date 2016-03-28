#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"

extern void derived_noun_heuristics();
extern void derived_noun1_heuristics();
extern void derived_verb_heuristics();
extern int comp_verbs();
extern int DEBUG;
extern int DEBUG_NEW;
extern int KRIYAMULA;

void
match_in_hypothetical_dict(root,pdgm,cat,DBM_FLAG,db_lex,ans_root,aux_verb)
char root[SUFFWORDSIZE],pdgm[WORD_SIZE],cat[20];
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
aux_v[0] = '\0';
if(!strcmp(cat,"verb"))
{
if(comp_verbs(root,pdgm,DBM_FLAG,db_lex,ans_root,aux_v))
/*
if(ans_root != '\0')
*/
{
if(strcmp(aux_v,""))
{
if(strcmp(aux_verb,"")){
strcat(aux_v,"_");
strcat(aux_v,aux_verb);
strcpy(aux_verb,aux_v);
}
else 
strcpy(aux_verb,aux_v);
}
}
else if(KRIYAMULA)
derived_verb_heuristics(root,pdgm,DBM_FLAG,db_lex,ans_root,aux_verb);
/* Always given preference to comp verbs than other combination */
}
if(!strcmp(cat,"noun"))
{
aux_verb[0] = '\0';/* This line is added after getting the junk o/p for peVxavi */
chk_cons_ending_for_wrds(root,pdgm,DBM_FLAG,db_lex,ans_root,aux_verb);
if(ans_root[0] == '\0')
derived_noun_heuristics(root,pdgm,DBM_FLAG,db_lex,ans_root,aux_verb);
if(ans_root[0] == '\0')
derived_noun1_heuristics(root,pdgm,DBM_FLAG,db_lex,ans_root,aux_verb);
/*if(ans_root[0] == '\0')		amba temp stop */
derived_adj_noun_heuristics(root,pdgm,DBM_FLAG,db_lex,ans_root,aux_verb);
if(ans_root[0] == '\0')
derived_adv_noun_heuristics(root,pdgm,DBM_FLAG,db_lex,ans_root,aux_verb);
/*
if(ans_root[0] == '\0')
derived_num_heuristics(root,pdgm,DBM_FLAG,db_lex,ans_root,aux_verb);
*/
if(DEBUG_NEW == 2) 
{
if(ans_root[0] != '\0') { 
printf("derived noun root = %s\n",ans_root);
/*
exit(8);
*/
}
}
else if(DEBUG_NEW) DEBUG_NEW++;
}
}
