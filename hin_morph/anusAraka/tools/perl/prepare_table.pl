print "Distict words	%Distinct words	Total_words	Coverage\n";
print "############	###############	##########	########\n";
while($in = <STDIN>)
{
$in =~ / = ([0-9]*)$/;
print $1,"		";
$in = <STDIN>;
$in =~ / = ([0-9]*)$/;
print $1,"		";
$in = <STDIN>;
$in =~ / = ([0-9]*)$/;
print $1,"		";
$in = <STDIN>;
$in =~ / = ([0-9]*)$/;
print $1,"\n";
}
