cp /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/convt_t1.c .
cc -g -o cvt.out convt_t1.c /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/tools/mt/bin/getline.o
./cvt.out
rm convt_t1.c
sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/lex.sh

sed '/#define SIZEOF_LEX/ d' const.h > junk0 
sed '/int sizeof_lex/ d' const.c > junk1
cat const1.h junk0 > const.h
cat const1.c junk1 > const.c
rm const?.h
rm const?.c
rm junk?
