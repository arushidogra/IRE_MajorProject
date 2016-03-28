sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/lext_print.sh > junk0
sed '/avy.t/ d' junk0 > junk4
sed '$s/,//' junk4 > junk0 
wc -l junk0 > junk1
sed -e 's/^[ ]*//
        s/[A-Za-z].*$//' junk1 >> junk2
sed '1s/^/#define totalf /' junk2 > junk3
cat junk3 /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/lext_head junk0 /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/tail > lext.h
rm junk?
