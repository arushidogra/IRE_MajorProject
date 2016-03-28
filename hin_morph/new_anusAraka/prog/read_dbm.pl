# $Id: read_dbm.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
if($ARGV[0] eq "GDBM"){
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/tools/include/use.pl";
tie(%DB_STORY,GDBM_File,"story_wrds",GDBM_READER,0666);
}
else { dbmopen(DB_STORY,"story_wrds",0666); }
while($in = <STDIN>)
{
chop($in);
print $DB_STORY{$in};
}
if($ARGV[0] eq "GDBM"){
untie(%DB_STORY);
}
else { dbmclose(DB_STORY);}
