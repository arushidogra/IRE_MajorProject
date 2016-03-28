# $Id: put_in_cmnts.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
while($in = <STDIN>)
{
if($in !~ /\[/)
{
$in =~ s/\/(.*)\/$/[\1]/;
}
$in =~ s/\/$//;
print $in;
}
