if($ARGV[0] eq "GDBM"){
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/tools/include/use.pl";
tie(%LEX,GDBM_File,$ARGV[1],0666,0);
}
else{ dbmopen(LEX,$ARGV[1],0666); }
while(<STDIN>)
{
$_ =~ /"([a-zA-Z_]+)","(.+)"/;
$LEX{$1}=$2;
}
if($ARGV[0] eq "GDBM"){ untie(%LEX); }
else{ dbmclose(LEX); }
