WRD [A-Za-z][A-Za-z]*           
%%               
{WRD}   {printf(" %s ",yytext);}
%%
