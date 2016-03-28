while(<STDIN>)
{
#s/lY/lV/g; Only for Kannada
#s/rY/r/g; Only for TElugu??
s/Z//g;
s/#/$ /g;
s/"/ " /g;
s/,/ , /g;
s/\.([a-zA-Z])/. \1/g;
s/([a-zA-Z])\./\1 ./g;
s/\.\n/ .\n/g;
s/\?/ ? /g;
s/!/ ! /g;
s/;/ ; /g;
s/:/ : /g;
s/\)/ ) /g;
s/\(/ ( /g;
s/'/ ' /g;
s/`/ ` /g;
#s/_/ - /g;
s/-/ - /g;
print $_;
}
