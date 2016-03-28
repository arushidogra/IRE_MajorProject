# $Id: rm_rare_ans_nfv.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
#All the rare answers from the square brackets are removed
while($in = <STDIN>)
{
chop($in);
($rt,$ana) = split(/,/,$in,2); #2 is added to avoid truncation of ana, in case
# ana contains ','.
if($ana !~ /\//)
{
print $in,"\n";
}
else
{
$ana =~ /^([^\/]*)\/(.*)$/;
$fir = $1;
$in = $2;
if($fir !~ /%/) { $out = $1."/";}
else { $out = "";}
@ans = split(/\//, $in);
foreach $ans (@ans)
{
if($ans !~ /%/) { $out = $out."/".$ans;}
}
$out =~ s/\/\//\//g; # replace contiguous // by /
$out =~ s/^\///; # remove leading  /
print $rt,",",$out,"\n";
}
}
