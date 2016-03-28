/************* THIS FUNCTION CHECKS WHETHER GIVEN WORD ********
************IS AVY OR NOT IT RETURNS THE VALUE OF ********/
 
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/struct1.h"

extern int sizeof_ind;
extern char indword[][AVYWORDSIZE];
/*
extern struct avy_dict avy_dict_ar[];
*/


/*
int AVY_srch(morph,ans_ar,pos)
char morph[Morphsize];
struct ans_struct ans_ar[20];
int *pos;
*/
int AVY_srch(morph)
char morph[Morphsize];
{
int i;
char *tmp,*malloc(),dummy_avy[AVYWORDSIZE];
struct avy_dict *avy_ptr;
void *my_bsearch();
int morph_size;
int ISNUMBER;

/* Put in comments TEMP_FIX 
avy_ptr = (char *)malloc(sizeof(char));
*/

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
            {
/*
                strcpy(ans_ar[*pos].root,morph);
                ans_ar[*pos].offset = -3;
                strcpy(ans_ar[*pos].aux_verb,"");
                (*pos)++;
*/
	        return(-3); /* numeral */
            }


else
/********searching in avy file **********************/
 {   
/*
        avy_ptr=(struct avy_dict *)my_bsearch(morph,avy_dict_ar->sl_rt,sizeof_ind,sizeof(avy_dict_ar[0]),strcmp);
*/
        avy_ptr=(char *)my_bsearch(morph,(char *)indword,sizeof_ind,sizeof(indword[0]),strcmp);
/*         SEARCHED IN AVY FILE */
        if (avy_ptr != NULL)
          {
/*                free(avy_ptr);*/
/*
                if((tmp = strchr(avy_ptr->tl_mng,'/')) != NULL) *tmp++ = '\0';
                strcpy(ans_ar[*pos].root,avy_ptr->tl_mng);
                ans_ar[*pos].offset = -1;
                strcpy(ans_ar[*pos].aux_verb,"");
                (*pos)++; 
*/
		return (-1);
          }
        else return (-2); /* Neither a numeral nor an avy */
 }
}
