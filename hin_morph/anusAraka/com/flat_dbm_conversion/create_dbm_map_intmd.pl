use GDBM_File;
tie(%LEX,GDBM_File,$ARGV[0],0666,0);
while(<STDIN>)
{
($wrd,$frz,$anu,$map) = (/	/,$_);
$LEX{$frz}=$map;
print $frz "= ",$LEX{$frz},"\n";
}
untie(%LEX);
