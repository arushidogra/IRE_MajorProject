sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/avy.sh

sed '/#define SIZEOF_IND/ d' ../c_data/const.h > junk0
sed '/int sizeof_ind/ d' ../c_data/const.c > junk1
cat const2.h junk0 > ../c_data/const.h
cat const2.c junk1 > ../c_data/const.c
rm const2.h
rm const2.c
rm junk?
