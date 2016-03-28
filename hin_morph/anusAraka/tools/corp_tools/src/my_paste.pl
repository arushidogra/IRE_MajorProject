open(FL1,$ARGV[0]);
open(FL2,$ARGV[1]);
while(!eof(FL1) && !eof(FL2))
{
$in1=<FL1>;
chop($in1);
print $in1,"	";
$in2=<FL2>;
print $in2;
}
if(eof(FL1))
{
print "EOF $ARGV[0]\n";
while(!eof(FL2))
{
$in2=<FL2>;
print $in2;
}
}
elsif(eof(FL2))
{
print "EOF $ARGV[1]\n";
while(!eof(FL1))
{
$in1=<FL1>;
print $in1;
}
}
