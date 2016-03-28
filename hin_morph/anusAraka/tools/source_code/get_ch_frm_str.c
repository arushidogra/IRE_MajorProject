#include <stdio.h>
#define NEW 1
#define UNGET -1

int 
get_ch_frm_str(flag,strng)
int flag;
char *strng;
{
static int g;
static char str[1000];
if(flag == UNGET)
    { 
     g--; 
     return(0);
    };
if(flag == NEW)
   {
    g = 0;
    strcpy(str,strng);
   }
else if(str[g]=='\0') 
       {
       g++;
       return(EOF);
       } 
     else return(str[g++]);
};
/*
main(argc,argv)
char *argv[];
int argc;
{
int j,c;
if(argc<2)
   {
     printf("Usage a.out strng\n");
     exit(0);
   }
printf("str=%s\n",argv[1]);
get_ch_frm_str(1,argv[1]);
c=get_ch_frm_str(0,"");
while(c!=EOF)
{
printf("%c\n",c);
c=get_ch_frm_str(0,"");
}
}
*/
