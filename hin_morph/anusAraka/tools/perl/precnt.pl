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
# It also works with the second pass in which
# the summary file has been used to strip the
# original file using: strip.pl  FILE.sum <FILE >FILE2
# Now it can be run again:  precnt.cmd <FILE2  >FILE2.sum
# The overall summary of prefixes is the union of *.sum files.
# (The reverse flag does not work with the second pass.)
sub precount {
  local ($infile, $outfile) = @_;
  local ($word, $freq, $curpref, $cumfreqcnt, $wrdcnt, $i, $temp, $frozenpre);
  if (!($_ = <$infile>)) {
    print STDERR "File is empty.\n"; 
    return (0);
  }
  if (/^\s+/) { $_ = $'; }  # Remove opening space.
  if (/\s+$/) { $_ = $`; }  # Remove ending space.
  $oldpre = '';
  ($word, $freq, $frozenpre) =  split (/\s+/);
  if ($freq eq '') { print STDERR "Freq not found:$word:\n"; }
  if ($revflag) { $word = reverse ($word); }
  #print STDERR "$word, $freq\n";   #for debugging

  $curpref =  $word;  $cumfreqcnt = $freq;  $wrdcnt = 1;
  while (<$infile>) {
    if (/^\s+/) { $_ = $'; }  # Remove opening space.
    if (/\s+$/) { $_ = $`; }  # Remove ending space.
    $oldpre = $frozenpre;
    ($word, $freq, $frozenpre) =  split (/\s+/);
    if ($freq eq '') { print STDERR "Freq not found:$word:\n"; }
    if ($revflag) { $word = reverse ($word); }
    #print STDERR "$word, $freq\n";   #for debugging
    $len = length ($curpref);
    #print STDERR "curpref :$curpref:,  word :$word:, frozenpre :$frozenpre:\n"; # for debugging
    for ($i=0;  $i <= ($len - 1);  $i++) {
      #print STDERR "$curpref, $cumfreqcnt, $wrdcnt\n";  # for debugging
      if (substr ($curpref, $i, 1) ne substr ($word, $i, 1)) {
        #if ($wrdcnt > 1) {
         if ($revflag) {
          $temp = reverse($curpref);
          print $outfile "$temp\t$cumfreqcnt\t$wrdcnt\n";
         }
         else { print $outfile "$oldpre$curpref\t$cumfreqcnt\t$wrdcnt\n";}
        #}
        last;
      }
    }
    if ($i == $len) {  # Prefix of the same size found.
      $cumfreqcnt += $freq;    $wrdcnt++; 
    }
    elsif ($i == 0) {  # No match at all. Set the new cur prefix.
      $curpref = $word;  $cumfreqcnt = $freq;  $wrdcnt = 1;
    }
    else {  # Prefix becomes smaller.
      $curpref = substr ($curpref, 0, $i);
      $cumfreqcnt +=  $freq;
      $wrdcnt++;
    }
  }  # End of while loop.
  #if ($wrdcnt > 1) {
   if ($revflag) {
    $temp = reverse($curpref);
    print $outfile "$temp\t$cumfreqcnt\t$wrdcnt\n";
   }
   else { print $outfile "$oldpre$curpref\t$cumfreqcnt\t$wrdcnt\n";}
  #}
}
1;
