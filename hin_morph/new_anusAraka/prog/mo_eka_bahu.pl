# $Id: mo_eka_bahu.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
while($in = <STDIN>)
{
chop($in);
$in =~ s/\/$//;
for($i=0;$i<100;$i++) {$ans[$i] = "z";}
($rt,$ana) = split(/,/,$in,2); # 2 is added to avoid truncation, in case
# ana contains ','.
print $rt,",";
if($ana !~ /\//) { print $ana,"\n";}
else
{
@ans = split(/\//,$ana);
$k = #$ans;
@ans_srt = sort(@ans);
for($i=0;$i<$k;$i++) {
if(!&my_cmp($ans_srt[$i],$ans_srt[$i+1]))
{
print $ans_srt[$i],"\/";
}
else
{
$ans_srt[$i] =~ s/bahu/any/;
print $ans_srt[$i],"\/";
}
}
print "\n";
}
}

sub my_cmp
{
local($str1,$str2) = @_;
if($str1 =~ /{(.*) [nP] .*bahu/)
{
$str1 =~ s/(.*) n any bahu \*0\*/\1 n any eka \*0\*/;
if($str1 eq $str2) { $ans = 1;}
else { $ans = 0;}
}
$ans;
}
1;
