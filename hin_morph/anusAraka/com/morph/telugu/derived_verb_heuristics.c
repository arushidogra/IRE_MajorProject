#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct1.h"

extern void dict_lookup();
extern int DEBUG;
void my_grep();

extern struct lex_info lex_ar[];
extern int sizeof_lex;


void
derived_verb_heuristics(root,pdgm,DBM_FLAG,db,answer)
char root[SUFFWORDSIZE],pdgm[WORD_SIZE];
int DBM_FLAG;
#ifdef GNU
GDBM_FILE db;
#else
DBM *db;
#endif

char answer[SUFFWORDSIZE];
{
int len,derived_root;
char suffix_2[3],suffix_3[4],suffix_4[5],suffix_5[6],suffix_6[7];
char ans_root[SUFFWORDSIZE];

len = strlen(root);
if(len>6) strcpy(suffix_6 , root+len-6); else strcpy(suffix_6,"");
if(len>5) strcpy(suffix_5 , root+len-5); else strcpy(suffix_5,"");
if(len>4) strcpy(suffix_4 , root+len-4); else strcpy(suffix_4,"");
if(len>3) strcpy(suffix_3 , root+len-3); else strcpy(suffix_3,"");
if(len>2) strcpy(suffix_2 , root+len-2); else strcpy(suffix_2,"");

derived_root = 0;
ans_root[0] = '\0';
answer[0] = '\0';

if(!strcmp(suffix_4,"iMcu") && !strcmp(pdgm,"cUpiMcu")) {
derived_root = 1;
strncpy(ans_root,root,len-4);
ans_root[len-4] = '\0';
if(ans_root[0] != '\0') 
{
my_grep(ans_root,DBM_FLAG,db,answer);
if(answer[0] != '\0') strcat(answer,"?_iMcu");
}
}

if(!strcmp(suffix_4,"padu") && !strcmp(pdgm,"padu")) {
derived_root = 1;
strncpy(ans_root,root,len-4);
ans_root[len-4] = '\0';
if(ans_root[0] != '\0') 
{
my_grep(ans_root,DBM_FLAG,db,answer);
if(answer[0] != '\0') strcat(answer,"?_padu");
}
}
if(!strcmp(suffix_4,"avvu") && !strcmp(pdgm,"avvu")) {
derived_root = 1;
strncpy(ans_root,root,len-4);
ans_root[len-4] = '\0';
if(ans_root[0] != '\0') 
{
my_grep(ans_root,DBM_FLAG,db,answer);
if(answer[0] != '\0') strcat(answer,"?_avvu");
}
}
if(!strcmp(suffix_6,"ceVyyi") && !strcmp(pdgm,"ceVyyi")) {
derived_root = 1;
strncpy(ans_root,root,len-6);
ans_root[len-6] = '\0';
if(ans_root[0] != '\0') 
{
my_grep(ans_root,DBM_FLAG,db,answer);
if(answer[0] != '\0') strcat(answer,"?_ceVyyi");
}
}
if(!strcmp(suffix_6,"veVyyi") && !strcmp(pdgm,"ceVyyi")) {
derived_root = 1;
strncpy(ans_root,root,len-6);
ans_root[len-6] = '\0';
if(ans_root[0] != '\0') 
{
my_grep(ans_root,DBM_FLAG,db,answer);
if(answer[0] != '\0') strcat(answer,"?_veVyyi");
}
}
if(!strcmp(suffix_6,"paracu") && !strcmp(pdgm,"pannu")) {
derived_root = 1;
strncpy(ans_root,root,len-6);
ans_root[len-6] = '\0';
if(ans_root[0] != '\0') 
{
my_grep(ans_root,DBM_FLAG,db,answer);
if(answer[0] != '\0') strcat(answer,"?_paracu");
}
}
if(!strcmp(suffix_4,"lAdu") && !strcmp(pdgm,"Adu")) {
derived_root = 1;
strncpy(ans_root,root,len-4);
ans_root[len-4] = '\0';
if(ans_root[0] != '\0') 
{
my_grep(ans_root,DBM_FLAG,db,answer);
if(answer[0] != '\0') strcat(answer,"?_lAdu");
}
}
if(!strcmp(suffix_6,"peVttu") && !strcmp(pdgm,"peVttu")) {
derived_root = 1;
strncpy(ans_root,root,len-6);
ans_root[len-6] = '\0';
if(ans_root[0] != '\0') 
{
my_grep(ans_root,DBM_FLAG,db,answer);
if(answer[0] != '\0') strcat(answer,"?_peVttu");
}
}

if(DEBUG && derived_root)
{
printf("%s\n",ans_root);
printf("%d\n",derived_root);
}
}
void 
my_grep(ans_root,DBM_FLAG,db,answer)
char ans_root[SUFFWORDSIZE],answer[SUFFWORDSIZE];
int DBM_FLAG;
#ifdef GNU
GDBM_FILE db;
#else
DBM *db;
#endif

{
char tmp[SUFFWORDSIZE];
int i,FLAG;
char ans_ar[100][2000];
strcpy(answer,"");
strcpy(tmp,ans_root);
FLAG = 0;
for(i=0;((i<5) && (!FLAG));i++)
{
strcpy(ans_root,tmp);
if(i==1) {strcat(ans_root,"u");}
else if(i==2) {strcat(ans_root,"i");}
else if(i==3) {strcat(ans_root,"a");}
else if(i==4) {strcat(ans_root,"eV");}
dict_lookup(ans_root,DBM_FLAG,db,lex_ar->word,sizeof_lex,sizeof(lex_ar[0]),strcmp,ans_ar);
if(ans_ar[0][0] != '\0') {
/*
printf("answer = %s\n",ans_ar[0]);
*/
strcpy(answer,ans_ar[0]);
FLAG = 1;
}
}
/*
printf("answer = %s\n",answer);
*/
}
