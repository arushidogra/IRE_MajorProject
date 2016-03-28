/*
*
*  Program to split a big file in two files
*  Spliting is done on the basis of given charecter
*
*
*/


#include<stdio.h>
#include<string.h>
main(argc,argv)
int argc;
char *argv[];
{
  FILE *fp,*fp1,*fp2;
  char c,line[BUFSIZ];
  if(argc != 3)
  {
	fprintf(stderr,"Usage:split char file\n");
	exit();
  }
  if ( (fp = fopen(argv[2],"r")) == NULL)
  {
	perror(argv[1]);
	exit();
  }
  if ( (fp1 = fopen("first","w")) == NULL)
  {
	perror("first");
	exit();
  }
  if ( (fp2 = fopen("second","w")) == NULL)
  {
	perror("second");
	exit();
  }
  while(!feof(fp))
  {
     fgets(line,sizeof(line),fp);
     if( argv[1][0] > line[0])
	  fputs(line,fp1);
     else
	  fputs(line,fp2);
  }
}
