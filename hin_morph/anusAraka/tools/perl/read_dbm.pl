
dbmopen(LEX,$ARGV[0],0666);
while (($key,$val) = each %LEX) {
                       print $key, ' = ', $val, "\n";
                  }

dbmclose(LEX);
