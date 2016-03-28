#include <stdio.h>
#include <string.h>

extern get_snt();
int REPLACE_NEW_LINE;
char DELIMITER;
int IGNORE_NULL_CHARACTER;
int ADD_LN_NOS;

main(argc,argv)
int argc;
char *argv[];
{
char line[500000];
int LINE_COUNT,c;
REPLACE_NEW_LINE=0;
LINE_COUNT=1;
ADD_LN_NOS=0;
while(argc-->0)
while(c=*++argv[0])
   switch(c)
	{
	case 'R' : REPLACE_NEW_LINE=1;
		   break;
	case 'I' : IGNORE_NULL_CHARACTER=1;
		   break;
	case 'D' : c=*++argv[0];
		   DELIMITER=c;
		   break;
	case 'N' : ADD_LN_NOS=1;
		   break;
	}
while((c=getchar()) !=EOF)
{
ungetc(c,stdin);
get_snt(line);
if(ADD_LN_NOS)
{
printf("%d. ",LINE_COUNT);
LINE_COUNT++;
}
printf("%s",line);
}
}
