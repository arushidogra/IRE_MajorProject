corpus_analysis.out < $1 > $1.s
sed '1,$s/ *\([0-9]\)/\1/' $1.s > tmp0000
mv tmp0000 $1.s
sort -m +1 stats.s $1.s > tmp0001
my_merge.out tmp0001 > stats.s
