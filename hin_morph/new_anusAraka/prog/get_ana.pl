# $Id: get_ana.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
while($in = <STDIN>)
{
$in =~ s/#_/\n/g;
$in =~ s/_#/\n/g;
$in =~ s/LWG_/\n/g;
$in =~ s/_LWG/\n/g;
print $in;
}
