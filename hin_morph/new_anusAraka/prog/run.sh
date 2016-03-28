for i in `cat lst`
do
echo $i
#perl /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/Modify/ndbm2gdbm_pl.pl < $i > $i.1
#mv $i.1 $i
perl add_id.pl < BAK/$i > $i
done
