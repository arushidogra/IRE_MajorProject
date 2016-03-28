%%
FRZ_[\^a-zA-Z_\[\]\/{}0-9\.\*\-%\~\`,\?!\|><\+]*_FRZ	{ printf("");}
OUT_[^ \+]*_OUT	{ printf("");}
LWG_[^ \+]*_LWG	{ printf("");}
@[a-zA-Z0-9]*	{ printf("");}
FRZ_¤[\^a-zA-Z_\[\]\/{}0-9\.>\*\-%\~\`,\?!\|><\+]*_FRZ	{ printf("");}
MO_¤([^ \+]*)_MO	{ yytext[yyleng-3] = '\0';printf("%c",yytext+2);}
