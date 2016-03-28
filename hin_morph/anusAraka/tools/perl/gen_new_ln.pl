$ln_no = 1;
$/ = " .";
while($in = <STDIN>)
{
$in =~ s/<[0-9]*>//g;
$in =~ /([\n\t]*)(.)/;
print $1," <",$ln_no,"> ",$2,$'; $ln_no++;
}
