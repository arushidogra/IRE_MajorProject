# $Id: get_rt.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/prog/get_mng.pl";
sub get_rt
{
local($rt,$cat,$cnt,$ALL) = @_;
local($tl_info,$dict_entry,@dict_entries,$pdgm,$dict_cat,$dict_mng,$dict,$count);
$mng = $rt; # If the word is not found in dict, mng is same as sl_rt
#print $rt," ",$cat,"\n";
if($DICT{$rt}){ $tl_info = $DICT{$rt}."#";}
#print $tl_info,"\n";
@dict_entries = split(/#/,$tl_info);
$count = 0;
$new_mng = "";
foreach $dict_entry (@dict_entries)
{
$dict_entry =~ /([^"]*)","([^"]*)","([^"]*)","([^"]*)/; # a comment may follow
#print $dict_entry,"\n";
$pdgm = $1;
$dict_cat = $2;
$dict_mng = $3;
#$dict_mng =~ s/;.*//; # TEMP FIX, for multiple mngs in punjabi dict
$dict = $4;
if(&chk_cat($dict_cat,$cat)){
$mng = &get_mng($dict_mng,$ALL);
#if($cat eq "avy") { $mng = "1.".$mng;} ?? Why is this line necessary?
if($mng !~ /UNKN/) {
$new_mng = $new_mng."/".$mng; 
# the multiple entries in avys is treated at par with multiple categories.
}
}
}
if($new_mng) {
$new_mng =~ s/^\///;
$new_mng =~ s/$/\//;
#$new_mng =~ s/#/\[/;
#if($new_mng =~ /\[/) { $new_mng =~ s/$/\]/;}
$mng = $new_mng;
}
if($mng eq "UNKN") { $mng = $rt;}
elsif($mng eq "%%UNKN") { $mng = "%%".$rt;}
$mng;
}
1;
