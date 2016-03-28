#include <string.h>
#include <stdio.h>

vwl_harmony(in_wrd,pdgm,out_wrd)
char *in_wrd,*pdgm,*out_wrd;
{
char lst_ch;
int i,q_cnt,ch_cnt,len,j;

/*printf("%s,%s\n",in_wrd,pdgm);*/
q_cnt = 0;
len = strlen(pdgm);
for(i=0;i<len;i++) {if(pdgm[i] == '?') q_cnt++;}
len = strlen(in_wrd);
lst_ch = in_wrd[len-1];

/*printf("%d\n",q_cnt);*/

if((lst_ch == 'i') || (lst_ch == 'u'))
{
for(i=0;i<len;i++) if(isvowel(in_wrd[i])) {j=i; break;}
for(i=0;i<j+1;i++) out_wrd[i]=in_wrd[i];
out_wrd[len-1]=in_wrd[len-1];
out_wrd[len] = '\0';
ch_cnt = 0;
for(i=len-2;i>j;i--)
{
if(ch_cnt < q_cnt)
{
if((lst_ch =='i') && (in_wrd[i] == 'u')) {out_wrd[i] = lst_ch;ch_cnt++;}
else if((lst_ch =='u') && (in_wrd[i] == 'i')) {out_wrd[i] = lst_ch;ch_cnt++;}
else if((lst_ch =='u') && (in_wrd[i] == 'a')) {out_wrd[i] = lst_ch;ch_cnt++;}
else if((lst_ch =='u') && (in_wrd[i] == 'u')) {out_wrd[i] = in_wrd[i];ch_cnt++;}
else if((lst_ch =='i') && (in_wrd[i] == 'i')) {out_wrd[i] = in_wrd[i];ch_cnt++;}
else out_wrd[i]=in_wrd[i];
}
else out_wrd[i]=in_wrd[i];
}
}
else out_wrd[0] = '\0';
/*printf("%s\n",out_wrd);*/
}
/*
main()
{
char str[100],str1[100],pdgm[100];
scanf("%s %s",str,pdgm);
vwl_harmony(str,pdgm,str1);
printf("%s %s\n",str,str1);
}
*/
