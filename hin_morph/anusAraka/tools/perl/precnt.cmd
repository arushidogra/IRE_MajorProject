#! /usr3/amba/perl-4.019/perl
# Counts prefixes or suffixes in a given list of sorted words.
# Usage: precnt.cmd -r INFILE OUTFILE
#   -r indicates reverse the suffixes.
# (Note revflag does not work with second pass.)
# See precnt.pl for details.

require ("/usr3/amba/amba/tools/perl/precnt.pl");

# Assumes that the args begin after the params. (Each param begins by -)
local ($i, $parmlastpos, $argbegpos);
$parmlastpos = -1; # Gives pos of last param in ARGV. Default no params.
$argbegpos = -1;  # Gives position of 1st argument in ARGV. Default no args
for ($i=0; $i <= $#ARGV; $i++) { # Extract the parameters and locate
                                 #  starting loc of command args.
  if (substr($ARGV[$i],0,1) eq '-') {  # A parameter found.
    $parmlastpos++;  # Change the following lines to suit your needs.
    if (substr($ARGV[$i],1,1) eq 'r') { # use suffix.
      $revflag = 1;
      $dval = substr ($ARGV[$i],2);
    }
    else { print STDERR "Unrecognized param: $ARGV[$i]. Ignoring.\n"; }
     ##elsif (substr($ARGV[$i],1,1) eq 'n') { # set switch n to true.
     ##  $nswitch = 1;
     ##}
  }
  else { # Argument found. Parameters end.
    $argbegpos = $i;
    last;
  }
}
#print STDERR "DEB params end: $parmlastpos;  args begin: $argbegpos; total: $#ARGV;\n";

# Process the arguments in the command line then call precount.
# 1. Can be used as a filter. OR
# 2. file args can be given instead of filters.

if ($argbegpos < 0) { # No args.
  &precount(STDIN, STDOUT);
}
elsif (($#ARGV - $argbegpos) == 0) { # Only one arg given. Execute the command with arg and stdout.
  open (INFILE, "$ARGV[$argbegpos]") ||
     die STDERR "Unable to open file $ARGV[$argbegpos]\n" ;
  &precount(INFILE, STDOUT);
  close (INFILE);
}
elsif (($#ARGV - $argbegpos) == 1) { # Two args given. Execute the command with arg1 and arg2.
  open (INFILE, "$ARGV[$argbegpos]") ||
     die STDERR "Unable to open input file $ARGV[$argbegpos]\n" ;
  open (OUTFILE, ">$ARGV[$argbegpos + 1]") ||
     die STDERR "Unable to open output file $ARGV[$argbegpos + 1]\n" ;
  &precount(INFILE, OUTFILE);
  close (OUTFILE);
  close (INFILE);
}
else { print STDERR "Too many arguments.\n"; }

