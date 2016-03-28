/************* THIS FUNCTION CHECKS WHETHER GIVEN WORD ********
************IS AVY OR NOT IT RETURNS THE VALUE OF ********/
 
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"

extern int sizeof_ind;
extern char indword[][AVYWORDSIZE];


int AVY_srch(morph)
char morph[Morphsize];
{
int i,size_avy_struct;
char *avy_ptr,*malloc(),dummy_avy[AVYWORDSIZE];
void *my_bsearch();
int morph_size;
int ISNUMBER;

/* Put in comments TEMP_FIX 
avy_ptr = (char *)malloc(sizeof(char));
*/
size_avy_struct = sizeof(dummy_avy);

/********to check if given word is nonalphabet ********/
morph_size=strlen(morph);
ISNUMBER = 1;
for (i = 0;i <= morph_size;++i)
        if(isalpha(morph[i]))
              {
                ISNUMBER = 0;
        	break;
              }
if (ISNUMBER)
	return(-3); /* numeral */

else
/********searching in avy file **********************/
 {   
        avy_ptr=(char *)my_bsearch(morph,(char *)indword,sizeof_ind,size_avy_struct,strcmp);
/*         SEARCHED IN AVY FILE */
        if (avy_ptr != NULL)
          {
/*                free(avy_ptr);*/
		return (-1);
          }
        else return (-2); /* Neither a numeral not an avy */
 }
}
