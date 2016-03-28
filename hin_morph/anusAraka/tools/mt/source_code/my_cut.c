#include <stdio.h>
#include <string.h>
#include <signal.h>


main(argc,argv)
int argc;
char *argv[];
{
char line[500000];
char DELIMITER;
int c;
int field_count,field_number,i;

i=0;
DELIMITER=' ';
field_number = 0;

if(argc<2) 
{
printf("Usage: my_cut.out [dc] fn\n");
exit(-1);
}
while(argc-->0)
while(c=*++argv[0])
   switch(c)
	{
	case 'f' : while(c=*++argv[0])
		   field_number = field_number * 10 + c-'0';
                   *--argv[0];
		   break;
	case 'd' : c=*++argv[0];
		   DELIMITER=c;
		   break;
	}
if(field_number==0)
{
printf("Non-zero field number should be specified.\n");
printf("Usage: my_cut.out [dc] fn\n");
exit (-1);
}
while((c=getchar()) !=EOF)
{
field_count=field_number;
ungetc(c,stdin);
i=0;
while(field_count>1)
{
while((c=getchar())!=DELIMITER && c!=EOF);
field_count--;
while((c=getchar())==DELIMITER);
ungetc(c,stdin);
}
while((c=getchar())!=DELIMITER && c!=EOF)
line[i++]=c;
line[i++]='\n';
line[i]='\0';
printf("%s",line);
while((c=getchar())!='\n' && c!=EOF);
}
}
