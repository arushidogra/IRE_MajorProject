/**
 * File Name : print_default_ans.c
 */

/** Function: print_default_ans
 * This function gives the output in horizontal way when there is singular direct case
 * Ittake arguments: word of char array
 */


#include "defn.h"
/**
 * Prototypes of the functions in this file with a file scope
 */

extern void resufun();

void print_default_ans(char *word)

   {
     int offset;
     offset = 1; /* This is the offset from feature_value.c file corresponding to singular direct case */

/* This function prints the root,pdgm,priority ,category */
      resufun(word,offset); //introduced arguments
     }
