sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/info.sh
sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/lext.sh
sh /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/morph_data_conv/main2.sh
#rm lext.h
#rm info.h
make
if test -a suff
then 
	rm suff
fi
if test -a ../../test/uword
then 
	rm ../../test/uword
fi
/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/prog/mk_dbm_suff
/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/mk_dbm_uword
chmod 644 suff ../../test/uword
