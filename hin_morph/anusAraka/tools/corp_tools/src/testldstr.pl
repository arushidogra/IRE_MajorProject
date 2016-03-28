#! /usr/users/epc003/PERL/perl-4.019/perl
# Tests the loading of lexical structures in mem. Prints out what
#  has been loaded.
require ("/usr/users/epc003/sangal/tools/src/corp/ldstr.pl");

&load_struc ("/usr/users/epc003/sangal/tools/src/corp/struc");
# Now print the structure loaded.
for ($i=0; $i <= $#catname;  $i++) {
  print STDERR $catname[$i], ': ', $numflds{$catname[$i]}, ':: ';
  for ($j=0;  $j <= $numflds{$catname[$i]};  $j++) {
    print  STDERR $fldname{$catname[$i], $j};
    print  STDERR '(', $fldpos{$catname[$i],$fldname{$catname[$i], $j}}, ')', ",";
  }
  print STDERR "\n";
}
1;
