require "/usr/local/perl/lib/look.pl";
open(KAN_DICT,$ARGV[0]);
$| = 1;# flush

$word = $ARGV[1]; 
	  $key = "\"".$word;
	  &look(*KAN_DICT,$key,$dict,$fold);
	  $dict_ln = <KAN_DICT>;
	  if($dict_ln ne "")
		{
		while($dict_ln =~ /$key[^"]","/)
		{
		print $dict_ln;
		$dict_ln = <KAN_DICT>;
		}
		}
