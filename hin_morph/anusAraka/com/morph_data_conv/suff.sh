#cp suff_info suff_info.bak
sort -T /tmp suff_info >sorted
mv sorted suff_info
/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/suff_add_ptr.out
wc -l suff_info.c >junk1
sed -e 's/^[ ]*//
    s/[A-Za-z].*$//' junk1 >> junk2
cat /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/suff_info1.head suff_info.c /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/tail >junk3
rm suff_info.c
mv junk3 ../c_data/suff_info.c
sed '1s/^/#define SIZEOF_SUFF_ADD /' junk2 > const3.h
sed 's/^/int sizeof_suff_add = /' junk2 > junk4
sed 's/$/;/' junk4 > const3.c
rm junk?
