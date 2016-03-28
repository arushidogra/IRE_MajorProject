# $Id: get_mng.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
sub get_mng
{
local($dict_mng,$ALL) = @_;
#$dict_mng =~ s/1\.//;
if($ALL == 0){
$dict_mng =~ s/\/.*//;
$dict_mng =~ s/1\.//;
}
$dict_mng =~ s/\+//;
#$dict_mng =~ s/;/\/g/;
#print "WITHIN get_mng",$dict_mng;
$dict_mng;
}
1;
