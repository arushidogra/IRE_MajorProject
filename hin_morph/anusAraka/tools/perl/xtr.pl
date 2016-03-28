# Searches for a given pattern and extracts it from given files.
# Usage: xtrct.pl pattern [-dn] infilename >outfilename
#  Option -dxyz indicates that xyz should be used as text line end mark.
#         -dn indicates use of new line as end marker.

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
    if (/$pat/) {
      if ($delim eq 'n') { print "$ARGV[$i]:$.: $_"; }
      else {  # Do not print line number (with respect to 
              #  the new delimiter other than new line). Beautify.
        #s/\n/ /g; # put in comments by AMBA
        print "\n$pat\n$ARGV[$i]: $_"; 
        print "\n"; # introduced by AMBA
      }
    }
  }
  close (FL);
}

