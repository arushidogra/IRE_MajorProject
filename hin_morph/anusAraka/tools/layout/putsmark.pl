# Put beginning and end of sentence (bos) markers in the input text.
# Begin mark: <s30>  -  sentence number 30 begins, etc.
# End mark: <.>  -  end of sentence. (Usual marks in the text: stop, !, ? are also retained.)
sub putsentencemark {
  local ($infile, $outfile) = @_;
  local ($word, $init, $char, $openquote, $sentcount, $quote, $oldfile);
     #print STDERR "Inside putsentencemark\n";
  $oldfile = select ($outfile);
  $quote = "\"\'\`"; # symbols which function as quote marks 
  $deb = 0;  $deb1 = 0;  $debc = 0;
  $openquote = 0;   # quotation not 'on' currently
  $bsl_mode = 0; # If 1, ignore all chars until a single backslash (bsl).
  $printbos = 1;  # $printbos causes printing of bos as early as possible
      # but appropriately (after a newline, opening blanks, bsl material etc.)
  $sentcount = 1;
  while (<$infile>) {
    if (/^\s*$/) { print; next; }  # white line. Do not process it further
    if ($bsl_mode) { $tmp = &consume_till_bsl (); }
    if ($bsl_mode) { # Current line consumed without mode over.
                     # Read next line which will continue consuming. 
      next;
    }
    if ( $printbos ) {      # print in the beginning appropriately.
      if ($deb1) { print "---PRBOS:$_"; }
      $tmp = &consume_bsl_material ();
      if ($bsl_mode) { next; } # Same comment as above.
      # When reaches here, all bsl material consumed.
      print " <s$sentcount> ";  $sentcount++; 
      $printbos = 0;
    }
    while ($_ ne "") {
      if ($deb) { print "Inner loop-1:$_"; }
      if ($bsl_mode) { $tmp = &consume_till_bsl (); }
      if ($bsl_mode) { next; } # Same comment as above.
      if (/[\.\?\xEA\!$quote\\]/) {  # process the line for special symbols
        $init = $`;  $char = $&;  $_ = $';
        if ($deb) { print "Inner loop-2:$init:$char:$_"; }
        print $init;
        if (($char eq "?") || ($char eq "!") || ($char eq "\xEA")) { # sentence ends.
          print $char;
          if ($debc) { print "|Case-1:$char:$_"; }
          if (/^\s*[$quote]/) { # quote mark follows
            if ($openquote) { # this quote mark closes the quotation
              print $&; $_ = $'; $openquote = 0;
            }
            # else { $openquote = 1; } Leave quote.To be consumed later
          }
          print ' <.>';
          $tmp = &try_pr_sentcount ();
        }
        elsif (($char eq "\"") || ($char eq "\'") || ($char eq "\`")) {
          if ($debc) { print "|Case-2:$char:$_"; }
          # $openquote = !($openquote);
          print $char;
          if ( $openquote ) { $openquote = 0;}
          else { $openquote = 1;}
        }
        elsif ($char eq "\\") { # Special symbol possibly.
          if ($debc) { print "|Case-3:$char:$_"; }
          if (/^\\/) { # second '\' therefore not a special symbol.
            print "\\\\";  $_ = substr ( $_, 1);
          }
          else { # Now we know that it is a single bsl.
            $_  =  "\\".$_;
            $tmp = &consume_bsl_material ();
            if ($deb) { print "CONSU..returns:tmp= $tmp"; }
            if ($bsl_mode) { $_ = ""; }
            elsif ($printbos) { 
              print ' <.>';
              &try_pr_sentcount (); 
            }
          }
        }
        elsif ($char eq "\.") {  # End of sentence possibly.
          if ($debc) { print "|Case-4:$char:$_"; }
          print $char;
          if (/^(\s*\.)+/) { # multiple dots follow, not an end of sentnce
            print $&;  $_ = $';
          }
          elsif ($init =~ /(\w+)\s*$/) { # look for word before dot.
            $word = $1;
            if (!( &lang_abbr ($word) )) {  # Dot not preceded by abbrev. 
                                            # End of sentence found.
              # goto QTPR;
              if (/^\s*[$quote]/) { # quote mark follows
                if ($openquote) { # quote mark closes the quotation
                  print $&; $_ = $'; $openquote = 0;
                }
                # else { $openquote = 1; }Leave quote.To be consumed later
              }
              print ' <.>';
              $tmp = &try_pr_sentcount ();
            }
            # else not an end of sentence, do nothing.
          }
          else { # dot closes a sentence. 
            # goto QTPR;
            if (/^\s*[$quote]/) { # quote mark follows
              if ($openquote) { # quote mark closes the quotation
                print $&; $_ = $'; $openquote = 0;
              }
              # else { $openquote = 1; }Leave quote.To be consumed later
            }
            print ' <.>';
            $tmp = &try_pr_sentcount ();
          }
          next;
    QTPR: # Check whether quote mark follows, if yes do appropr.
          if (/^\s*[$quote]/) { # quote mark follows
            if ($openquote) { # quote mark closes the quotation
              print $&; $_ = $'; $openquote = 0;
            }
            else { $openquote = 1; }  # this mark opens a quotation
          }
          print ' <.>';
          $tmp = &try_pr_sentcount ();
        }
      } 
      else {  # No special symbol found in the line.
        if ($debc) { print "|NO SP SYMBOL:$_"; }
        print; $_ = "";
      }
    } # End of second while loop: processing a line
  } # End of first while loop: reading from file
  select ($oldfile);
} # End of putsentencemark procedure.

# Consumes material between backslashes, as much as possible.
# Prints as it goes.
# Returns 0 if unable to consume anything.
sub consume_bsl_material {
  if ($deb) { print "CONSUME_BSL..:$_"; }
  while ($_ ne "") {
    if (/^\s+/) { # opening white space found. Consume.
      print $&; $_ = $';
      if ($deb1) { print "<--printed white spaces:$_"; }
    }
    if (/^\\\\/) { # Two '\' therefore not a special symbol. Exit.
      return (0);  # Failure. Unable to consume anything.
    }
    elsif (/^\\/)  { # else single bsl
      print $&; $_ = $';
      if (/^p\\\s*/) { print $&; $_ = $'; 
                       $openquote = 0;  $printbos = 1; }
      elsif (/^section\\\s*/) { print $&; $_ = $';
                                $openquote = 0;  $printbos = 1; }
      elsif (/^title\\\s*/) { print $&; $_ = $';
                              $openquote = 0;  $printbos = 1; }
      else { 
        $bsl_mode = 1;  $tmp = &consume_till_bsl ();
          # If current line over,but bsl mode on, will be taken
          #  care of appropriately by the calling routine.
        return (1);
      }
    }
    else { return (0); }
  }
  1;
} 

# The following consumes chars in $_ until the end of '\' ignoring
# any special symbols. Prints as it goes.
# Resets the bsl mode off on finding the closing '\', however
#  if none found, it consumes the whole line but leaves the mode on.
sub consume_till_bsl {
  while ($bsl_mode) { # Go past chars until a single '\'
    if (/\\/) { # First '\' found.
      print $`, $&;  $_ = $'; 
      if (/^\\/) { # Second '\'. Do not close the bsl_mode.
        print $&;  $_ = $'; 
      }
      else { # Close the bsl mode. Already printed.
        $bsl_mode = 0;
      }
    }
    else { # No bsl found in this line.
      print;  $_ = ""; last;  # bsl mode will remain on.  
    }
  }
}

# Print now if not end of line, else delay printing to next line.
sub try_pr_sentcount {
  if (!(/^\s*\n/)) { # Something follows in the line.
    print " <s$sentcount> ";  $sentcount++;
    $printbos = 0;
  }
  else { $printbos = 1; }
}


# Looks to see whether the given argument word is an abbreviation.
# Currently checks in a given small array.
# Input arg is the previous word (before dot).
@abbr = ( "Ema", "e", "bI", "EsasI" );
$#abbr = @abbr;
sub lang_abbr {
  local ($word) = @_;
  local ($i);
  if (length($word) == 1) { return (1); }; # Word of single char. Assume abbrev. 
  if ($word =~ /[0-9]+/) { # Probably the fullstop is 
                           # a decimal point in a number.
    return (1);
  }
  for ($i=0; $i <= $#abbr; $i++) {
    if ( $abbr[$i] eq $word ) { return (1); }
  }
  0;  # Not found, return false.
}
1;
