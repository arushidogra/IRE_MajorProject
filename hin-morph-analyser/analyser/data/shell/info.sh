sh info_print.sh > junk0
sed '$s/,//' junk0 > junk4
wc -l junk4 > junk1
sed -e 's/^[ ]*//
        s/[A-Za-z].*$//' junk1 >> junk2
sed '1s/^/#define totfile /' junk2 > junk3
cat junk3 ../c_data/info_head junk4 ../c_data/tail > info.h
mv info.h ../c_data/
rm junk?
