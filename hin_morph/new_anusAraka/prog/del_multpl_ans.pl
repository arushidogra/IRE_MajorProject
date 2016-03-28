# $Id: del_multpl_ans.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
while($in = <STDIN>)
{
chop($in);
$in =~ s/\/$//;
$in =~ s/\/[^_]*_lelyA[^\/]*//g;
$in =~ s/,[^_]*_lelyA[^\/]*\//,/;
print $in,"\n";
}
