for i in *.tmp1
do
sed '1,$s/ /,/' $i>$i_c
done
