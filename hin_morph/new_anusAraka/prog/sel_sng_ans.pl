# $Id: sel_sng_ans.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
# Here the answer is selected if it is single one.
while($in = <STDIN>)
{
chop($in);
# in case of single ans print it
if($in !~ /[\[\/\(&]/)
{
$in =~ s/,/,1_/;
}
print $in,"\n";
}
