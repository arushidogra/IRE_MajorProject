# $Id: factor.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
#This is to factorise X from X[X_]
# X[X_] -> X[_]
while($in = <STDIN>)
{
#$in =~ s/\b([^\[]*)\[\1_\]\b/\1\[_\]/g; # Why this does not work?
$in =~ s/([^\[]*)\[\1_\]/\1\[_\]/g;
$in =~ s/([^\[]*)\/\1\-/\1\[-\]/g;
print $in;
}
