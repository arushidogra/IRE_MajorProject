#include <string.h>
#include <stdio.h>
#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include <fcntl.h>
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct1.h"
extern char * my_blk_bsearch();

void chk_uword_dict(word,base,nel,width,compar,answer,DBM_FLAG,db)
char base[WORD_SIZE],word[WORD_SIZE];
int nel,width;
int (*compar)();
char answer[200];
int DBM_FLAG;
#ifdef GNU
GDBM_FILE db;
#else
DBM *db;
#endif

{
datum db_tag,db_out;
struct uword_dict *tag_out;
if(DBM_FLAG)
{
db_tag.dptr = word;
db_tag.dsize = strlen(word);
#ifdef GNU
db_out = gdbm_fetch(db,db_tag);
#else
db_out = dbm_fetch(db,db_tag);
#endif

if(db_out.dptr != '\0')
{
strncpy(answer,db_out.dptr,db_out.dsize);
answer[db_out.dsize] = '\0';
}
else answer[0]='\0';
}
else
{
tag_out = (struct uword_dict *)my_blk_bsearch(word,base,nel,width,compar);
if(tag_out != '\0')
strcpy(answer,tag_out->tl_word);
else answer[0]='\0';
}
}
