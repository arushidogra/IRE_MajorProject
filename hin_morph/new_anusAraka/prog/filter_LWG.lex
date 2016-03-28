%%
#_LWG_¤[^#\n\t]*_LWG_# { yytext[yyleng-6] = '\0';
		   printf("%s\n",yytext+7);}
#LWG_¤[^#\n\t]*_LWG# { yytext[yyleng-5] = '\0';
		   printf("%s\n",yytext+6);}
#MO_¤[^#\n\t]*_MO# { yytext[yyleng-4] = '\0';
		   printf("%s\n",yytext+5);}
FRZ_MO_¤#[^#\n\t]*_MO_FRZ { yytext[yyleng-7] = '\0';
		   printf("%s\n",yytext+8);}

#_LWG_[^#\n\t]*_LWG_# { yytext[yyleng-6] = '\0';
		   printf("%s\n",yytext+6);}
#LWG_[^#\n\t]*_LWG# { yytext[yyleng-5] = '\0';
		   printf("%s\n",yytext+5);}
#OUT_[^#\n\t]*_OUT# { yytext[yyleng-5] = '\0';
		   printf("%s\n",yytext+5);}
#MO_[^#\n\t]*_MO# { yytext[yyleng-4] = '\0';
		   printf("%s\n",yytext+4);}
#[^#\n\t]*# { yytext[yyleng-1] = '\0';
		   printf("%s\n",yytext+1);}
FRZ_MO_#[^#\n\t]*_MO_FRZ { yytext[yyleng-7] = '\0';
		   printf("%s\n",yytext+7);}
SUF_[^# \n\t]*_SUF { yytext[yyleng-4] = '\0';
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
/* Deleted, for maroVkti in Telugu
#OUT_¤[^#\n\t]*_OUT# { yytext[yyleng-5] = '\0';
		   printf("%s\n",yytext+6);}*/
