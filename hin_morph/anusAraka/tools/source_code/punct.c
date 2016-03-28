#include <stdio.h>
#include <ctype.h>

main()
{
   int c;
   while (( c = getchar()) != EOF ) {
	 if (ispunct(c))
	     putchar(' ');
         putchar(c);
   }
}
