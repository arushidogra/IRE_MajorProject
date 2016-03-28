#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
struct lex_info
{
char word[LEXWORDSIZE];
char pdgm[WORD_SIZE];
char cat[CATEGORYWORDSIZE];
char priority;
};
struct suff_info
{
char suffix[SUFFWORDSIZE];
char add[WORD_SIZE];
char pdgm[WORD_SIZE];
char category[CATEGORYWORDSIZE];
int offset;
};
struct order_info
{
char category[WORD_SIZE];
char feature[MAX_NO_OF_FEATURES][WORD_SIZE];
};
struct suff_add_info
{
char suff[SUFFWORDSIZE];
char add[WORD_SIZE];
int ptr;
int no_of_entries;
};
