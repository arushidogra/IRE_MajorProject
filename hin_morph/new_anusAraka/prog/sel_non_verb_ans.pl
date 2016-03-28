# $Id: sel_non_verb_ans.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
# Here the answer is selected if it is single one.
# If it has multiple answers:
# In case of nouns the one with 0 vibh is selected.
while($in = <STDIN>)
{
$flag = 0;
chop($in);
($wrd,$mng) = split(/,/,$in,2); #2 is added to avoid truncation, in case ana
#contains ','.
print $wrd,",";
@ans_ar = split(/\//,$mng);
local($rt,$lft,$mid);
$rt = "";
$lft = "";
$mid = "";
foreach $ans (@ans_ar)
{
#print "1",$ans,"\n";
if(($ans !~ /V\./) && ($ans !~ /%%/)&& (!$flag)) { 
$mid = $ans;
#print $mid,"\n";
$flag = 1;
}
elsif(!$flag) {$lft = $lft."/".$ans;}
else {$rt = $rt."/".$ans;}
}
if(!$flag){
$rt = "";
$lft = "";
$mid = "";
# select first non rare answer
foreach $ans (@ans_ar)
{
if(($ans !~ /%%/) && (!$flag)) {
$mid = $ans;
$flag = 1;
}
elsif(!$flag) {$lft = $lft."/".$ans;}
else {$rt = $rt."/".$ans;}
}
}
if($flag){ 
$lft =~ s/^/\[/;
$rt =~ s/$/\]/;
$ans = $mid.$lft.$rt;
$ans =~ s/\[\//\[/;
print $ans,"\n";
}
else{
# If all the answers are rare, select the 1st one.
$ans =~ s/\//\[/;
$ans =~ s/$/\]/;
#print "BBBB",$ans,"\n";
}
}
