#include <stdio.h>
#include <ctype.h>
#define MED_STR 100
void getlines(s_ptr)
char *s_ptr;
{
/*   Collects the string from the stdin, into the string s_ptr */
	int c;
	while((c = getchar()) != '\n' && c != EOF) *s_ptr++ = c;
	*s_ptr = '\0';
}
void fgetline(s_ptr,fp)
char *s_ptr;
FILE *fp;
{
/*   Collects the string from the FILE fp, into the string s_ptr */
	char c;
	while((c = getc(fp)) != '\n' && !feof(fp)) *s_ptr++ = c;
	*s_ptr = '\0';
}
void getnumber(s_ptr)
int *s_ptr;
{
/*   Collects the number from the stdin, into s_ptr */
	int c,i = 0;
	char temp[MED_STR];
	while((c = getchar()) != '\n' && c != EOF) *(temp + i++) = c;
	*(temp + i) = '\0';
	sscanf(temp,"%d",s_ptr);
}
char sb(fp)
FILE *fp;
{
/* skip white space */
	char c;
	while ((c = getc(fp)) == ' ' || c == '\n' || c == '\t');
	return(c);
}
void chkint(fp)
FILE *fp;
{
/* checks to see if the next char on the stream fp is an integer */
	char ctyp;
	if (isdigit(ctyp = sb(fp)))
		ungetc(ctyp,fp);
}


/*
main()
{
char s1[100];
FILE *fp;
int lin=0;
printf("?\n");
fp = fopen("getline.c","r");
while(!feof(fp)) {
fgetline(s1,fp);
printf("%d %s\n",lin++,s1);
}
printf("%d\n",lin-1);
fclose(fp);
}
*/
