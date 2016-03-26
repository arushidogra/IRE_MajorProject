/*
 *
 * FUNCTION getfileword(fp,word)
 * last modified on 25 May 1991.
 *
 * This function fetches the next word from the current line
 * of the specified file. It returns the length of the word if aword is read;
 * otherwise returns 0 for '\n'(previous word read was the last word in the 
 * line), or returns -1 for '\0'(previous word read was the last word in input).
 *
 * Open the file before calling this function
 * 
 * All valid C identifiers are returned as words.
 * Initial non-letters are ignored. That is, 12abc45efg77 is read as abc45efg77.
 * All non-letters and non-digits(except for "_")  are treated as 
 * field seperators, e.g. west@point23 will be read as west and point23.
 * 
 */

#include <stdio.h>
#include <ctype.h>

int getfileword(fp,word)
FILE *fp;
char *word;
{
	int i = 0;
        int c;

	word[0] = '\0';
	if ((c = getc(fp)) == EOF)
		return (-1); /* first char EOF or ERROR in file read */
	if (c == '\n' )
	{
		word[0] = '\n';
		word[1] = '\0';
		return (0);  /* first char read is newline */ 
	}
/*
	while ((c != EOF) && (!(isalpha(c))) && (c != '\n') )
*/
	while ((c==' ') ||(c=='\t'))
		c = getc(fp);    /* skipping all  spaces, */
	if (c == EOF)
		return (-1);
	word[i++] = c;
	if (c == '\n' )
	{
		word[1] = '\0';
		return (0);  /* only newline found */
	}
	while (isalpha(c =getc(fp)) || isdigit(c) || (c == '_') || (c == '-'))
		word[i++] = c;
	if (c != EOF)
		ungetc(c, fp); /* EOF cannot be ungetted */
	word[i] = '\0';
	return (i); /* word found */
}
