# $Id: map_compress.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
while($in = <STDIN>)
{
chop($in);
$in =~ s/\/$//;
($rt,$anas) = split(/,/,$in,2); # 2 is added to avoid further truncation,
# if anas contains ','.
print $rt,",";
#print "DEBUG",$anas,",";
@ana = split(/\//,$anas);
foreach $ana (@ana)
{
if($ana =~ /#/)
{
if($ana =~ /#_/)
{
$ana =~ /(.*)#_(.*)/;
$rt = $1."#";
$tam = "_".$2;
}
else {$rt = $ana;$tam = "";}
for($i=0;$i<100;$i++) {$ans[$i] = "z";}
@ans = split(/#/,$rt);
$k = #$ans;
@ans_srt = sort(@ans);
for($i=0;$i<$k;$i++) {
if($ans_srt[$i] ne $ans_srt[$i-1]) {
print $ans_srt[$i],"#";
}
}
if($tam) { print $tam;}
}
else { print $ana;}
print "/";
}
print "\n";
}
