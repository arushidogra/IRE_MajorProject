#include "/1d1/mt/com/morph/prog/headers/defn.h"
print_deafult_ans(word)
char word[Morphsize];
{
int offset;
/*
offset = 1;  This is the offset from feature_value.c file corresponding to 
singular direct case */
if(!strcmp(word,"Gara") || !strcmp(word,"ladakA") || !strcmp(word,"kavi") || !strcmp(word,"Sawru") || !strcmp(word,"AlU") || !strcmp(word,"kuAz") || !strcmp(word,"redio")) offset = 1;
else offset = 5;
resufun(word,offset);
}
