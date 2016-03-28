while($in = <STDIN>){
if($in =~ /{/){
if($in !~ /,[a-zA-Z\_]{1,}{[a-zA-Z\_?]{2,}/) {
$in =~ s/,.*/,\@SKIPPING/;
}
}
print $in;
}
