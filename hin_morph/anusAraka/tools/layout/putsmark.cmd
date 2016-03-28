#!/usr3/amba/perl-4.019/perl
# Put beginning and end of sentence (bos) markers in the input text.
#   Example Usage: putsmark.cmd  <abc >abc.sm
# Begin mark: <s30>  -  sentence number 30 begins, etc.
# End mark: <.>  -  end of sentence. (Usual marks in the text: stop, !, ? are also retained.)
# cmd type many to many. (Differs from putsmark2.cmd which is M to 1)

require ("/usr3/amba/anusAraka/tools/layout/putsmark.pl");
require ("/usr3/amba/anusAraka/tools/layout/printusage.pl");


# Assumes that the args begin after the params. (Each param begins by -)
local ($i, $parmlastpos, $argbegpos, $arg, $suff, $argsinfile);
$parmlastpos = -1; # Gives pos of last param in ARGV. Default no params.
$argbegpos = -1;  # Gives position of 1st argument in ARGV. Default no args
$argsinfile = 0;  # Default args file names are not in a file.
$suff = '.sm'; # Default suffix for output file if necessary.
for ($i=0; $i <= $#ARGV; $i++) { # Extract the parameters and locate
                                 #  starting loc of command args.
  if (substr($ARGV[$i],0,1) eq '-') {  # A parameter found.
    $parmlastpos++;  # Change the following lines to suit your needs.
    if (substr($ARGV[$i],1,1) eq 'h') { # print help info.
      &printusage ('/usr3/sangal/tools/src/corp/putsmark.cmd');
      die;
    }
    elsif (substr($ARGV[$i],1,1) eq 's') { # Suffix for output file names.
       $suff = substr ($ARGV[$i],2);
    }
    else { print STDERR "Parameter not recognized $ARGV[$i]. Ignoring.\n";
      &printusage ('/usr3/sangal/tools/src/corp/putsmark.cmd');
    }
  }
  else { # Argument found. Parameters end.
    if (substr($ARGV[$i],0,1) eq '@') {  # A file list found
      $argsinfile = 1;
      $ARGV[$i] = substr($ARGV[$i], 1);
    }
    $argbegpos = $i;
    last;
  }
}
#print STDERR "DEB params end: $parmlastpos;  args begin: $argbegpos; total: $#ARGV;\n";

# Process the arguments in the command line then call putsentencemark.
# 1. Can be used as a filter. OR
# 2. If one or more file arguments are given, they are treated as
#    inputs files, and the output file name is given
#    by the input file name suffixed by '.sm' (default can be changed).

if ($argbegpos < 0) { # No args.
  &putsentencemark (STDIN, STDOUT);
}
elsif ($argsinfile) {  # Args in file.
  open (ARGFILE, "$ARGV[$argbegpos]") ||
    die STDERR "Unable to open args file $ARGV[$argbegpos]\n" ;
  while (<ARGFILE>) { # Read args.
      #print STDERR "Got arg name: $_";
    chop;
    if (!(open (INFILE, $_))) {
      print STDERR "Unable to open file $_\n" ;
      next;
    }
    if (!(open (OUTFILE, ">$_$suff"))) {
      print STDERR "Unable to open out file $_$suff\n";
      close (INFILE);
      next;
    }
    &putsentencemark (INFILE, OUTFILE);
    close (INFILE);
    close (OUTFILE);
  }
  close (ARGFILE);
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
    &putsentencemark (INFILE, OUTFILE);
    close (INFILE);
    close (OUTFILE);
  }
}

