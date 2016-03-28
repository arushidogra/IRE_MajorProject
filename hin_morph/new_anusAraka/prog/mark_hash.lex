WRD [A-Za-z_0-9][A-Za-z_0-9]*
%%
OUT_[^ \n]*_OUT { printf("%s",yytext);}
LWG_[^ \n]*_LWG { printf("%s",yytext);}
FRZ_[^ \n]*_FRZ { printf("%s",yytext);}
{WRD}	{printf("#%s",yytext);}
