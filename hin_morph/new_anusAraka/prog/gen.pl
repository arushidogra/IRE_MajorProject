# $Id: gen.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
sub gen
{
local($rt,$cat,$gen,$num,$per,$tam) = @_;
local($lft_prt,$comm,$rt_prt);
#print "##",$rt," ",$cat," ",$gen," ",$num," ",$per," ",$tam,"\n";
$lft_prt = "";
$comm = "";
$rt_prt = "";
#Example : ho[raha];
#Example : pAla[>badA_kara];
if (($rt =~ /[^_]\[/) && (($rt =~ /[^_]\]$/) || ($rt =~ /[^_]\]{.*}$/)))
{
if($rt =~ /\[</) { $NS = "<";}
elsif($rt =~ /\[>/) { $NS = ">";}
else { $NS = "";}
if($rt =~ /[^_]\]({.*})$/){$comm = $1;$rt =~ s/{.*}$//;}
$rt1 = $rt;
$rt2 = $rt;
$rt2 =~ s/(.*)\[[<>]?//;
$rt2 =~ s/\]$//;
$rt1 =~ s/\[.*\]//;
}
else { $rt1 = $rt; $rt2 = "";}
for($i=0;$i<2;$i++)
{
if($i == 0) { $rt = $rt1;}
if($i == 1) { $rt = $rt2;}
if($rt ne "")
{
if($i == 1) { print "[",$NS;}
## Example vaha{swrI}
if($rt =~ /}$/) { $rt =~ /^([^{]+){(.+)}$/; $rt = $1; $comm = "{".$2."}";}
#print "##",$rt," ",$cat," ",$gen," ",$num," ",$per," ",$tam,"\n";
## Example xonoM_[logoM]_ko , xonoM_[logoM]_ko_hI
if($rt =~ /._\[.*\]_/) { $rt =~ /^(.+_\[.+\].*_)([^_]+)$/; $lft_prt = $lft_prt.$1; $rt = $2;}
#print "##",$lft_prt," ",$rt," ",$cat," ",$gen," ",$num," ",$per," ",$tam,"\n";
## Example [ki_]ora
#if($rt =~ /^\[./) { $rt =~ /^\[(.+)_\](.+)$/; $lft_prt = $lft_prt."[".$1."_]"; $rt = $2;}
## Example [ki]_ora
if($rt =~ /^\[./) { $rt =~ /^\[(.+)\]_(.+)$/; $lft_prt = $lft_prt."[".$1."]_"; $rt = $2;}
#print "##",$rt," ",$cat," ",$gen," ",$num," ",$per," ",$tam,"\n";
## Example Ane_vAlA_[xina]
if($rt =~ /^(.+)_\[([^\]]+)\]$/) { $rt =~ /^(.+)_\[([^\]]+)\]$/; $rt = $1; $rt_prt = "_[".$2."]";}
## Example jagaha[_para]
#if($rt =~ /\[_./) { $rt =~ /^(.+)\[_([^\]]+)]$/; $rt = $1; $rt_prt= "[_".$2."]";}
#print "##",$rt," ",$cat," ",$gen," ",$num," ",$per," ",$tam,"\n";
## Example *_vaha_
#print "AAAA",$rt,"AAAA\n";
if($rt =~ /^(.+)_([^_]+)_$/) { $rt =~ /^(.+)_([^_]+)_$/; $lft_prt = $lft_prt.$1."_"; $rt = $2;$rt_prt = "_";}
#print "##",$rt," ",$cat," ",$gen," ",$num," ",$per," ",$tam,"\n";
## Example vaha_
#print "AAAA",$rt,"AAAA\n";
if($rt =~ /^(.+)_$/) { $rt =~ /^(.+)_$/; $rt = $1;$rt_prt = "_";}
## Example vaha`
#print "AAAA",$rt,"AAAA\n";
if($rt =~ /.\`$/) { $rt =~ /^(.+)\`$/; $rt = $1;$rt_prt = "`";}
#print "##",$lft_prt," ",$rt," ",$cat," ",$gen," ",$num," ",$per," ",$tam,"\n";
## Example Ascarya_cakiwa
#print "AAAA",$rt,"AAAA\n";
if($rt =~ /^(.+)_([^_]+)$/) { $rt =~ /^(.+)_([^_]+)$/; $lft_prt = $lft_prt.$1."_"; $rt = $2;}
#print "##",$rt," ",$cat," ",$gen," ",$num," ",$per," ",$tam,"\n";
$rt =~ s/`$//;
#print "##",$rt," ",$cat," ",$gen," ",$num," ",$per," ",$tam,"\n";
print $lft_prt;
#print "LFT=",$lft_prt,"RT=",$rt,"AAAA\n";
if($rt =~ /^([^a-zA-Z]*)([a-zA-Z].*)$/) { print $1; $rt = $2;}
#print "input:",$rt," ", $cat," ", $gen," ", $num," ", $per," ", $tam,"OVER\noutput:";
if(!(($tam eq "future") && ($num eq "p") && ($per eq "u")) && ($tam ne "nA"))# if not fin_hortative
{
# Always generate 3ms forms
$per = "a";
$num = "s";
$gen = "m";
}
if($tam eq "ne") { 
$per = "a";
$num = "p";
$gen = "m";
}
#print "AAAA",$rt,":",$cat,":",$gen,":",$num,":",$per,":",$tam,"AAAA\n";
if($rt eq "") { print "Case_NOT_COVERED_IN_gen.pl ";}
elsif($rt eq "*") { print $rt;}
else {
$rt =~ s/vaha\`/vaha/;
#print "AAAA",$rt,":",$cat,":",$gen,":",$num,":",$per,":",$tam,"AAAA\n";
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/gen/gen.out $rt $cat $gen $num $per $tam");
#system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/com/gen/test/new_gen.out ON SHOW $rt $cat $gen $num $per $tam");
}
#print "OVER\n";
print $rt_prt,$comm;
if($i == 1) { print "]"}
}
}
}
1;
