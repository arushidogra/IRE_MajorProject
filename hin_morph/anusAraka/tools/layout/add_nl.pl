$ln_no = 1;
$/ = " .";
while(<STDIN>)
{
if(/([\n\t]*)(.)/)
{ print $1,"\n ",$2,$';$ln_no++;}
}
