use GDBM_File;
print $ARGV[0],"\n";
tie(%LEX,GDBM_File,$ARGV[0],0666,0);
while (($key,$val) = each %LEX) {
                       print $key, ' = ', $val, "\n";
                  }

untie(%LEX);
