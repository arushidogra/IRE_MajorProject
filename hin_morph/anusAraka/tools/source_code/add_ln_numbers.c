#include <stdio.h>
#include <string.h>

get_snt(s_ptr)
char *s_ptr;
{
char c;
c = getchar();
while((c!='.') && (c!= '?') && ( c!= '!') && (c != EOF))
{
*s_ptr++ = c;
c = getchar();
}
if(c != EOF)
{ *s_ptr++ = c;
 c = getchar();
if(c=='\n') *s_ptr++ = c;
else ungetc(c,stdin);
}
*s_ptr = '\0';
return;
}


main(argc,argv)
int argc;
char *argv[];
{
char c,line[500000];
int count;
count = 1;
while((c=getchar()) !=EOF)
{
ungetc(c,stdin);
get_snt(line);
printf("<%d> %s",count,line);
count++;
}
}
