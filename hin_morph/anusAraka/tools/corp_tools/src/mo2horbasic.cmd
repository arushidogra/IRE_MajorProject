#!/usr3/amba/PERL/perl-4.019/perl
# Takes the morph output (in vert format) from anusaraka system and 
# changes it to horizontal form.(Each word and its associated info 
# appears in a line.)

require ("/usr3/amba/anusAraka/tools/corp_tools/src/ldstr.pl");
require("/usr3/amba/anusAraka/tools/corp_tools/src/mo2horbasic.pl");

# Assumes that the args begin after the params. (Each param begins by -)
local ($i, $parmlastpos, $argbegpos, $arg, $suff);
$parmlastpos = -1; # Gives pos of last param in ARGV. Default no params.
$argbegpos = -1;  # Gives position of 1st argument in ARGV. Default no args
$suff = 'h'; # Default suffix for output file if necessary.
for ($i=0; $i <= $#ARGV; $i++) { # Extract the parameters and locate
                                 #  starting loc of command args.
  if (substr($ARGV[$i],0,1) eq '-') {  # A parameter found.
    $parmlastpos++;  # Change the following lines to suit your needs.
    if (substr($ARGV[$i],1,1) eq 's') { # Suffix for output file names.
       $suff = substr ($ARGV[$i],2);
    }
    else { print STDERR "Parameter not recognized $ARGV[$i]. Ignoring.\n"; }
     ##elsif (substr($ARGV[$i],1,1) eq 'd') { # type of param is d, get val
     ##  $dval = substr ($ARGV[$i],2);
     ##}
     ##elsif (substr($ARGV[$i],1,1) eq 'n') { # set switch n to true.
     ##  $nswitch = 1;
     ##}
     ##else { print STDERR "Unrecognized param: $ARGV[$i]\n"; }
  }
  else { # Argument found. Parameters end.
    $argbegpos = $i;
    last;
  }
}
#print STDERR "DEB params end: $parmlastpos;  args begin: $argbegpos; total: $#ARGV;\n";

# Process the arguments in the command line then call mo2hor.
# 1. Can be used as a filter. OR
# 2. If one or more file arguments are given, they are treated as
#    inputs files, and the output file name is given
#    by the input file name suffixed by 'h' (default can be changed).

if ($argbegpos < 0) { # No args.
  &load_struc ("/usr3/amba/anusAraka/tools/corp_tools/src/struc");
  &mo2hor(STDIN, STDOUT);
}
else { # Call the program with each arg. 
  for ($arg = $argbegpos; $arg <= $#ARGV; $arg++) {
    if (!(open (INFILE, "$ARGV[$arg]"))) {
      print STDERR "Unable to open file $ARGV[$arg]\n" ;
      next;
    }
    if (!(open (OUTFILE, ">$ARGV[$arg]$suff"))) {
      print STDERR "Unable to open out file $ARGV[$arg]$suff\n";
      close (INFILE);
      next;
    }
    &load_struc ("/usr3/amba/anusAraka/tools/corp_tools/src/struc");
    &mo2hor (INFILE, OUTFILE);
    close (INFILE);
    close (OUTFILE);
  }
}

