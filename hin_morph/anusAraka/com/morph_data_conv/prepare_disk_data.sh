# This program is to prepare the pc_version of the data
# It assumes that the following files are already created.
#
#
# ../c_data will have the following files.
# avy.c
# lex.c
# feature_value.c
# 	&
# suff_info in test area.
#
# Following files will be created in disk_data directory
# avy_disk.c
# lex_disk.c
# feature_value_disk.c
# suff_info_disk.c

echo preparing suff_info_disk.c
/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/suff_add_ptr_disk.out
mv suff_info.c ../disk_data/suff_info_disk.c

echo preparing avy_disk.c
 sed -e '1,3d
         4,$s/\"//g
        $d' ../c_data/avy.c >jnk
awk -F, '{printf("%-30s\n",$1)}' <jnk >avy_disk.c
mv avy_disk.c ../disk_data/avy_disk.c


echo preparing lex_disk.c
sed -e '1,3d
        4,$s/\"//g
        $d' ../c_data/lex.c >jnk
awk -F, '{printf("%-30s,%-15s,%-2s\n",$1,$2,$3)}' < jnk > lex_disk.c
mv lex_disk.c ../disk_data/lex_disk.c

echo preparing feature_value_disk.c
sed -e '1,3d
        $d' ../c_data/feature_value.c >jnk
awk -F\" '{printf("%-60s\n",$2)}' <jnk >feature_value_disk.c
mv feature_value_disk.c ../disk_data/feature_value_disk.c

rm jnk
