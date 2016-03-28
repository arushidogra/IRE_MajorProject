#include <stdio.h>
#define START 0
#define OVER 2

static int p;
static char str[1000];

/*if flag is 0 both the arguments are dummy */
int 
put_ch_in_str(flag,format,strng)
int flag;
char *format;
char strng;
{
 str[p++]=strng;
}
int 
put_str_in_str(flag,format,strng)
int flag;
char *format;
char *strng;
{
int j;
switch (flag){
case  START : 
    		p = 0;
    		str[0]='\0';
      		break;
case  OVER  :   str[p]='\0';
                strcpy(strng,str);
      		break;
default     : for(j=0;j<strlen(strng);j++)
               str[p++]=strng[j]; 
}
}
/*
main(argc,argv)
char *argv[];
int argc;
{
char str[100] ;
put_str_in_str(0,"%s",str);
put_str_in_str(1,"%s","rAma");
put_ch_in_str(1,"%c",'x');
put_str_in_str(1,"%s","sIwA");
put_str_in_str(2,"%s",str);
printf("%s\n",str);
}
*/
