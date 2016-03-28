# $Id: rm_rare_ans1.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
#All the rare answers from the square brackets are removed
while($in = <STDIN>)
{
chop($in);
($rt,$ana) = split(/,/,$in,2); #2 is added to avoid truncation of ana, in case
# ana contains ','.
if($ana !~ /\//) { print $in,"\n"; }
else
{
#print $rt,",";
if($ana =~ /\+/) { $ana =~ /^(.*)\+(.*)/; $first = $1; $second = $2;$sep = "+";}
else { $first = $ana; $second = "";$sep = "\n";}
$j = 0;
while($j < 2){
if($j == 0) { $ana = $first;}
elsif($j == 1) { $ana = $second;}
if($ana ne ""){
if($ana !~ /\//) { print $ana;}
else
{
$ana =~ /^([^\/]*)\/(.*)$/;
#$out = $1."[";
$out = $1;
$in = $2;
$rem = $3;
@ans = split(/\//, $in);
foreach $ans (@ans)
{
if($ans !~ /%/) { $out = $out."/".$ans;}
}
#$out =~ s/$/\]/;
#$out =~ s/\[\//\[/;
#$out =~ s/\[\]//;
$out =~ s/^\///;
print $rt,",",$out,$rem;
} 
print $sep;
}
$j++;
$sep = "\n";
}
}
}
