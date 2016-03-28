# $Id: filter_LWG.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
while($in = <STDIN>)
{
$in =~ s/¤[a-zA-Z_]*//g;
print $in;
}
