/**
 * my_fatal.c
*/

/** Function: my_fatal
  * This function displays a message  "File not found"  
  * when the files dict_final,suff are not there
  * It takes arguments fpt of char array
  * derived by  K.SWATHI ,koradaswathi13@gmail.com
  */


#ifdef GNU
#endif
#include <stdio.h>
#include <stdlib.h>
#include "morph_logger.h"

extern FILE *log_file;

void my_fatal(char fpt[100])
   {
	if(!fpt)        /* fpt is not true */
          {
 		printf("ERROR could not find dict_final %s   please check the path ",fpt); exit(0);

	   }
    }
