if($ARGV[0] eq "GDBM"){
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/tools/include/use.pl";
tie(%TGNP,GDBM_File,$ARGV[1],0666,0);
}
else {
dbmopen(TGNP,$ARGV[1],0666);
}
$i=1;
while(<STDIN>)
{
chop();
$TGNP{$_} = $i;
#print $TGNP{$_},$i,"\n";
$i++;
}
if($ARGV[0] eq "GDBM"){ untie(%TGNP);}
else {dbmclose(TGNP);}
