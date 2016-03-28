#! /usr/users/epc003/PERL/perl-4.019/perl
# Counts the prefixes occuring in a file containing
# sorted words with their frequencies.
# If $revword flag is set does the same thing for reverse sorted
# suffixes.
# Usage:  precnt.cmd <FILE  >FILE.sum
# Example input file FILE:
#   fedcbahx   30
#   fescbaaaaaaaa   40
#   fxdcba   25
#   ledgrphgu   300
#   ledkba   24
#   lfbaferhg   201
# Ans FILE.sum:
#   fe   70
#   f   95
#   le   324
#   l   525
sub prefixcount {
  local ($infile, $outfile) = @_;
  local ($word, $freq, $curpref, $cumfreqcnt, $wrdcnt, $i, $temp, $frozenpre);
  if (!($_ = <$infile>)) {
    print STDERR "File is empty.\n"; 
    return (0);
  }
  if (/^\s+/) { $_ = $'; }  # Remove opening space.
  if (/\s+$/) { $_ = $`; }  # Remove ending space.
  ($freq, $word) =  split (/\s+/);
  if ($freq eq '') { print STDERR "Freq not found:$word:\n"; }
  #print STDERR "$word, $freq\n";   #for debugging

  $curpref =  $word;
  $len = length ($curpref);
  for($i = 0; $i<=$len ; $i++)
  {
  $pref[$i] = substr($word,0,$i);
  $cumfreqcnt[$i] = $freq;
  $cum_wrd_cnt[$i] = 1;
  }
  $wrdcnt = 1;
  $top = $len;
  while (<$infile>) {
    if (/^\s+/) { $_ = $'; }  # Remove opening space.
    if (/\s+$/) { $_ = $`; }  # Remove ending space.
    ($freq, $word) =  split (/\s+/);
    if ($freq eq '') { print STDERR "Freq not found:$word:\n"; }
    #print STDERR "$word, $freq\n";   #for debugging
    $len = length ($curpref);
    #print STDERR "curpref :$curpref:,  word :$word:, frozenpre :$frozenpre:\n"; # for debugging
    for ($i=0;  $i <= $len;  $i++) {
      #print STDERR "$curpref, $cumfreqcnt, $wrdcnt\n";  # for debugging
      if (substr ($curpref, $i, 1) ne substr ($word, $i, 1)) {
          for($j = $top ; $j > $i ; $j--) {
          if($cum_wrd_cnt[$j] != 1){
          print $outfile "$pref[$j]\t$cumfreqcnt[$j]\t$cum_wrd_cnt[$j]\n";
}
          $cumfreqcnt[$j] = 0;
          $cum_wrd_cnt[$j] = 0;
          $pref[$j] = "";
          }
        last;
      }
    }
      $curpref =  $word;
  	$len = length ($curpref);
  	for($i = 0 ; $i<=$len ; $i++)
  	{
  	$pref[$i] = substr($word,0,$i);
  	$cumfreqcnt[$i] += $freq;
        $cum_wrd_cnt[$i] +=  1;
  	}
  	$top = $len;
      $wrdcnt++;
  }  # End of while loop.
          for($j = $top ; $j > 0 ; $j--) {
          if($cum_wrd_cnt[$j] != 1){
          print $outfile "$pref[$j]\t$cumfreqcnt[$j]\t$cum_wrd_cnt[$j]\n";
}
          $cumfreqcnt[$j] = 0;
          $cum_wrd_cnt[$j] = 0;
          $pref[$j] = "";
          }
}
1;
