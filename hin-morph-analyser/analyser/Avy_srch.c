/**
 * File Name : Avy_srch.c
 */


/** Function : Avy_srch
 * Avy_srch(morph)
 * This function checks whether the given word is Avy or not.
 * If it is true it returns the numeric value.
 * it takes morph of char type as argument. whrer morph is the input word
 * Return :int , returns a numeric value indicating as a numeral or a special
 * character
 */


#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include "defn.h"
#include "morph_logger.h"

extern char *program_name;
extern FILE *log_file;
extern char *log_messg;
#define FUNCTION "Avy_srch()"
extern int sizeof_ind;		/* table size */
extern char indword[][AVYWORDSIZE];	/* table start address */
extern void *my_bsearch();

/**
 * Prototypes of the functions in this file with a file scope
*/
int AVY_srch(morph)
char morph[Morphsize];		/* word */
{
    int loop1, size_avy_struct;	/* size of avy */
    char *avy_ptr, dummy_avy[AVYWORDSIZE];	/* pointer of avy , dummy avy */
    int morph_size;		/* word length */
    int ISNUMBER;		/* isnumber for checking numeric value */

    PRINT_LOG(log_file,
	      " checking whether the given word is Avy or not.\n");
    size_avy_struct = sizeof(dummy_avy);

    /* to check if given word is nonalphabet */
    morph_size = strlen(morph);
    ISNUMBER = 1;
    /* check if loop is alpha numeric or not */
    for (loop1 = 0; loop1 <= morph_size; ++loop1)

	if (isalpha(morph[loop1])) {	/* if morph is alpha numeric */
	    ISNUMBER = 0;
	    break;
	}
    if (ISNUMBER)		/* if ISNUMBER is true */
	return (-3);		/* numeral */
    else {
/*** searching in avy file ***/

	/* this function returns the ptr to the location of the key                           in the table, if it is present else returns a null */
	avy_ptr =
	    (char *) my_bsearch(morph, (char *) indword, sizeof_ind,
				size_avy_struct, strcmp);
	sprintf(log_messg, "INFO: AVY has identifeid as %s", avy_ptr);
	PRINT_LOG(log_file,
		  " checking whether the given word is Avy or not.\n");

	if (avy_ptr != NULL) {	/* searched in AVY file */
	    /* free(avy_ptr); */
	    return (-1);
	} else {
	    return (-2);
	}			/* Neither a numeral not an avy */
    }
}
