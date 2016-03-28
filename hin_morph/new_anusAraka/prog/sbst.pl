# $Id: sbst.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
use GDBM_File;
tie(%LEX,GDBM_File,$ARGV[0],GDBM_READER,0644);
while($in = <STDIN>)
{
$in =~ s/OUT/#/g;
$in =~ s/LWG/#/g;
$in =~ s/FRZ/#/g;
#while($in =~ /([ 	^\n]*)([^ 	^\n]*)/g)
while($in =~ /([ 	_#^\n]*)([^#]*)/g)
{
$spc = $1;
$ana = $2;
if($ana !~ /{[nPv]=/) { print $spc,$ana;}
else
{ 
#$ana =~ s/^#_//;
#$ana =~ s/_#$//;
$ana =~ s/_$//;
$ana =~ s/^_//;
#print "3",$ana,"\n";
if($LEX{$ana}) { 
#print $spc,"#_",$LEX{$ana},"_#";
print $spc,$LEX{$ana},"_";
}
else{
#print $spc,"#_",$ana,"_#";
print $spc,$ana,"_";
}
}
#print "\n";
}
}
untie(%LEX);
