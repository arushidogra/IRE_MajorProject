#Usage : MORPH.sh file_name
#Output : file_name.mo
/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/tools/layout/sep_punct.out < $1 | tr ' ' '\012' | sort -u| grep '[a-zA-Z]' > wrds
/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/moh_special.sh < wrds > wrds.mo
paste -d, wrds wrds.mo | grep ',.' > tmp.mo
sed '1,$s/^w[0-9]* //' < uword > unkn
perl /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph_SV/spell_variation.pl < unkn > unkn.mo
cat tmp.mo unkn.mo | sort -u > mo2
cat /dev/null > story_wrds
/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/prog/create_dbm.out story_wrds < mo2
/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/prog/sbst_mo.out story_wrds < $1 > $1.mo
rm wrds wrds.mo tmp.mo mo2 story_wrds unkn unkn.mo tmp.r tmp uword
