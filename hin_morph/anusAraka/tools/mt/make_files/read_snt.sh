d=/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/tools/mt
cc -c -g $d/source_code/get_snt.c
mv get_snt.o $d/bin
cc -c -g $d/source_code/read_snt.c
mv read_snt.o $d/bin
cc -g -o $d/lib/read_snt.out $d/bin/get_snt.o $d/bin/read_snt.o
