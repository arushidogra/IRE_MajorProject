# $Id: put_cmnts.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
while($in = <STDIN>)
{
chop($in);
$out = "";
@ans = split(/\//,$in);
foreach $ans (@ans)
{
if($ans =~ /(.*)#_(.*)/) { $rt = $1."#"; $tam = "_".$2;}
else { $rt = $ans;$tam = "";}
$rt =~ s/#$//;
if($rt =~ /#/)
{
$rt =~ s/#/\[/;
$rt =~ s/#/\//g;
$rt =~ s/$/\]/;
}
$out = $out."&&".$rt.$tam;
}
$out =~ s/^&&//;
if($out =~ /&&/) { $flag = 1;} else { $flag = 0;}
#$out =~ s/&&/\//;
#$out =~ s/&&/\//g;
if($flag) { $out =~ s/$/&&/;}
print $out,"\n";
}
