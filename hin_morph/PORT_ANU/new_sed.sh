#echo $1
if test -x $1
then
exec=1
else
exec=0
fi
perl sed.pl < $1 > jnk
mv jnk $1
if test $exec
then
chmod +x $1
fi
