d=/1d1/mt/tools
cc -c $d/source_code/dir.c
cc -c $d/source_code/recexe.c
mv dir.o $d/bin
mv recexe.o $d/bin
cc -o $d/lib/rex.out $d/bin/recexe.o $d/bin/dir.o
