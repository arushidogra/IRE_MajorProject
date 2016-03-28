#include <stdio.h>
#include <string.h>

main(argc,argv)
int argc;
char *argv[];
{
FILE *fpt1;
char fir[100];
int TOTAL,num,total_count,cur_num;
int flag_t,flag_n;
int line_count;
flag_t = 0;
flag_n = 0;
if(argc<2)
{
printf("Usage sum.out file_name [nt] number \n");
exit(0);
}
if((fpt1=fopen(argv[1],"r"))==NULL)
{
printf("Error in opening %s\n",argv[1]);
exit(0);
}
if(argc==2) {flag_t=0;flag_n=0;}
if(argc==4)
{
if(argv[2][0]=='t'){ total_count = atoi(argv[3]); flag_t = 1;printf("%d\n",total_count);}
if(argv[2][0]=='n'){ cur_num = atoi(argv[3]); flag_n = 1;printf("%d\n",cur_num);}
}
TOTAL=0;
line_count=0;
fgetnumber(fpt1,&num,' ');
while(num > 0 && ((flag_t && total_count > TOTAL) || (flag_n && num < cur_num)))
{
line_count++;
TOTAL+=num;
fgetword(fpt1,fir,' ');
fgetnumber(fpt1,&num,' ');
}
printf("%d\n",TOTAL);
printf("lines =%d\n",line_count);
printf("%d %s\n",num,fir);
}

