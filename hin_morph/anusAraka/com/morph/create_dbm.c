/*
Note : Before running this program,
first create two files with 0 bytes by names lex.dir & lex.pag 
in the desired directory
*/
#include <stdio.h>
#include <fcntl.h>
#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif



extern void *my_fatal();

#include "lex.c"
main()
{
#ifdef GNU
GDBM_FILE db1;
#else
DBM *db1;
#endif

int i,st,derr;
char *key;
datum lex_data,tag,tag2;

#ifdef GNU
db1 = gdbm_open("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/morph/test/lex",512,GDBM_READER,0666,my_fatal());
#else
db1 = dbm_open("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/morph/test/lex",O_WRONLY,0666);
#endif


for(i=0;i<SIZEOF_LEX;i++)
{
tag.dptr=lex_ar[i].word;
tag.dsize = strlen(lex_ar[i].word);
tag2.dptr=lex_ar[i].pdgm;
tag2.dsize = strlen(lex_ar[i].pdgm);
st = dbm_store(db1,tag,tag2,DBM_INSERT);
}
dbm_close(db1);
}
