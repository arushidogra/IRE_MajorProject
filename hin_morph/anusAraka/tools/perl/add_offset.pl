while($in=<STDIN>)
{
if($in =~/^w([0-9]*) (.*)$/)#This chk is added to eat up a line input_word ehilch occurs as the 1st line in the hori o/p
{
$word_num=$1+$ARGV[0];
print "w",$word_num," ",$2,"\n";
}
}
