if (sed -e 's/\/usr1\/proj\/mtg\//\/usr\/cs\/srinivas\/hcl1\//
	s/\/usr1\/proj\/mt\//\/usr\/cs\/srinivas\/hcl1\//' $1 > ,tmp)
then
	chmod 644 $1
	mv ,tmp $1
fi
