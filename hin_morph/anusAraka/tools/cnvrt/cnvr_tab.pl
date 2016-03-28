# This program converts a file from one roman notation to IITK Notation.
# Input : a table of conversion in the following form
# symbol in roman notation,symbol in iitk notation
# E.G. sample entries for BH Krishnamurthy's notation to IITK Notation:
#a,a
#a,A
#i,i
#ii,I

# Usage : perl cnvrt.pl tab < input_file > output_file
# tab : file name of the above table
# input_file : a file in one roman notation
# output file : conversion of input-file into iit-k notation
open($TAB,"$ARGV[0]");
$max = 0;
while($in = <$TAB>)
{
chop($in);
($key1 ,$val1)=split(/,/,$in);
$tab{$key1} = $val1;
if($max < length($key1)) { $max = length($key1);}
}
close($TAB);
#print $max,"\n";
$look_ahead = $max;
#foreach $key ( keys %tab)
#{
#print $key , " " ,$tab{$key},"\n";
#}
$| = 1;
while($in = <STDIN>)
{
chop($in);
if(length($in) >= $look_ahead) 
{$cur_look_ahead = $look_ahead;}
else {$cur_look_ahead = length($in);}
while($in =~ /./)
{
$in =~ /^(.{$cur_look_ahead})(.*)$/;
$context = $1;
$rem = $2;
if($tab{$context} ne "") { 
print $tab{$context};
$in = $rem;
if(length($in) >= $look_ahead) 
{$cur_look_ahead = $look_ahead;}
else {$cur_look_ahead = length($in);}
#$cur_look_ahead = $look_ahead;
}
else { 
if($cur_look_ahead > 1)
{
$cur_look_ahead = $cur_look_ahead-1;
}
else { #look-ahead equal to 1. In this case map the charatcter as it is.
print $context;
$in = $rem;
if(length($in) >= $look_ahead) 
{$cur_look_ahead = $look_ahead;}
else {$cur_look_ahead = length($in);}
}
}
}
#print $cur_look_ahead,"\n",$in;
print "\n";
}
