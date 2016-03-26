#!/usr/bin/perl
while($in = <STDIN>)
{
if($in =~ /^""/)
{
$in =~ s/^""/"0"/;
}
print $in;
}
