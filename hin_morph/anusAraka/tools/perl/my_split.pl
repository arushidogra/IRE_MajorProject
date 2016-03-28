$i=1;
$filename=">f2".$i;
print $filename,"\n";
while(1)
{
$count=0;
open(OUT,$filename);
print $filename,"\n";
while($count < $ARGV[0])
{
if($in = <STDIN>)
{
print OUT $in;
$count++;
}
else
{
exit;
}
}
close(OUT);
$i++;
$filename=">f2".$i;
}
