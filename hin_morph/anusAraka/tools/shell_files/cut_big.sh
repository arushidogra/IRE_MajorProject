grep '[0-9][0-9][0-9][0-9]' $1 > jnk
perl /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/telugu/STATS/corpus/grep_big.pl $2 < jnk > $1.$2
