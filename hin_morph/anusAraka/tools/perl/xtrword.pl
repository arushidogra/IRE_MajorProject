# Searches for a given word and extracts it from given files.

$delim = '<.>';
for ($s=0; $s <= $#ARGV; $s++) { # Extract the switches and pattern.
  if (substr($ARGV[$s],0,1) eq '-') {
    if (substr($ARGV[$s],1,1) eq 'd') { # Delimiter specified.
      $delim = substr ($ARGV[$s],2);
    }
    elsif (substr($ARGV[$s],1,1) eq 'n') { # Use new line as delimiter
      $delim = 'n';
    }
    else { print STDERR "xtr.pl: Unrecognized switch: $ARGV[$s]\n"; }
  }
  else { # Switches are over, first arg must be the pattern to be searched. 
    $pat = $ARGV[$s];   last;
  }
}
$s++;
if ($delim ne 'n') { $/ = $delim; } # Else use the default newline setting
# print STDERR "xtr.pl: Delimiter = $/    Pattern = $pat\n";
for ($i = $s; $i<=$#ARGV; $i++) { 
  open (FL, "$ARGV[$i]") || print "Unable to open file $ARGV[$i]\n";
  while (<FL>) {
    if (/\W$pat\W/) {
      if ($delim eq 'n') { print "$ARGV[$i]:$.: $_"; }
      else {  # Do not print line number (with respect to 
              #  the new delimiter other than new line). Beautify.
        s/\n/ /g;
        print "\n$ARGV[$i]: $_"; 
      }
    }
  }
  close (FL);
}

