#!/usr/bin/perl
# Takes an input file containing the declarations of lexical
# categories and their features from C programming language (with
# double quotes and commas removed, but curly brackets NOT removed).
# And builds an associative structure for use in many perl programs.
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

sub load_struc {
  local($filename) = @_[0];
  local (@strucinfo, $i, $j);
  open (STRUCF, $filename) ||
    die STDERR "Unable to open structure file $filename\n";
  $j = -1;
  $/ = '}';
  while (<STRUCF>) {  # Read a new structure def
    if (/^\s*$/) { next; }    # blank space found not a new struc.
    if (/^\n+/) { $_ = $'; }  # Remove new lines in the beginning.
    if (/\n+$/) { $_ = $`; }  # Remove new lines at the end.
    @strucinfo = split (/\n/);
    if ($strucinfo[0] ne '{') {
      print STDERR "Format of structure not recognized $strucinfo[0], $strucinfo[1],...\n";
      next;
    }
    $j++;
    $catname[$j] = $strucinfo[1]; # Name of the lex cat is stored.
    for ($i = 0;  $i <= ($#strucinfo - 3);  $i++) {
      $fldname{$catname[$j],$i} = $strucinfo[$i + 2];
      $fldpos{$catname[$j],$strucinfo[$i + 2]} = $i;
    }
    $numflds{$catname[$j]} = $i - 1;
  }
  close (STRUCF);
}
1;
