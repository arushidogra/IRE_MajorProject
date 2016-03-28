#!/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/perl-4.019/perl
# Removes the prefix as specified by the input file sample
#   and produces theoutput file sample.2.
# Usage: strip.pl  sample.sum  <sample  >sample.2
#  where 'sample' is a sorted file, sample.sum is generated
#  by the following command:  precnt.cmd <sample >sample.sum

open (PRESUMM, "$ARGV[0]") ||
  die STDERR "Unable to open file $ARGV[0]\n";

$pref_1 = '';  $wrdcnt_1 = 0;
while (<PRESUMM>) {
    #print STDERR "Read summary: $_";
  ($pref, $cumfreqcnt, $wrdcnt) = split (/\s+/);
    #print STDERR "$pref, $cumfreqcnt, $wrdcnt,\n";
  if ($pref_1 =~ /^$pref/) {  $remwrdcnt = $wrdcnt - $wrdcnt_1; }
  else { $remwrdcnt = $wrdcnt; }

  for ($i=1;  $i <= $remwrdcnt;  $i++) {
    $wrdfreq = <STDIN>;
    ($word, $freq) = split (/\s+/, $wrdfreq);
    if ($word =~ /^$pref/) {
      if ($' ne '') { print "$'\t$freq\t$pref\n"; }
    }
    else { print STDERR "No prefix match found. File mismatch. $wrdfreq\n"; }
  }
  $pref_1 = $pref;  $wrdcnt_1 = $wrdcnt;
}
 
close (PRESUMM);
