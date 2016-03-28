while($in = <STDIN>)
{
chop($in);
$in =~ s/\/$//;
for($i=0;$i<100;$i++) {$ans[$i] = "z";}
($rt,$ana) = split(/,/,$in,2); #2 is added to avoid the truncation of anas,
# in case it contains ','.
print $rt,",";
if($ana =~ /\+/) { $ana =~ /^(.*)\+(.*)/; $first = $1; $second = $2;$sep = "+";}
else { $first = $ana; $second = "";$sep = "\n";}
$j = 0;
while($j < 2){
if($j == 0) { $ana = $first;}
elsif($j == 1) { $ana = $second;}
if($ana ne ""){
if($ana !~ /\//) { $ana =~ s/^[0-9]_//; print $ana;}
else
{
@ans = split(/\//,$ana);
$k = #$ans;
@ans_srt = sort {$b <=> $a} (@ans);
$ans_srt[0] =~ /^([0-9])_(.*)$/;
$priority = $1;
#print "PRI = ",$priority;
print $2;
for($i=1;$i<$k;$i++) {
#print "SUR = ",$ans_srt[$i];
if($ans_srt[$i] =~ /^($priority)_(.*)$/)
{
$tmp = $2;
print "\/";
print $tmp;
}
}
}
print $sep;
}
$j++;
$sep = "\n";
}
}
