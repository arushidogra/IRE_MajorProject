WRD [A-Za-z_][A-Za-z_]*
SPACE [\t\n0 ]
PNCT [?\.!"]
%%
{WRD}/{SPACE}*{PNCT}	{prefer_verb(yytext);}
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
GDBM_FILE db_multi_wrds;
#else
DBM *db_multi_wrds;
#endif


prefer_verb(word)
char word[100];
{
char ans_str[1000],*ptr_tmp,*tmp;
char ans_ar[20][1000];
char ans[1000];
char lft[1000];
char rt[1000];

datum db_tag,db_out;
int i,j;

strcpy(ans_str,word);
strcpy(ans,word);
db_tag.dptr = word;
db_tag.dsize = strlen(word);
#ifdef GNU
db_out = gdbm_fetch(db_multi_wrds,db_tag);
#else
db_out = dbm_fetch(db_multi_wrds,db_tag);
#endif

if(db_out.dptr != '\0')
{
strncpy(ans_str,db_out.dptr,db_out.dsize);
ans_str[db_out.dsize]='\0';
}
strcpy(ans_ar[0],ans_str);
lft[0] = '\0';
for(i=0;;)
{
if((ptr_tmp =(char *) strchr(ans_ar[i],(int)'/')) == NULL) break;
*ptr_tmp = '\0';
strcpy(ans_ar[++i],ptr_tmp+1);
if((tmp = (char *) strchr(ans_ar[i-1],(int)'V')) != NULL) {
strcpy(ans,tmp+2);
strcat(ans,"[");
if(ans_ar[i][0] != '\0') {
strcat(ans,ans_ar[i]);
}
if(lft[0] != '\0') {
strcat(ans,"/");
strcat(ans,lft);
}
strcat(ans,"]");
break;
}
else { strcat(lft,ans_ar[i-1]);strcat(lft,"/");}
}
printf("%s",ans);
}


main(argc,argv)
int argc;
char *argv[];
{
#ifdef GNU
db_multi_wrds = gdbm_open(argv[1],512,GDBM_READER,0644,my_fatal());
#else
db_multi_wrds = dbm_open(argv[1],O_RDONLY,0644);
#endif

yylex();

#ifdef GNU
gdbm_close(db_multi_wrds);
#else
dbm_open(db_multi_wrds);
#endif

}

