
# This program produces a file with uniq key that is required for dbm 
$_ = <STDIN>;
$_ =~ /"([a-zA-Z_0-9\?]+)","([^"]*)"/;

$prev1 = $1;
$prev2 = $2;
$prev2 =~ s/[0-9]\.//;
while(<STDIN>)
{
$cur = "\"".$prev1."\",\"".$prev2;
$_ =~ /"([a-zA-Z_0-9\?]+)","([^"]*)"/;
$next1 = $1;
$next2 = $2;
$next2 =~ s/[0-9]\.//;
while($prev1 eq $next1) 
{
$cur = $cur."#".$next2;
$_ = <STDIN>;
$_ =~ /"([a-zA-Z_0-9\?]+)","([^"]*)"/;
$next1 = $1;
$next2 = $2;
$next2 =~ s/[0-9]\.//;
}
print  $cur,"\"\n";
$cur="";
$prev1 = $next1;
$prev2 = $next2;
}
print "\"",$next1,"\",\"",$next2,"\"\n";
