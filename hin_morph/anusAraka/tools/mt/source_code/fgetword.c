/*
 *
 * FUNCTION getfileword(fp,word)
 *
 * This function fetches the next word from the current line
 * of the specified file. It returns the length of the word if aword is read;
 * otherwise returns 0 for '\n'(previous word read was the last word in the 
 * line), or returns -1 for '\0'(previous word read was the last word in input).
 *
 * Open the file before calling this function
 */

#include <stdio.h>
#include <ctype.h>

fgetword(fp,word,delimitor)
FILE *fp;
char *word;
char delimitor;
{
	int c;
        int i = 0;

        c=getc(fp);
	while ((c != EOF) && ( c != delimitor) && ( c!='\n'))
         {
           if(c!=' ') word[i++] = c; /* ignore blanks */
	   c = getc(fp);    
	 }
	word[i] = '\0';
}

/*
main()
{
FILE *fp;
char word[100];
if((fp=fopen("jnk","r"))==NULL)
    {
    printf("Error in jnk opening\n");
    exit(0);
    }

fgetword(fp,word,',');
printf("%s\n",word);
fgetword(fp,word,',');
printf("%s\n",word);
}
*/
