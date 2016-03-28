#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *
my_strstr(s1,s2)
char *s1,*s2;
{
char *ans;
ans = index(s1,*s2);
if (ans == '\0') return 0;
else if (strncmp(s2,ans,(int)strlen(s2)) == 0) return ans;
else return(my_strstr((ans+1),s2));
}

