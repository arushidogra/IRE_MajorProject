ANU_prog=/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/prog
cp /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/tools/empty story_wrds
perl $ANU_prog/create_dbm.pl GDBM story_wrds < $1
