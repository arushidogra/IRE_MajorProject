#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct1.h"

extern int DEBUG;

extern int sizeof_num_suff;

extern struct suff_info num_suff_ar[];

extern void get_derived_rt();

void
derived_num_heuristics(root,pdgm,DBM_FLAG,db_lex,ans_root)
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
char suff[SUFFWORDSIZE];
char offset_aux_str[SUFFWORDSIZE];

len = strlen(root);
strcpy(tmp_root,root);

derived_root = 0;
ans_root[0] = '\0';

/*
required pdgm & heuristics from GUR
get_derived_rt(root,adj_ni_ar->suffix,sizeof_adj_ni,sizeof(adj_ni_ar[0]),strcmp,DBM_FLAG,db_lex,"noun",ans_root,offset_aux_str);
if(ans_root[0] != '\0') strcat(ans_root,num_vib);
*/

if(DEBUG && derived_root)
{
printf("%s\n",ans_root);
printf("%d\n",derived_root);
}

}
