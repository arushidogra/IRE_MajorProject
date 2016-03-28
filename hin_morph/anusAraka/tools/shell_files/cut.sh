for i in *.tmp1
do
cut -d, -f2 $i>tmp
paste final.lex tmp >tmp.lex
mv tmp.lex final.lex
rm tmp
done

