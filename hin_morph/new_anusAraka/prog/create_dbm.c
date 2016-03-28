/*
Note : Before running this program,
first create two files with 0 bytes by names lex.dir & lex.pag 
in the desired directory
*/
#include <stdio.h>
#include <fcntl.h>
#include <ctype.h>
#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

void *my_fatal()
{
};

main(int argc,char *argv[])
{
GDBM_FILE db1;

int i,st;
char c,key[300],value[500];
datum tag,tag2;

db1 = gdbm_open(argv[1],512,GDBM_WRCREAT,0666,my_fatal());
if(db1 == NULL) {
printf("Error in creating story_wrds \n Exiting ..\n");
exit(1);
}
c = getchar();
while(c != EOF) {
i=0;
while((c != EOF) && (c != ',')) {key[i++] = c; c= getchar();}
key[i] = '\0';

if(c == EOF) { printf ("Error in Data file.\n Exiting ...\n");}
i=0;
c=getchar();
while((c != EOF) && (c != '\n')) {value[i++] = c; c= getchar();}
value[i] = '\0';
tag.dptr=key;
tag.dsize = strlen(key);
tag2.dptr=value;
tag2.dsize = strlen(value);
st = gdbm_store(db1,tag,tag2,GDBM_INSERT);
c=getchar();
}
gdbm_close(db1);
exit(0);
}
