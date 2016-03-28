# $Id: clean.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
while($in = <STDIN>)
{
$in =~ s/\bkOna_BI\b/koyi_BI/g;
$in =~ s/\bkOna_/kisa_/g;
$in =~ s/\bkara_kara/kara_ke/g;
$in =~ s/_kara_kara/_kara_ke/g;
#$in =~ s/\bkarA\b/kiyA/g;
$in =~ s/_karA_/_kiyA_/g;
$in =~ s/_karA\b/_kiyA/g;
$in =~ s/_jAyA/_gayA/g;
$in =~ s/\bjAyA/gayA/g;
$in =~ s/_vAz_vAlI/_vI/g;
$in =~ s/\bsADe_eka\b/deDa/g;
$in =~ s/\bsADe_xo\b/DAI/g;
$in =~ s/\bcAra_vAz\b/cOWA/g;
$in =~ s/\bwIna_vAz\b/wIsarA/g;
$in =~ s/\bxo_vAz\b/xUsarA/g;
$in =~ s/\beka_vAz\b/pahalA/g;
$in =~ s/_hoyA\b/_huA/g;
$in =~ s/\bhoyA\b/huA/g;
$in =~ s/_huA_huA/_huA/g;
$in =~ s/\bhuA_huA/huA/g;
$in =~ s/\bhuA_\[huA\]/huA/g;
$in =~ s/\budu_/a_/g;
$in =~ s/\budu\b/a/g;
#$in =~ s/jo\*_vaha_/so-/g;
#$in =~ s/jo\*_vaha/so/g;
$in =~ s/<#ajFAwa>//g;
$in =~ s/<ajFAwa>//g;
$in =~ s/<UW>//g;
$in =~ s/<#UW>//g;
$in =~ s/\[hE\|WA\]/\[hE\/WA\]/g;
$in =~ s/ne_ko\`/ne_ke_liye/g;
$in =~ s/\[WA\|rahA\]/\[hE\/rahA\]/g;
print $in;
}
