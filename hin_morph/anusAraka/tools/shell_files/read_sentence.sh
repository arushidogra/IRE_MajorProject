d=/1d1/amba/tools
cc -c -g $d/source_code/get_sentence.c
mv get_sentence.o $d/bin
cc -c -g $d/source_code/read_sentence.c
mv read_sentence.o $d/bin
cc -g -o $d/lib/read_sentence.out $d/bin/get_sentence.o $d/bin/read_sentence.o
