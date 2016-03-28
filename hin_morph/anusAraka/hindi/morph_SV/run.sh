for i in `ls ../corpus/FR_WRDS/x??`
do
echo $i
./morph_sv.sh $i 
done
