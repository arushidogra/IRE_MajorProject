$sum = 0;
while($in = <STDIN>)
{
$in =~ /^([0-9]*) /;
$sum = $sum + $1;
}
print $sum," ",$sum/30000,"\n";
