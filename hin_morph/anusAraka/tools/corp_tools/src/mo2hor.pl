#! /usr/users/epc003/PERL/perl-4.019/perl
# Takes as its input the output of morph analyser and puts 
# the features for each word in horizontal line.
# Usage: mo2hor.pl <abhi.mo >abhi.moh

local (@catname, @numflds, @fldname);
# Example data structure:
# $catname[0] = v         - name of lexical cat
# $numflds{v} = 3         - number of fields (from 0 to 3)
# $fldname{v,0} = tam     - name of first field 
#    ...
# $fldname{v,3} = person - name of last field 
#     There is also a reverse entry as shown below::
# $fldpos{v,tam} = 0     - position of field
#    ...
# $fldpos{v,person} = 3     - position of field
# $#catname -  number of lexical categories.


  # require ("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/bin/ldstr.pl");
  # &load_struc ("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/bin/struc");
  #     #require ("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/bin/testldstr.pl");
  # &mo2hor (STDIN, STDOUT);

sub mo2hor {
  local ($infile, $outfile) = @_;
  local ($oldfile) = select($outfile);
  local ($i, $col, @values, $sentbegin, $oldlimtr);
  $sentbegin = '';  # Becomes true if the entry read has sentence marker at the end
  $oldlimtr = $/;
  $/ = 'input_word';
  $_ = <$infile>;
  @values = split (/\n/);
  print $values[0], "\n";   # Print the beginning sent no.
  while (<$infile>) {
    if (/^\n+/) { $_ = $'; }  # Remove new lines in the beginning.
    @values = split (/\n/);
    if ($values[$#values] eq 'input_word') { # Not true at the last entry read from file..
      $#values--;  # Decrement so as not to count 'input_word'
    }
    if ($values[$#values] =~ /# s[0-9]+/) { # beginning of sent found
      $sentbegin = $values[$#values];
      $#values--;
    }
    print $values[0], " ";   # print word no.
    for ($col = 1;  $col <= $#values; $col += (3 + $numflds{$values[$col]}) ) {
      if ($values[$col] eq 'AVY') { print '                          '; }
      print $values[$col + 1], '{';   # print root and '{'
      print $values[$col];          # print lex cat name
      for ($i=0;  $i <= $numflds{$values[$col]};  $i++) {
        print ' ', $values[$i+$col+2];
      }
      print "}";
      if ( ($i + $col + 2) <= $#values) { print '|'; } # One more possible lexical entry for the word.
    }
    print "\n";
    if ($sentbegin) { print $sentbegin, "\n";  $sentbegin = ''; }
  }
  select ($oldfile);
  $/ = $oldlimtr;
}  
1;  

