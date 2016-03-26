#include <stdio.h>
#include <string.h>

#include "struct.h"
#include "morph_logger.h"

extern char *program_name;
extern FILE *log_file;

#define FUNCTION "cp_to_struct_chk_pdgm()"


void
cp_to_struct_chk_pdgm(ch_ar,struct_ar,i,pdgm)
char ch_ar[100][2000];
struct lex_info struct_ar[100];
int *i;
char pdgm[60];
{
struct lex_info *tag;
int j;
PRINT_LOG(log_file, "checking for the word in PDGM\n");

j=0;
while(ch_ar[j][0] !='\0')
{
tag = ( struct lex_info *) ch_ar[j];
if(!strcmp(tag->pdgm,pdgm))
{
strcpy(struct_ar[*i].word,tag->word);
strcpy(struct_ar[*i].pdgm,tag->pdgm);
strcpy(struct_ar[*i].cat,tag->cat);
//struct_ar[*i].priority=tag->priority;
(*i)++;
}
j++;
}
}
