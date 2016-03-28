while($in = <STDIN>)
{
$in =~ s/eka_vAz/pahalA/g;
$in =~ s/xo_vAz/xUsarA/g;
$in =~ s/wIna_vAz/wIsarA/g;
$in =~ s/cAra_vAz/cOWA/g;
$in =~ s/_vAz/vAz/g;
$in =~ s/_ko_\[hUz\]/_ko[hUz]/g;
$in =~ s/_kA_\[ho\]/_kA[ho]/g;
$in =~ s/___/_/g;
$in =~ s/__/_/g;
$in =~ s/_{/{/g;
$in =~ s/\/\//\//g;
$in =~ s/\/\+/+/g;
print $in;
}
