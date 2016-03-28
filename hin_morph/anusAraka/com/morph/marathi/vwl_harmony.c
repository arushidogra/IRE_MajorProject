#include <string.h>
#include <stdio.h>

vwl_harmony(in_wrd,pdgm,out_wrd)
char *in_wrd,*out_wrd,*pdgm;
{
int len,i,j;
char lst_but_one_vwl;

len = strlen(in_wrd);
if(is_dbl_cns(pdgm)){
for(i=0;i<len-3;i++) out_wrd[i]=in_wrd[i];
out_wrd[len-3]=in_wrd[len-4];
out_wrd[len-2]=in_wrd[len-3];
out_wrd[len-1]=in_wrd[len-2];
out_wrd[len]=in_wrd[len-1];
out_wrd[len+1] = '\0';
}
else{
if(is_aI_pdgm(pdgm) || is_aU_pdgm(pdgm) || is_I_pdgm(pdgm) || is_U_pdgm(pdgm)|| is_va_pdgm(pdgm)){
lst_but_one_vwl = in_wrd[len-3];
for(i=0;i<len;i++) out_wrd[i]=in_wrd[i];
out_wrd[len] = '\0';
if(lst_but_one_vwl == 'I') out_wrd[len-3] = 'I';
else if(lst_but_one_vwl == 'U') out_wrd[len-3] = 'U';
else if((lst_but_one_vwl == 'a') && is_aI_pdgm(pdgm)) out_wrd[len-3] = 'I';
else if((lst_but_one_vwl == 'a') && is_aU_pdgm(pdgm)) out_wrd[len-3] = 'U';
else if((lst_but_one_vwl == 'i') && is_I_pdgm(pdgm)) out_wrd[len-3] = 'I';
else if((lst_but_one_vwl == 'u') && is_U_pdgm(pdgm)) out_wrd[len-3] = 'U';
else if((lst_but_one_vwl == 'v') && is_va_pdgm(pdgm)) out_wrd[len-3] = 'U';
else if(lst_but_one_vwl == 'i') out_wrd[len-3] = 'I';
else if(lst_but_one_vwl == 'u') out_wrd[len-3] = 'U';
}
else out_wrd[0] = '\0';
}
}

int is_aI_pdgm(pdgm)
char *pdgm;
{
if(!strcmp(pdgm,"cil?ma")) return 1;
if(!strcmp(pdgm,"uMx?ra")) return 1;
else return 0;
}

int is_I_pdgm(pdgm)
char *pdgm;
{
if(!strcmp(pdgm,"pAk?ta")) return 1;
if(!strcmp(pdgm,"Pik?ra")) return 1;
if(!strcmp(pdgm,"bat?ka")) return 1;
if(!strcmp(pdgm,"cetak?Na")) return 1;
if(!strcmp(pdgm,"cil?ma")) return 1;
if(!strcmp(pdgm,"molakar?Na")) return 1;
if(!strcmp(pdgm,"uMx?ra")) return 1;
if(!strcmp(pdgm,"v?ja")) return 1;
else return 0;
}

int is_aU_pdgm(pdgm)
char *pdgm;
{
if(!strcmp(pdgm,"mAN?sa")) return 1;
if(!strcmp(pdgm,"cim?ta")) return 1;
else return 0;
}

int is_U_pdgm(pdgm)
char *pdgm;
{
if(!strcmp(pdgm,"pA?sa")) return 1;
if(!strcmp(pdgm,"pA?la")) return 1;
if(!strcmp(pdgm,"m?la")) return 1;
if(!strcmp(pdgm,"s?ja")) return 1;
else return 0;
}

int is_va_pdgm(pdgm)
char *pdgm;
{
if(!strcmp(pdgm,"pA?la")) return 1;
if(!strcmp(pdgm,"pA?sa")) return 1;
else return 0;
}

int is_dbl_cns(pdgm)
char *pdgm;
{
if(!strcmp(pdgm,"maddama")) return 1;
if(!strcmp(pdgm,"Sillaka")) return 1;
if(!strcmp(pdgm,"gammawa")) return 1;
else return 0;
}
/*
main()
{
char str[100],str1[100],pdgm[100];
scanf("%s %s",str,pdgm);
vwl_harmony(str,str1,pdgm);
printf("%s %s\n",str,str1);
}
*/
