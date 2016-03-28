#include <stdio.h>
#include <string.h>

extern get_snt();

main(argc,argv)
int argc;
char *argv[];
{
char c,line[500000];
while((c=getchar()) !=EOF)
{
ungetc(c,stdin);
get_sentence(line);
/*
printf("%s\n",line);
*/
printf("%s",line);
}
}
