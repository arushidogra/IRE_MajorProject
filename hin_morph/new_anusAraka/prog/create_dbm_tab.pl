# $Id: create_dbm_tab.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
if($ARGV[0] eq "GDBM"){
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/tools/include/use.pl";
tie(%LEX,GDBM_File,$ARGV[1],GDBM_WRITER,0666);
}
else {dbmopen(LEX,$ARGV[1],0666); }
while($in = <STDIN>)
{
chop($in);
($wrd1,$wrd2) = split(/	/,$in,2); #2 is added to avoid the truncation of
#wrd2, in case it contains ','.
if($wrd2 eq "") { $wrd2 = $wrd1;}
$LEX{$wrd1} = $wrd2;
}
if($ARGV[0] eq "GDBM") { untie(%LEX);}
else {dbmclose(LEX);}
untie(%LEX);
