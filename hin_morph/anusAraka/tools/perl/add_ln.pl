$ln_no = 1;
$/ = " .";
while(<STDIN>)
{
if(/([\n\t]*)(.)/)
{ print $1," <",$ln_no,"> ",$2,$';$ln_no++;}
}
