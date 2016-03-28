#include <string.h>
#include <stdio.h>
#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif


#include <fcntl.h>
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"

extern void suff_build_struct();

char *dbm_suff_tab_lookup(word,db)
char word[SUFFWORDSIZE];
#ifdef GNU
GDBM_FILE db;
#else
DBM *db;
#endif

{
datum db_tag,db_out;
int i;
char temp_str[200], *ptr_tmp,ans_ar[100][2000];

struct suff_add_info ans_ar1[100];

db_tag.dptr = word;
db_tag.dsize = strlen(word);
#ifdef GNU
db_out = gdbm_fetch(db,db_tag);
#else
db_out = dbm_fetch(db,db_tag);
#endif

if(db_out.dptr != '\0')
{
strncpy(temp_str,db_out.dptr,db_out.dsize);
temp_str[db_out.dsize]='#';
temp_str[db_out.dsize+1]='\0';
strcpy(ans_ar[0],temp_str);
for(i=0;;)
{
if((ptr_tmp = strchr(ans_ar[i],'#')) == NULL)break;
*ptr_tmp = '\0';
strcpy(ans_ar[++i],ptr_tmp+1);
}
}
else ans_ar[0][0] = '\0';
suff_build_struct(word,ans_ar,ans_ar1);
return ans_ar1;
}
