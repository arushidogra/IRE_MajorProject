#include <stdio.h>
#include <fcntl.h>
#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif



extern void *my_fatal();

struct lex_info
{
char root[100];
char pdgm[100];
};

main()
{
#ifdef GNU
GDBM_FILE db1;
#else
DBM *db1;
#endif

int i,st;
char key1[100];
char *key,*tag1;
datum lex_data,tag,tag2;
#ifdef GNU
db1 = gdbm_open("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/amba/amba/rajen/Malyalam/morph/test/lex",512,GDBM_READER,0666,my_fatal());
#else
db1 = dbm_open("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/amba/amba/rajen/Malyalam/morph/test/lex",O_RDONLY,0666);
#endif


for(;;){
printf("Enter the key to be searched\n");
scanf("%s",key1);
printf("%s\n",key1);
fflush(stdout);
tag.dptr = key1;
tag.dsize = strlen(key1);
#ifdef GNU
tag2 = gdbm_fetch(db1,tag);
#else
tag2 = dbm_fetch(db1,tag);
#endif

for(i=0;i<tag2.dsize;i++)
printf("%c",*((tag2.dptr)+i));
printf("\n");
}
dbm_close(db1);
}
