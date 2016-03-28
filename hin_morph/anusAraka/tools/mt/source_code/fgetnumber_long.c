#include <stdio.h>
#include <ctype.h>
fgetnumber(fp,s_ptr,delimitor)
int *s_ptr;
FILE *fp;
char delimitor;
{
/*   Collects the number from the stdin, into s_ptr */
	int c,i = 0;
        char temp[10];
	c=getc(fp);
        while ((c != EOF) && ( c != delimitor) && ( c!='\n'))
         {
           if(isdigit(c)) *(temp+ i++) = c; /* ignore blanks
*/
           c = getc(fp);
         }

       *(temp+i) = '\0';
	sscanf(temp,"%ld",s_ptr);
}
