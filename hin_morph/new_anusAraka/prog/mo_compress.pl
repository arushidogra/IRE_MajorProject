# $Id: mo_compress.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
while($in = <STDIN>)
{
chop($in);
$in =~ s/\/$//;
for($i=0;$i<100;$i++) {$ans[$i] = "z";}
($rt,$ana) = split(/,/,$in,2); #2 is added to avoid the truncation of anas,
# in case it contains ','.
print $rt,",";
if($ana eq "") { print "^^^\n";break;}
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
@ans = split(/\//,$ana);
$k = #$ans;
@ans_srt = sort(@ans);
print $ans_srt[0];
for($i=1;$i<$k;$i++) {
if($ans_srt[$i] ne $ans_srt[$i-1])
{
print "\/";
print $ans_srt[$i];
}
}
}
print $sep;
}
$j++;
$sep = "\n";
}
}
