WRD [A-Za-z][A-Za-z']*
%%
OUT_[^ 	\+\n]*_OUT { printf("%s",yytext);}
FRZ_[^ 	\+\n]*_FRZ { printf("%s",yytext);}
FRZ_MO_¤#[^#]*_MO_FRZ { printf("%s",yytext);}
MO_[^#]*_MO { printf("%s",yytext);}
#_LWG_¤[^#]*_LWG_# { yytext[yyleng-6] = '\0';srch_dbm(yytext+7);}
#LWG_¤[^#]*_LWG# { yytext[yyleng-5] = '\0';srch_dbm(yytext+6);}
#OUT_¤[^#]*_OUT# { yytext[yyleng-5] = '\0';srch_dbm(yytext+6);}
#LWG_[^#]*_LWG# { yytext[yyleng-5] = '\0';srch_dbm(yytext+5);}
#MO_¤[^#]*_MO# { yytext[yyleng-4] = '\0';srch_dbm(yytext+5);}
#MO_[^#]*_MO# { yytext[yyleng-4] = '\0';srch_dbm(yytext+4);}
#¤[^#]*# { yytext[yyleng-1] = '\0';srch_dbm(yytext+2);}
#[^¤#]*# { yytext[yyleng-1] = '\0';srch_dbm(yytext+1);}
#[^#]*# { yytext[yyleng-1] = '\0';srch_dbm(yytext+1);}
@[^ \n]*/[ 	\n] { printf("%s",yytext);}
%%
#include <stdio.h>
#include <strings.h>
#include <fcntl.h>
#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif



#ifdef GNU
void *my_fatal()
{
}
#endif


#ifdef GNU
GDBM_FILE db_story_wrds;
#else
DBM *db_story_wrds;
#endif


srch_dbm(word)
char word[100];
{
char ans_str[1000];
datum db_tag,db_out;

strcpy(ans_str,word);
db_tag.dptr = word;
db_tag.dsize = strlen(word);
#ifdef GNU
db_out = gdbm_fetch(db_story_wrds,db_tag);
#else
db_out = dbm_fetch(db_story_wrds,db_tag);
#endif

/*if(db_out.dptr != '\0') */
if(db_out.dsize != 0)
{
strncpy(ans_str,db_out.dptr,db_out.dsize);
ans_str[db_out.dsize]='\0';
printf("MAP_%s_MAP",ans_str);
}
else printf("LWG_%s_LWG",ans_str);
}

main(argc,argv)
int argc;
char *argv[];
{
#ifdef GNU
db_story_wrds = gdbm_open(argv[1],512,GDBM_READER,0644,my_fatal());
#else
db_story_wrds = dbm_open(argv[1],O_RDONLY,0644);
#endif

yylex();

#ifdef GNU
gdbm_close(db_story_wrds);
#else 
dbm_close(db_story_wrds);
#endif
}

