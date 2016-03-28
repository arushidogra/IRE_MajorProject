#sccs and vi ;csh program
if (-e s.$1) then
echo SCCS file exists
else
admin -i s.$1
endif
get -e s.$1
vi $1
delta s.$1
get s.$1
