#include <stdio.h>
#include <string.h>
extern int REPLACE_NEW_LINE;
extern char DELIMITER;
extern int IGNORE_NULL_CHARACTER;

get_snt(s_ptr)
char *s_ptr;
{
int c;
while((c=getchar())!= DELIMITER && c != EOF )
{
 if (REPLACE_NEW_LINE)
 {
 if(c=='\n') *s_ptr++ =' ';
 else *s_ptr++ = c;
 }
 else if ((IGNORE_NULL_CHARACTER)&&(c!='\0')) *s_ptr++ =c;
 else *s_ptr++ = c;
}
 if(c != EOF) *s_ptr++ = c;
*s_ptr++ ='\n';
*s_ptr = '\0';
return;
}
