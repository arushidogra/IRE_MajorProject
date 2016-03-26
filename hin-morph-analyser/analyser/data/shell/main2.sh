echo preparing lex.c
cp ../c_data/convt_t2.c .
cc -Wall -g -o cvt.out convt_t2.c ../c_data/getline.c
rm convt_t2.c
./cvt.out
rm cvt.out
rm lex.c
echo preparing avy.c
sh avy.sh
echo preparing offset and feature_value files

cc -Wall -g -o gen_fe_val_off.out ../c_data/gen.c ../c_data/getfileword.c ../c_data/getline.c
./gen_fe_val_off.out --cepath ../pc_data/ --capath ../pc_data/ --fepath ../pc_data/ --mappath ../pc_data/
rm gen_fe_val_off.out
echo preparing suff_info
cp ../c_data/suff_gen.c .
cc -Wall -g -o suff_gen.out ../c_data/suff_gen.c ../c_data/getfileword.c
./suff_gen.out 2
rm suff_gen.out suff_gen.c
cp suff_info suff_info.bak
echo sorting suff_info
sh suff.sh
rm suff_info.bak
echo separating suff and add from other information
sh feature_value.sh
sh cat.sh
rm suff_info
rm offset
rm feature_value
