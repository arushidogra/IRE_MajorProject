d=/1d1/amba/tools
cc -c -g $d/source_code/get_gen_snt.c
mv get_gen_snt.o $d/bin
cc -c -g $d/source_code/read_snt.c
mv read_snt.o $d/bin
cc -g -o $d/lib/read_gen_snt.out $d/bin/get_gen_snt.o $d/bin/read_snt.o

