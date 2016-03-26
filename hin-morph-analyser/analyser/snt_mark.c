/**
 * FILE NAME: snt_mark.c 
*/

/** Function: snt_num , end_mark and print_snt_num
 *  This function marks a sentence number to the word
 *  It takes arguments : snt_num() takes morph of char array.
 *  end_mark() takes morph of char array as an argument
 *  print_snt_num() takes morph of char array as an argument
 *  Return : int, returns default sentence number 
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "defn.h"
#include "morph_logger.h"

extern char *program_name;
extern FILE *log_file;

#define FUNCTION "snt_num()"

int snt_num(morph)
char morph[Morphsize];     /* morph word */
{
int len,i,success;         /* length of word */
PRINT_LOG(log_file, "taking morph from array\n");

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
return success;  //returns the value of success as 1
}
//#define FUNCTION "end_mark()"
int end_mark(morph)
char morph[Morphsize];   /* morph word */
{
int success;
//char *program_name="snt_num.c";
PRINT_LOG(log_file, "passing morph as argument\n");
success = 0;
if((morph[0] == '<') && (morph[2] == '>') && (morph[1] == '.'))
{
success = 1;
}
return success;//returns the value of success as 1
}
void print_snt_num(morph)
char morph[Morphsize];
{
int len = strlen(morph);

if(morph[0] == '<') morph[0] =' ';
if(morph[len-1] == '>') morph[len-1] ='\0';
printf("#%s\n",morph);
}
