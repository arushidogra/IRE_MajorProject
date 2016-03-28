$/ = "#";
while(<STDIN>)
{
s/@ END/###/g;
s/@ BEGIN//g;
s/@.*\n//g;
s/\n/ /g;
s/CONTD/##/g;
s/OVER//g;
s/###/\n/g;
print $_,"\n";
}
