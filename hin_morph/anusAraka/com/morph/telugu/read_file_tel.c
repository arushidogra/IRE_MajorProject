#include <string.h>
#include <stdio.h>
#include <ctype.h>
#ifdef GNU
#include <gdbm.h>
#else
#include <ndbm.h>
#endif

#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"

extern int YES_NO;

/**********THIS FUNCTION CHECKS END OF INPUT CONDITIONS *****/

void fun_close(fpt,fp_suff,swit,DBM_FLAG,db1,db2)
#ifdef GNU
GDBM_FILE db1,db2;
#else
DBM *db1,*db2;
#endif

FILE *fpt,*fp_suff;
int swit,DBM_FLAG;
{
        if (swit == 0)
                fclose(fpt);
        if (DBM_FLAG == 1)
	      {
                dbm_close(db1);
                dbm_close(db2);
	      }
        fclose(fp_suff);
        exit(1);
}



/***********THIS FUNCTION READS INPUT WORD ***************/

int fun_read(morph)
char morph[Morphsize];
{
int i,j;
int c;
j=0;
c=getchar();
while (!isalnum(c) && (c != EOF))
       {
       if(YES_NO) printf("%c",c);
       c = getchar();
       }
while(isalnum(c))
 { 
       morph[j] = c; j++;
       c = getchar();
 } 
for (i = j;i< Morphsize;++i)
       morph[i] = '\0';
/*
while((c == ' ') && (c != EOF))
       {
       if(YES_NO) printf("%c",c);
       c = getchar();
       }
*/
       ungetc(c,stdin);
return(c);
}
