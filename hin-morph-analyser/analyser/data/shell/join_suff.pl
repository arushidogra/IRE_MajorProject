#!/usr/bin/perl
# This program produces a file with uniq key that is required for dbm 
$in = <STDIN>;
$in =~ /"([a-zA-Z0-9]*)","(.*,)$/;
$prev1 = $1;
$prev2 = $2;
$prev2 =~ s/"//;
while($in = <STDIN>)
{
$cur = "\"".$prev1."\",\"".$prev2;
$in =~ /"([a-zA-Z0-9]*)","(.*,)$/;
$next1 = $1;
$next2 = $2;
$next2 =~ s/"//;
while($prev1 eq $next1) 
{
$cur = $cur."#".$next2;
$in = <STDIN>;
if($in =~ /"([a-zA-Z0-9]*)","(.*,)$/)
{
$next1 = $1;
$next2 = $2;
$next2 =~ s/"//;
}
else { print $cur,"\",\n";exit;}
}
print  $cur,"\",\n";
$cur = "";
$prev1 = $next1;
$prev2 = $next2;
}
print "\"",$next1,"\",\"",$next2,"\",\n";
