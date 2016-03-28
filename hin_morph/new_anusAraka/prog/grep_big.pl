while($in = <STDIN>){
$in =~ /^(.*),(.*)/;
if(length($2) > 70) { print $in;}
}
