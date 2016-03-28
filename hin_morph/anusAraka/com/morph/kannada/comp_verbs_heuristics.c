#include <string.h>
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/kannada/comp_verb_data.c"

void
comp_verb_heuristics(root,pdgm,comp_verbs,new_root,pre_kqxaMwa)
char root[SUFFWORDSIZE];
char pdgm[WORD_SIZE];
char comp_verbs[20];
char new_root[SUFFWORDSIZE];
char pre_kqxaMwa[SUFFWORDSIZE];
{
int len,rt_len,i,flag;
char rt_suff[SUFFWORDSIZE];
char rt_bak[SUFFWORDSIZE];

comp_verbs[0] = '\0';
rt_len = strlen(root);
comp_verbs[0] = '\0';
strcpy(rt_bak,root);
flag = 0;
for(i=0;i<sizeof_comp_verb_rls&!flag;i++)
{
strcpy(root,rt_bak);
len = strlen(comp_verb_rls[i].suffix);
if(rt_len >= len) strcpy(rt_suff,root+rt_len-len);
else strcpy(rt_suff,"");
if(!strcmp(rt_suff,comp_verb_rls[i].suffix) &&
!strcmp(pdgm,comp_verb_rls[i].pdgm))
{
strcpy(comp_verbs,comp_verb_rls[i].aux);
strncpy(new_root,root,rt_len-len);
new_root[rt_len-len] = '\0';
strcat(new_root,comp_verb_rls[i].add);
strcpy(pre_kqxaMwa,comp_verb_rls[i].nf_tam);
flag = 1;
}
}
}
