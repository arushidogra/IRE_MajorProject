# Data is generated in wip area & merged with the previous data . Backup of old data is stored in wip. 
cd wip
# copy the files temporarily. Reqd for data generation 
cp ../feature_value .
cp ../offset .

sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph/data_conv/info.sh
# data is being generated
echo data is being generated
cp /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/suff_gen.c .
cc -g -o suff_gen.out suff_gen_disk.c /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/tools/mt/source_code/getfileword.0
suff_gen.out 1

# data generation over
echo  data generation over
rm suff_gen_disk.c
cp ../suff_info suff_info.old

# data files are being merged
echo data files are being merged
sort -mu suff_info suff_info.old >suff_info.new
# files are moved to appropriate places.
mv suff_info.new suff_info
/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/suff_add_ptr.out
mv ../pdgm_offset_info pdgm_offset_info.bak
mv ../suff_info.c ../suff_info.c.bak
mv suff_info.c ../
mv pdgm_offset_info ../
rm feature_value
rm offset

# data is compiled.
cd ..
cc -g -c suff_info.c
sh comp.sh
