input_dir=$1
ouput_dir=$2

for f in $input_dir/*.p
do
	filename=`basename $f`
	#echo "Processing $f"
	#echo $filename
	#tokenizer.sh $f > "$2/$filename-ssf.txt"
	#more +2 $f > $f.txt
	tail -n +2 $f | sed 's/\/.*$//g' | sort | uniq | sed 's/^/1\t/g' > "$2/$filename-ssf-wx"
done
