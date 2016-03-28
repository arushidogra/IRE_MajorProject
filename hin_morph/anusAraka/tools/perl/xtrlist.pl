# Searches for words given in a file and extracts them from given files.
# (The words are given in the file find.lst, one word per line.)

open (LST, "find.lst") || die "Unable to open file find.lst\n";
$j = 0;
while (<LST>) { # Read in the words to be matched in an array @words.
  if (/^\s+/) { $_ = $'; }  # Remove starting blanks.
  if (/\s+$/) { $_ = $`; }  # Remove trailing blanks.
  ($words[$j], $fnames[$j]) = split($_);  
  $j++;
  open ( 

}

for ($i =1; $i<=$#ARGV; $i++) { # Do for each file.
  open (FL, "$ARGV[$i]") || print "Unable to open file $ARGV[$i]\n";
  while (<FL>) {
    for ($j =1; $j<=$#ARGV; $j++) {  # Do for each word to be matched.
      select ($fileout[$j]);
      if (/$words[$j]/) {
        print "$ARGV[$i]:$.: $_";
      }
    }
  }
  close (FL);
}

