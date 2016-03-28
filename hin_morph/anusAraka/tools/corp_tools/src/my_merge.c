#include <stdio.h>
#include <string.h>
/* input : 
3 Agibiduwwaxo
1 BAvanavara
10 BAvanavara
7 BAvanavarigeV
2 BAvanavaru
4 aSvameXa
9 pariSecanavannu
5 rigeV
6 rigeV
8 wAne

output : 
3 Agibiduwwaxo
11 BAvanavara
7 BAvanavarigeV
2 BAvanavaru
4 aSvameXa
9 pariSecanavannu
11 rigeV
8 wAne
*/

main(argc,argv)
int argc;
char *argv[];
{
FILE *fpt1;
char fir[100],prev[100];
int num,cum_num;
if(argc<2)
{
printf("Usage my_merge.out file_name\n");
exit(0);
}
if((fpt1=fopen(argv[1],"r"))==NULL)
{
printf("Error in opening %s\n",argv[1]);
exit(0);
}
cum_num=0;
fgetnumber(fpt1,&num,' ');
cum_num = num;
fgetword(fpt1,fir,' ');
strcpy(prev,fir);
fgetnumber(fpt1,&num,' ');
while(num>0)
{
fgetword(fpt1,fir,' ');
if(!strcmp(prev,fir)) 
cum_num = num+cum_num;
else
{
printf("%d %s\n",cum_num,prev);
strcpy(prev,fir);
cum_num = num;
}
fgetnumber(fpt1,&num,' ');
}
printf("%d %s\n",cum_num,prev);
}
