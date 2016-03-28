#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <ndbm.h>
DBM *db_story_wrds;

main(argc,argv)
int argc;
char *argv[];
{
datum db_tag,db_out;
char fname[100],word[100],ans_str[1000];

ans_str[0] = '\0';

if(argc<2) 
{
  printf("Usage srch.out <dbm_file> <word>\n");
  exit(1);
}

strcpy(fname,argv[1]);
strcpy(word,argv[2]);


db_story_wrds = dbm_open(fname,O_RDONLY,0666);
db_tag.dptr = word;
db_tag.dsize = strlen(word);
db_out = dbm_fetch(db_story_wrds,db_tag);
if(db_out.dptr != '\0')
{
strncpy(ans_str,db_out.dptr,db_out.dsize);
ans_str[db_out.dsize]='\0';
}
printf("%s",ans_str);
}
