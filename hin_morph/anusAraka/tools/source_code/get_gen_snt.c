#include <stdio.h>
#include <string.h>

get_snt(s_ptr)
char *s_ptr;
{
char c;
c = getchar();
while((c!='.') && (c!= '?') && ( c!= '!') && (c != EOF))
{
 if(c=='\n') *s_ptr++ =' ';
 else *s_ptr++ = c;
c = getchar();
}
if(c != EOF) *s_ptr++ = c;
*s_ptr = '\0';
return;
}
