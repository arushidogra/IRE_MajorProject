/**
 * File Name : get_suff.c
 */



/** Function: get_suff
 * This function concatenates the root word with the suffix
 * It takes arguments morph of char array type , suff of char array and position of int type    
 * Return : void
 */
#include <string.h>
#include <stdio.h>
#include "defn.h"
#include "morph_logger.h"

extern char *program_name;
extern FILE *log_file;

#define FUNCTION "get_suff()"
void get_suff(morph,suff,position)

char suff[SUFFWORDSIZE],morph[Morphsize];  /* suffix of word and morph given word */
int position;                              /* position of char in word */
 {
    char chr[2];                           /* chr is char of 2 bytes to check for last 
                                               char of morph and null */
    PRINT_LOG(log_file, "concating the root word with the suffix\n");
    chr[0]=morph[position];  /* stores the morph word last letter position in chr[0] */
    chr[1]='\0';
    strcat(suff,chr);
 }
