echo preparing suff_info_disk.c
sed -e '1,3d
        4,$s/\"//g
        $d' ../c_data/suff_info.c >jnk
awk -F, '{printf("%-35s,%-14s,%-8d,%-4d\n",$1,$2,$3,$4)}' < jnk > suff_info.c
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
