while($in = <STDIN>)
{
chop($in);
$in =~ /([^ 	]*)[ 	](.*)/;
$word = $1;
$word = reverse($word);
print $word," ",$2,"\n";
}
