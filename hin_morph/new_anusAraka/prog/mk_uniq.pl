# $Id: mk_uniq.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
while($in = <STDIN>)
{
chop($in);
($wrd,$mng_lst) = split(/ /,$in);
$ans_mng = "";
if($mng_lst eq "") { $mng_lst = $wrd;}
#print $wrd,"\n",$mng_lst,"\n";
if($mng_lst =~ /\[/) # If multiple answers
{
$mng_lst =~ /(.*)\[(.*)\]/;
$mng1 = $1;
$mng_ar = $2;
if($mng_ar =~ /\//) # If more than 2 answers
{
@mngs = split(/\//,$mng_ar);
foreach $mng (@mngs)
{
if($mng1 ne $mng) { $ans_mng = $ans_mng."/".$mng;}
}
}
elsif ($mng_ar ne $mng1) { 
#print $mng1," ",$mng_ar,"\n";
$ans_mng = $mng_ar;
}
$ans = $mng1;
# next 4 lines : temp put in brackets
if($ans_mng) {
$ans_mng =~ s/^\///;
$ans = $mng1."[".$ans_mng."]";
}
}
else { $ans = $mng_lst;}

print $wrd," ",$ans,"\n";
}
