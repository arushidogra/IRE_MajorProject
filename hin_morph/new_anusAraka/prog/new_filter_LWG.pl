# $Id: filter_LWG.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
while($in = <STDIN>)
{
$in =~ s/#_\^\^\^_#/\n/g;
$in =~ s/#[^a-zA-Z]*#/#\n#/g;
$in =~ s/#[^a-zA-Z]*$/#\n/;
$in =~ s/#_LWG_---_LWG_#/\n/g;
$in =~ s/#_LWG_//g;
$in =~ s/_LWG_#/\n/g;
$in =~ s/OUT//g;
$in =~ s/FRZ//g;
$in =~ s/#_[^#]*_#//g;
$in =~ s/([ \t\n])[ \t\n]*/\1/g;
$in =~ s/^([ \t\n])[ \t\n]*//g;
print $in;
}
