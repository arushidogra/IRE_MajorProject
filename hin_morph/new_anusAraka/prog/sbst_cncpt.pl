open(TMP,"<tlg.cncpt");
$i = 0;

while($in = <TMP>){
($rt[$i],$cncpt[$i]) = split(/\t/,$tmp);
$i++;
}
close(TMP);

while($in = <STDIN>){
if($in =~ /./){
	while($in =~ /([^#]*
}
else { print "\n";}
