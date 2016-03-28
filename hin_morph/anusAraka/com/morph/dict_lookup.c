#include <string.h>
#include <stdio.h>
#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include <fcntl.h>
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"

extern void build_struct();
extern char * my_blk_bsearch();

void dbm_dict_lookup(word,db,ans_ar1)
char word[WORD_SIZE];
#ifdef GNU
GDBM_FILE db;
#else
DBM *db;
#endif

char ans_ar1[100][2000];
{
datum db_tag,db_out;
int i;
char temp_str[2000], *ptr_tmp,ans_ar[100][2000];

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
build_struct(word,ans_ar,ans_ar1);
}
void flat_dict_lookup(word,base,nel,width,compar,ans_ar)
char *base,*word;
int nel,width;
int (* compar)();
char ans_ar[100][2000];
{
char * tag_out;
int ans,i,j;
tag_out =  (char *)my_blk_bsearch(word,base,nel,width,strcmp);
i=0;
if(tag_out != '\0')
{
ans = (* compar) (word,tag_out);
while(!ans)
{
for(j=0;j<width;j++)
ans_ar[i][j]=tag_out[j];
ans_ar[i][j] = '\0';
i++;
tag_out = tag_out + width;
ans = (* compar) (word,tag_out);
}
}
strcpy(ans_ar[i] , "");
}

void
dict_lookup(word,DBM_FLAG,db,base,nel,width,compar,ans_ar)
char *base,*word;
int nel,width;
int (* compar)();
char ans_ar[100][2000];
int DBM_FLAG;
#ifdef GNU
GDBM_FILE db;
#else
DBM *db;
#endif

{
if(DBM_FLAG)
dbm_dict_lookup(word,db,ans_ar);
else
flat_dict_lookup(word,base,nel,width,compar,ans_ar);
}

void prop_noun_dict_lookup(word,base,nel,width,compar,ans_ar)
char *base,*word;
int nel,width;
int (* compar)();
char ans_ar[100][2000];
{
char * tag_out;
int ans,i,j;
tag_out =  (char *)my_blk_bsearch(word,base,nel,width,strcmp);
i=0;
if(tag_out != '\0')
{
ans = (* compar) (word,tag_out);
while(!ans)
{
for(j=0;j<width;j++)
ans_ar[i][j]=tag_out[j];
ans_ar[i][j] = '\0';
i++;
tag_out = tag_out + width;
ans = (* compar) (word,tag_out);
}
}
strcpy(ans_ar[i] , "");
}

