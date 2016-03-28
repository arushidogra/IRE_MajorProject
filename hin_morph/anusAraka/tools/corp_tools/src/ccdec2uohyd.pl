while($in = <STDIN>)
{
$in =~ s/\/usr\/users\/epc003/\/home\/epc002/;
$in =~ s/\/sangal\/tools\/src\/corp/\/tools\/corp_tools\/src/;
print $in;
}
