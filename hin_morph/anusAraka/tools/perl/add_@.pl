$/ = " ";
while(<STDIN>)
{
#print $_;
if($_ =~ /\n/)
	{
	$first = $`;
	$second = $';
	if($first =~ /^([^A-Za-z0-9]*)([A-Za-wyz]+)(.*)/){
		print "$1","@",$2,"@",$3,"\n";
	}
	else {print $first,"\n";}
	if($second =~ /^([^A-Za-z0-9]*)([A-Za-wyz]+)(.*)/){
		print $1,"@",$2,"@",$3;
	}
	else {print $second;}
	}
elsif ($_ =~ /^([^A-Za-z0-9 ]*)([A-Za-wyz]+)(.*)/){ 
                print $1,"@",$2,"@",$3; 
        }
else { 
	print $_;
	}
}
