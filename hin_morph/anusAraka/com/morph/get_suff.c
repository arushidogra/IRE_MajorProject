#include <string.h>
#include <stdio.h>
#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"

void 
get_suff(morph,suff,position)
char suff[SUFFWORDSIZE],morph[Morphsize];
int position;
{
char chr[2];
chr[0]=morph[position];
chr[1]='\0';
strcat(suff,chr);
}
