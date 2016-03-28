perl /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/flat_dbm_conversion/join_dict.pl < dict.special > jnk
rm dict_special
perl /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/flat_dbm_conversion/create_dbm_dict.pl GDBM dict_special < jnk
chmod 644 dict_special
