#include <string.h>
#include <stdio.h>
#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif


extern void *my_fatal();

#include <fcntl.h>

struct lex_info
{
char word[35];
char pdgm[60];
char cat[20];
};
#include "lex.c"

main(argc,argv)
int argc;
char *argv[];
{
#ifdef GNU
GDBM_FILE db;
#else
DBM *db;
#endif

char word[20],ans_ar[100][200];
int i,DBM_FLAG;
struct lex_info *tag;

DBM_FLAG = 0;
if(argc >1)
{
if(argv[1][0] == 'D') DBM_FLAG = 1;
}
printf("Enter the word\n");
scanf("%s",word);
printf("word = %s\n",word);
if(DBM_FLAG)
{
#ifdef GNU
db = gdbm_open("j",512,GDBM_READER,0666,my_fatal());
#else
db = dbm_open("j",O_RDONLY,0666);
#endif

}
table_lookup(word,DBM_FLAG,db,lex_ar->word,sizeof_lex,sizeof(lex_ar[0]),strcmp,ans_ar);
i=0;
while(ans_ar[i][0]!='\0')
{
tag = (struct lex_info *) ans_ar[i];
printf("%d %s %s %s\n",i,tag->word,tag->pdgm,tag->cat);
i++;
}
}
