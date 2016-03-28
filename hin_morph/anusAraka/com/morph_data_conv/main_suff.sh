cp /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/suff_gen.c .
cc -g -o suff_gen.out suff_gen.c /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/tools/bin/getfileword.o
./suff_gen.out 1
rm suff_gen.c
sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/suff.sh
/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/suff_add_ptr.out

sed '/#define SIZEOF_SUFF/ d' const.h > junk2
sed '/int sizeof_suff/ d' const.c > junk3
cat const3.h junk2 > const.h
cat const3.c junk3 > const.c
rm junk?
