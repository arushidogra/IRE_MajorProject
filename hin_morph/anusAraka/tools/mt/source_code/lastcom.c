#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
char filename[]="utils/.lastcomdat";
main()
{
	long c;
	struct tm tc, *tcp;
	int fp;
	c = time(NULL);
	tcp = localtime(&c);
	tc = *tcp;
	fp = open(filename,O_WRONLY);
	write(fp,&tc,sizeof(tc));
	close(fp);
}
