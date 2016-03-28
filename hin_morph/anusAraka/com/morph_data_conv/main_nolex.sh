echo preparing offset and feature_value files
cp /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/gen_fe_val_off.c .
cc -g -o gen_fe_val_off.out gen_fe_val_off.c /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/tools/mt/bin/getfileword.o /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/tools/mt/bin/getline.o
./gen_fe_val_off.out
rm gen_fe_val_off.c
#noun_feature_value contains list of noun types & their feature values. This is for Telugu
cat feature_value noun_feature_value >jnk
mv jnk feature_value
sed -e '/^noun_/d
        /^noun/d
        /^adj,/d
        /^adv,/d
        /^avy,/d
        /numeric/d
        /pronoun/d
        /pronoun_/d
        /_pronoun_/d' offset > jnk
cat jnk noun_offset > jnk2
mv jnk2 offset
rm jnk
echo preparing suff_info
cp /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/suff_gen.c .
cc -g -o suff_gen.out suff_gen.c /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/tools/mt/bin/getfileword.o
./suff_gen.out 1
rm suff_gen.c
echo sorting suff_info
sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/suff.sh
echo separating suff and add from other information
sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/feature_value.sh
sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/cat.sh
rm cvt.out
rm gen_fe_val_off.out
rm suff_gen.out
