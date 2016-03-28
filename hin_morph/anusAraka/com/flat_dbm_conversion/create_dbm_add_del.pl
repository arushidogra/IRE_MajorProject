if($ARGV[0] eq "GDBM"){
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/tools/include/use.pl";
tie(%ADD_DEL,GDBM_File,$ARGV[1],0666,0);
}
else{ dbmopen(ADD_DEL,$ARGV[1],0666); }
while(<STDIN>)
{
$_ =~ /"([^"]+)","([^"]+)"$/;
$ADD_DEL{$1} = $2;
}
if($ARGV[0] eq "GDBM"){ untie(%ADD_DEL); }
else {dbmclose(ADD_DEL);}
