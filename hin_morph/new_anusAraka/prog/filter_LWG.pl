# $Id: filter_LWG.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
while($in = <STDIN>)
{
#$in =~ s/[a-zA-Z_]*_LWG//g;
$in =~ s/FRZ_[\^a-zA-Z_\[\]\/{}0-9\.\*\-%\~\`,\?!\|><\+]*_FRZ//g;
$in =~ s/OUT_[^ \+]*_OUT//g;
$in =~ s/LWG_[^ \+]*_LWG//g;
$in =~ s/@[a-zA-Z0-9]*//g;
$in =~ s/FRZ_¤[\^a-zA-Z_\[\]\/{}0-9\.>\*\-%\~\`,\?!\|><\+]*_FRZ//g;
$in =~ s/OUT_¤[^ \+]*_OUT//g;
$in =~ s/LWG_¤[^ \+]*_LWG//g;
$in =~ s/MO_¤([^ \+]*)_MO/\1/g;
print $in;
}
