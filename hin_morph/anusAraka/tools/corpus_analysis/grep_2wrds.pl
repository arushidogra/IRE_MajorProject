#!/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/perl-4.019/perl
$/ = ".";
while($in = <STDIN>)
{
if(($in =~ / $ARGV[0] ([^ ]*)/) || ($in =~ / $ARGV[0]$/) || ($in =~ /^$ARGV[0] ([^ ]*)/) || ($in =~ /^$ARGV[0]$/))
  {
   print $ARGV[0]," ",$1,"\n";
  }
}
