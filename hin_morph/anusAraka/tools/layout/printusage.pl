sub printusage {
  local ($filename) = @_;
  local ($oldlimtr);
  open (USAGE, $filename) ||
    die "Unable to open file $filename and show usage help.\n";
  print STDERR "--- Help for the command in file $filename:::\n";
  $oldlimtr = $/;
  $/ = "\12";
  while (<USAGE>) {
    if (/^\#/) {
      # print STDERR "DEBUG if:--$_--\n";
      if (!(/^\#\!/)) { print STDERR $_; }
    }
    else { last; }
  }
  $/ = $oldlimtr;
}
1;
