#include <stdio.h>
#include <string.h>
#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct1.h"

verify_root(INFLTNL,guessed_root,pdgm,cat,offset,ans_table,ans_ar,j,DBM_FLAG,db)
int INFLTNL;
char guessed_root[SUFFWORDSIZE],pdgm[WORD_SIZE],cat[CATEGORYWORDSIZE];
int offset,*j;
struct lex_info ans_table[100];
struct ans_struct ans_ar[20];
int DBM_FLAG; 
#ifdef GNU
GDBM_FILE db;
#else
DBM *db;
#endif

{
int match1;
match1 = match_in_dict(guessed_root,pdgm,cat,offset,ans_table,ans_ar,j);
if(!match1)
test_hypothetical_dict(guessed_root,pdgm,cat,offset,ans_ar,j,DBM_FLAG,db);
}
test_hypothetical_dict(root,pdgm,cat,suff_offset,ans_ar,j,DBM_FLAG,db)
char root[SUFFWORDSIZE],pdgm[WORD_SIZE],cat[CATEGORYWORDSIZE];
int suff_offset,*j;
struct ans_struct ans_ar[20];
int DBM_FLAG;
#ifdef GNU
GDBM_FILE db;
#else
DBM *db;
#endif

{
}
