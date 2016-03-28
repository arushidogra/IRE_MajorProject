echo preparing lex.c
cp /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/convt_t1.c .
cc -g -o cvt.out convt_t1.c /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/tools/mt/bin/getline.o
./cvt.out
rm convt_t1.c
rm convt_t1.o
sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/lex.sh 
echo preparing avy.c
sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/avy.sh
echo preparing offset and feature_value files
cp /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/gen_fe_val_off.c .
cc -g -o gen_fe_val_off.out gen_fe_val_off.c /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/tools/mt/bin/getfileword.o /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/tools/mt/bin/getline.o
./gen_fe_val_off.out
rm gen_fe_val_off.c
echo preparing suff_info
cp /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/suff_gen.c .
cc -g -o suff_gen.out suff_gen.c /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/tools/mt/bin/getfileword.o
./suff_gen.out 1
rm suff_gen.c
cp suff_info suff_info.bak
echo sorting suff_info
sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/suff.sh
echo separating suff and add from other information
sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/feature_value.sh
sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/cat.sh
rm cvt.out
rm gen_fe_val_off.out
rm suff_gen.out
rm gen_fe_val_off.o
#rm suff_gen.o
#rm suff_info
#rm offset
#rm feature_value
