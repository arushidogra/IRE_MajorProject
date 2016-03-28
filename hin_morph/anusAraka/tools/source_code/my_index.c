#include <stdio.h>
#include "string.h"
char *index(str,ch)
char *str,ch;
{
return(strchr(str,ch));
}
