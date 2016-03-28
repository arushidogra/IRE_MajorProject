sort -u lex.c > sorted
rm lex.c
wc -l sorted > junk0
sed -e 's/^[ ]*//
        s/[A-Za-z].*$//' junk0 >> junk1
cat /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/lex.head sorted  /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/tail > lex.c
mv lex.c ../c_data/lex.c
sed '1s/^/#define SIZEOF_LEX /' junk1 > const1.h
sed 's/^/int sizeof_lex  = /' junk1 > junk3
sed 's/$/;/' junk3 > const1.c
rm junk?
