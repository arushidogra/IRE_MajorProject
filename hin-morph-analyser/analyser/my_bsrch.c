/**
 * File Name : my_bsrch.c
 */

/** Given the table start address - base,
  * the table size - nel,
  * the table width - width,
  * the comparison function - compar,
  * this function returns the ptr to the location of the key
  * in the table, if it is present else returns a null
  * Return : void
  */

 #include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include "morph_logger.h"

extern char *program_name;
extern FILE *log_file;

#define FUNCTION "my_bsearch()"


void *my_bsearch(key,base,nel,width,compar)
        /* Given the table start address - base,
         the table size - nel,
         the table width - width,
         the comparison function - compar,
	 this function returns the ptr to the location of the key
	 in the table, if it is present else returns a null
          */

	char *base,*key;
	int nel,width;
	int (* compar)();
	{
	    int low,high,mid,ans;
	    PRINT_LOG(log_file, "returning the pointer to the location of the key in the table\n");
	    low = 0; 
	    high = nel-1;
	    while (low <= high)   /* executes till low is <= high */
 		{
			mid = (low + high)/2;	
			ans = (* compar)(key,(char *)(base+mid*width));
		/* printf("The string being tested is %s\n",(char *)(base+mid*width)); */
			if (ans < 0) 
			    high = mid -1;
			else if (ans > 0) 
			    low = mid +1;
		        else 
                            return ((void *) (base + mid*width)); /* returns address of base+mid*width 's value */
	          }
	     return ((void *) '\0');  /* return null pointer */
         }
