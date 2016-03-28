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

getword(word,delimitor)
char *word;
char delimitor;
{
        char c,i = 0;

        c=getchar();
        while ((c != EOF) && ( c != delimitor) && ( c!='\n'))
         {
           if(c!=' ') word[i++] = c; /* ignore blanks */
           c = getchar();
         }
        word[i] = '\0';
}
