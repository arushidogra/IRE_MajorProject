$/ = "input_word";
while(<STDIN>)
{
s/\n/ /g;
s/input_word//;
s/(# s[0-9]*)/\n$1/;
print $_,"\n";
}
