#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct1.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct.h"
cp_suff_add_struct(suff_add,ch_ar)
char suff_add[SUFFWORDSIZE];
char ch_ar[SUFFWORDSIZE];
{
struct suff_add_info dummy;
int i,size;
i=0;
size=sizeof(dummy);
for(i=0;i<size;i++)
suff_add[i]=*ch_ar++;
}
