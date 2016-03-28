for i in *.s
do
newname=`basename $i .s`
mv $i $newname
done
