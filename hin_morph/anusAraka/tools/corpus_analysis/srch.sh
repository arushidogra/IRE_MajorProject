for i in /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/telugu/test/sb/CORPUS/TEXT/*
do
echo $i
/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/amba/amba/corpus_analysis/grep.pl $1 < $i
echo ============================================
done
