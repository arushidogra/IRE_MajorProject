/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/amba/tools/lib/reverse.out < $1 > $1.t
sort $2 < $1.t >jnk
/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/amba/tools/lib/reverse.out < jnk > $1.rs
#rm $1.t jnk
