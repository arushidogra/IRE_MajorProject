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

extern int match_in_dict();
extern void match_in_hypothetical_dict();
extern int direct_ans_flag;
extern int DEBUG_NEW;
extern int INFLTNL;


void
verify_root(INFLTNL,guessed_root,pdgm,cat,offset,ans_table,ans_ar,j,DBM_FLAG,db_lex)
char guessed_root[SUFFWORDSIZE],pdgm[WORD_SIZE],cat[CATEGORYWORDSIZE];
int offset,*j;
struct lex_info ans_table[100];
struct ans_struct ans_ar[20];
int DBM_FLAG,INFLTNL;
#ifdef GNU
GDBM_FILE db_lex;
#else
DBM *db_lex;
#endif

{
int match1;
char ans_root[SUFFWORDSIZE];
char aux_verb[SUFFWORDSIZE];
aux_verb[0] = '\0';
match1 = 0;

if(INFLTNL)
match1 = match_in_dict(guessed_root,pdgm,cat,offset,ans_table,ans_ar,j);
if(!INFLTNL)
{
if(offset <= 902) { strcpy(cat,"verb");}
else if(offset > 902) { strcpy(cat,"noun");} 
match_in_hypothetical_dict(guessed_root,pdgm,cat,DBM_FLAG,db_lex,ans_root,aux_verb);
if(strcmp(ans_root,""))
{
strcpy(ans_ar[*j].root , "0_"); /* Always derived answer has least priority */
strcat(ans_ar[*j].root , ans_root);
ans_ar[*j].offset = offset;
strcat(ans_ar[*j].aux_verb,aux_verb); 
strcpy(ans_ar[*j].pdgm,pdgm); 
if(!INFLTNL) strcat(ans_ar[*j].pdgm,"_deri"); 
(*j)++;
if(DEBUG_NEW)
{
if(*j == DEBUG_NEW)
{
printf("Exiting from Verify root\n"); 
/* fflush(); */
exit(9); /*TEMP  AMBA */
}
}
}
}
}
