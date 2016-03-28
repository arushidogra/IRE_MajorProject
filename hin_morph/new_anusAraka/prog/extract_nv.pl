# $Id: extract_nv.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
while($in = <STDIN>)
{
($wrd,$ana) = split(/,/,$in,2); # 2 is added to avoid truncation, in case
# ana conitans ','.
@ana = split(/\//,$ana);
$noun = 0;
$verb = 0;
$ind = 0;
foreach $ans (@ana)
{
if($ans =~ /{n/) { $noun = 1;}
elsif($ans =~ /{v/) { $verb = 1;}
elsif($ans !~ /{/) { $ind = 1;}
}
if(($noun || $ind) && $verb) { print "NV ",$in;}
else { print $in;}
}
