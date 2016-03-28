open(FILE,$ARGV[0]);
while(<FILE>)
{
if($_ !~ / /) { print $.," ",$_;}
elsif($_ =~ /[^ ]* [^ ]* [^ ]*/) { print $.," ",$_;}
}
