sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/info_print.sh > junk0
sed '$s/,//' junk0 > junk4
wc -l junk4 > junk1
sed -e 's/^[ ]*//
        s/[A-Za-z].*$//' junk1 >> junk2
sed '1s/^/#define totfile /' junk2 > junk3
cat junk3 /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/info_head junk4 /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/tail > info.h
rm junk?
