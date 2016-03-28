# Puts end of sentence marker for each sentence (and its associated
# information) in a 3 line output. Info for the next sentence etc.
# will begin from a new line after the eos marker.

$nlmark = $/;
$/ = ' . ';
while (<>) {
  print "$_\n";
  $/ = $nlmark;
  $reml1 = <>;

  $/ = ' . ';
  $l2 = <>; print "$l2\n";
  $len = length ($l2);
  $/ = $nlmark;
  $reml2 = <>;

  $l3 = <>;
  $reml3 = substr ($l3, $len);
  $l3 = substr ($l3, 0, $len);
  if (substr ($l3, $len - 2) eq '  ') { # Beautify.
    $l3 = substr ($l3, 0, $len - 2);
  }
  print "$l3<.>\n";
  $l4 = <>;
  print "$l4";

  if (!( ($reml1 =~ /^\s+$/) &&
       ($reml2 =~ /^\s+$/) &&
       ($reml3 =~ /^\s+$/) )) { # Print remainder if necy.
    print $reml1, $reml2, $reml3, $l4;
  }
  $/ = ' . ';
}
1;
