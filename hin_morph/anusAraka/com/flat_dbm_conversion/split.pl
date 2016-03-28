# This program splits the contents ( that are separated by a #) corresopnding to a key

while(<STDIN>)
{
if($_ =~ /"([a-zA-Z_]+)","([a-zA-Z]+)"/) { print $_;}
else
{
$_ =~ /"([a-zA-Z_]+)","([a-zA-Z]+)#(.+)"/;
$key = $1;
print "\"", $1,"\",\"",$2,"\"\n";
$rem = $3;
while($rem ne "")
{
if($rem =~ /([a-zA-Z_]+)#(.*)/) {print "\"", $key,"\",\"",$1,"\"\n"; $rem = $2; }
else {print "\"", $key,"\",\"",$rem,"\"\n"; $rem = ""; }
}
}
}
