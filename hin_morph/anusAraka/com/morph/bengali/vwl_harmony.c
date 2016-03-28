#include <string.h>
#include <stdio.h>

vwl_harmony(in_wrd,out_wrd)
char *in_wrd,*out_wrd;
{
int len,i,j;
char lst_ch;

len = strlen(in_wrd);
lst_ch = in_wrd[len-1];
if(lst_ch == 'a')
{
i=len;
while((in_wrd[i] != 'e')  && i>0)
{
out_wrd[i] = in_wrd[i];
i--;
}
out_wrd[i] = 'A';
for(j=i-1;j>=0;j--)
{
out_wrd[j] = in_wrd[j];
}
}
else out_wrd[0] = '\0';
}
main()
{
char str[100],str1[100];
scanf("%s",str);
vwl_harmony(str,str1);
printf("%s %s\n",str,str1);
}
