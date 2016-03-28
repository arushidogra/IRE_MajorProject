WRD [A-Za-z_][A-Za-z_]*
PUNCT [?"']
OPT_SPACE [\t\n ]*
SPACE [\t\n ]+
%%
OUT_[^ \t\n]*_OUT 				{ printf("%s",yytext);}
{PUNCT}{OPT_SPACE}annaxi/{SPACE}	{hndl_annaxi(yytext);}
%%
#include <stdio.h>
#include <strings.h>
#include <fcntl.h>

/*Rule:
if annaxi is preceded by a punctuation mark, 
then annaxi -> Verb
else annaxi -> Noun
*/
                                

hndl_annaxi(word)
char word[100];
{
int i;
i=0;
if(!isalpha(word[i])) { printf("%c",word[i]);i++;}
printf("%cOUT_kahA_{WA|hE}_OUT",word[i]);
}

main(argc,argv)
int argc;
char *argv[];
{
yylex();
}

