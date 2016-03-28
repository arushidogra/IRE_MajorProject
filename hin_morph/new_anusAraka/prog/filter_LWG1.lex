%%
#_LWG_¤[^#]*_LWG_# { yytext[yyleng-6] = '\0';
		   printf("%s\n",yytext+7);}
#LWG_¤[^#]*_LWG# { yytext[yyleng-5] = '\0';
		   printf("%s\n",yytext+6);}
#MO_¤[^#]*_MO# { yytext[yyleng-4] = '\0';
		   printf("%s\n",yytext+5);}
FRZ_MO_¤[^¤]*_MO_FRZ { yytext[yyleng-7] = '\0';
		   printf("%s\n",yytext+8);}

MO_¤[^#]*_MO { yytext[yyleng-3] = '\0';
		   printf("%s\n",yytext+4);}
#_LWG_[^#]*_LWG_# { yytext[yyleng-6] = '\0';
		   printf("%s\n",yytext+6);}
#LWG_[^#]*_LWG# { yytext[yyleng-5] = '\0';
		   printf("%s\n",yytext+5);}
#MO_[^#]*_MO# { yytext[yyleng-4] = '\0';
		   printf("%s\n",yytext+4);}
SUF_[^#]*_SUF { yytext[yyleng-4] = '\0';
		   printf("%s\n",yytext+4);}
.		{no_action();}
%%
#include <stdio.h>
#include <strings.h>
#include <fcntl.h>

no_action()
{
}

main(argc,argv)
int argc;
char *argv[];
{
yylex();
}
