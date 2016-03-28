for i in `cat lst`
do
echo $i
diff $i $i.1
done
