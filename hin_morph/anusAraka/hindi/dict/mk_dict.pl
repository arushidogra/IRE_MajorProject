while($in = <STDIN>)
{
chop($in);
$in =~ /^"([^"])",(.*)$/;
$wrd = $1;
$rem = $2;
print $in,"\"",$1,"\",\"d_rekha\",\n";
}
