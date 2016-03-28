chomp($prefix = `pwd`);
while($in = <STDIN>){
$in =~ s/\/home\/amba/$prefix/g;
print $in;
}
