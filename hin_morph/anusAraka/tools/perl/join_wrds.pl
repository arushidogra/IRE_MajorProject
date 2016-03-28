$/ = " ";
while(<STDIN>)
{
s/~\n//g;
s/@@//g;
print $_;
}
