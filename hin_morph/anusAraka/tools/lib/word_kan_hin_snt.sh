#This program collects all the sentences from corpus given the word , and gives there hindi equivalents.
# The output is displayed on the screen
d0=/4u4/cspg/phd/vnn/anu/anuvAd/test/sb 
d1=/1d1/amba/tools/lib
curr_dir=`pwd`
rm fl_nms
cd $d0/kannada
  fgrep -l  $1  story* > $curr_dir/fl_nms
cd $curr_dir
	 for i in `cat fl_nms`
	 do
 $d1/read_snt.out N D.< $d0/kannada/$i >temp0001
	 egrep " $1 " temp0001 >temp0002
	  /1d1/amba/tools/lib/my_cut.out f1 < temp0002 >snt_nos

 sed '1,$s/\.\]/\]/g
      1,$s/\.\}/\}/g' $d0/hindi/$i >temp000
 $d1/read_snt.out N I D. <temp000 >hin_snt_no

 $d1/read_snt.out N I D. < $d0/kannada/$i >kan_snt_no

	 echo $i 
	 	for j in `cat snt_nos`
	 	do
         	egrep "^$j " kan_snt_no  
         	egrep "^$j " hin_snt_no  
         	done
	 done
 rm $curr_dir/temp000 $curr_dir/temp0001 $curr_dir/temp0002
 rm  $curr_dir/story*.hin_snt_no
 rm  $curr_dir/story*.kan_snt_no
 rm  $curr_dir/story*.mo_snt
 rm $curr_dir/snt_nos
