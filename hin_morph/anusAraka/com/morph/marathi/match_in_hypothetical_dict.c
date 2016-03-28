#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"

extern void derived_noun_heuristics();
extern void derived_verb_heuristics();
extern int comp_verbs();
extern int DEBUG;
extern int DEBUG_NEW;

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
ans_root[0] = '\0';
if(!strcmp(cat,"noun"))
{
derived_noun_heuristics(root,pdgm,DBM_FLAG,db_lex,ans_root,aux_verb);
}
if(!strcmp(cat,"verb"))
{
derived_verb_heuristics(root,pdgm,DBM_FLAG,db_lex,ans_root,aux_verb);
}
}

