for i in *map
do
awk -F, '{printf "%s\n\n%s\n\n",$1,$2}' $i >$i.jay
done

