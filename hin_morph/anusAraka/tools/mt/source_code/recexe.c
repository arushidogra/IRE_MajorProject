#include <stdio.h>
char shellcmd[100];

extern void recurse();

main(argc,argv)
int argc;
char **argv;
{
	char fname[100];
	extern void execute_sh();
	if (argc != 3) {
		fprintf(stderr,"Usage: cmd startdir shellfile\n");
		exit(-1);
	}
	strcpy(shellcmd,argv[2]);
	strcpy(fname,argv[1]);
	recurse(fname,execute_sh);
}
void
execute_sh(filename)
char *filename;
{
	char cmd[100];
	sprintf(cmd,"%s %s",shellcmd,filename);
	system(cmd);
}
