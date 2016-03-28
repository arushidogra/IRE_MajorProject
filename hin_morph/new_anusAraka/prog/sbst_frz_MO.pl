use GDBM_File;
tie(%LEX,GDBM_File,$ARGV[0],GDBM_READER,0644);
while($in = <STDIN>)
{
chop($in);
if($LEX{$in}) { 
print $in,",",$LEX{$in},"\n";
}
else {print $in,",\n";}
}
untie(%LEX);
