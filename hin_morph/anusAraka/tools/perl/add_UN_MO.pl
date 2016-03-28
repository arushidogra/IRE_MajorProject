while($in = <STDIN>)
{
chop($in);
$in =~ s/([0-9]*) [^ ]*\tw[0-9]* (.*)/\1 /;
$word = $2;
if($word ne "") { $in = $in."MO\n";}
if($word eq ""){ $in = $in."UN\n";}
print $in;
}
