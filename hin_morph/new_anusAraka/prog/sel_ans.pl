# $Id: sel_ans.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
# Here the answer is selected if it is single one.
# If it has multiple answers:
# In case of nouns the one with 0 vibh is selected.
while($in = <STDIN>)
{
chop($in);
# in case of single ans print it
if($in !~ /\//) { print $in,"\n"; }
else # multiple answers
{
$flag = 0;
($rt,$ana) = split(/,/,$in,2); #2 is added to avoid truncation, in case ana
#contains ','.
@ans = split(/\//, $ana);
foreach $ans (@ans)
{
if($ans !~ /[\_%]/) # select non rare one which does not have _s
{
$flag = 1; print $rt,",",$ans,"\n"; last;
}
}
if(!$flag)
{
foreach $ans (@ans)
{
if($ans !~ /%/) # select one which is not rare.
{
$flag = 1; print $rt,",",$ans,"\n"; last;
}
}
}
if(!$flag) # If all are rare, select 1st rare answer
{
print $rt,",",$ans[0],"\n";
}
}
}
