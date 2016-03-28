perl /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/flat_dbm_conversion/join_dict.pl < dict.final > dict_final.dbm.c
if test -a dict_final
then 
	rm dict_final
fi
perl /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/flat_dbm_conversion/create_dbm_dict.pl GDBM dict_final < dict_final.dbm.c
chmod 644 dict_final
