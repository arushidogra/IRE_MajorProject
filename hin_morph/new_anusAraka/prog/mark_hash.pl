# $Id: mark_hash.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
while($in = <STDIN>)
{
$in =~ s/ ([^OLF][^UWR][^TGZ])/ #\1/g;
$in =~ s/^([^OLF][^UWR][^TGZ])/#\1/g;
print $in;
}
