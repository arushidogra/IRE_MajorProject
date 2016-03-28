# $Id: sel_mc_ans1.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
# Here the answer is selected if it is single one.
# If it has multiple answers:
# In case of nouns the one with 0 vibh is selected.
local($ans,@ans,$ana,$out);
while($in = <STDIN>)
{
#print $in;
chop($in);
# in case of single ans print it
if($in !~ /\//) { print $in,"\n"; }
else # multiple answers
{
($rt,$ana) = split(/,/,$in,2); # 2 is added to avoid truncation of ana field,
# in case it contains ','.
#print $rt," ",$ana,"\n";
@ans = split(/\//,$ana);
$i=0;
while($ans[$i] ne "") { $i++;}
$k=$i;
#print $k,"\n";
#print ""; # Why is this line required?
$non_rare=0; # If all are rare, 1st shld be outside the brckets
$out = "";
for($i=0;$i<$k;$i++)
{
if($ans[$i] !~ /%/) { $non_rare = $i;last;}
}
#$out = $out.$ans[$non_rare]."[";
$out = $out.$ans[$non_rare];
#print $non_rare,"\n";
#print $out,"\n";
for($i=0;$i<$k;$i++)
{
#print $i,"\n";
if($i != $non_rare) {$out = $out."/".$ans[$i];}
}
#$out =~ s/$/\]/;
#$out =~ s/\[\//\[/;
print $rt,",",$out,"\n";
}
}
