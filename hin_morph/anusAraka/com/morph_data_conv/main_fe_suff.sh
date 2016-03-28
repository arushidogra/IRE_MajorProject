cp /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/gen_fe_val_off.c .
cc -g -o gen_fe_val_off.out gen_fe_val_off.c /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/tools/mt/bin/getfileword.o /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/tools/mt/bin/getline.o
./gen_fe_val_off.out 1
rm gen_fe_val_off.c
#nf_mapfile contains list of non finite tams & their feature values. This is only for kannada
cat feature_value nf_mapfile >jnk
mv jnk feature_value

cp /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/suff_gen.c .
cc -g -o suff_gen.out suff_gen.c /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/tools/mt/bin/getfileword.o
./suff_gen.out 1
rm suff_gen.c
sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/suff.sh
/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/suff_add_ptr.out

sed '/#define SIZEOF_SUFF/ d' const.h > junk2
sed '/int sizeof_suff/ d' const.c > junk3
cat const3.h junk2 > const.h
cat const3.c junk3 > const.c
rm junk?
