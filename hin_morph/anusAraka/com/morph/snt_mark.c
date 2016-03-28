#include "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/headers/defn.h"

int snt_num(morph)
char morph[Morphsize];
{
int len,i,success;
len = strlen(morph);
success = 1;
if((morph[0] == '<') && (morph[len-1] == '>') && (morph[1] == 's'))
{
for(i=2;i<len-2;i++)
{
if((morph[i] < '0') || (morph[i] > '9')) { success = 0;break;}
}
}
else  success = 0;
return success;
}

int end_mark(morph)
char morph[Morphsize];
{
int success;
success = 0;
if((morph[0] == '<') && (morph[2] == '>') && (morph[1] == '.'))
{
success = 1;
}
return success;
}

void
print_snt_num(morph)
char morph[Morphsize];
{
int len = strlen(morph);
if(morph[0] == '<') morph[0] =' ';
if(morph[len-1] == '>') morph[len-1] ='\0';
printf("#%s\n",morph);
}
