# $Id: map.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/prog/get_rt.pl";
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/prog/gen.pl";
if($ARGV[0] eq "GDBM"){
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/tools/include/use.pl";
tie(%DICT,GDBM_File,$ARGV[1],GDBM_READER,0644);
tie(%TAM,GDBM_File,$ARGV[2],GDBM_READER,0644);
}
else {
dbmopen(DICT,$ARGV[1],0644);
dbmopen(TAM,$ARGV[2],0644);
}
if($ARGV[3] eq "TEL") {
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/telugu/chk_cat_tel.pl";
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/telugu/get_tel_derived_rt.pl";
}
if($ARGV[3] eq "MAR") {
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/marathi/chk_cat_mar.pl";
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/marathi/get_mar_derived_rt.pl";
}
if($ARGV[3] eq "PUN") {
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/punjabi/chk_cat_pun.pl";
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/punjabi/get_pun_derived_rt.pl";
}
if($ARGV[3] eq "BNG") {
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/bengali/chk_cat_bng.pl";
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/bengali/get_bng_derived_rt.pl";
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/bengali/get_bng_gnp.pl";
}
if($ARGV[3] eq "KAN") {
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/kannada/chk_cat_kan.pl";
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/new_anusAraka/kannada/get_kan_derived_rt.pl";
}
if($ARGV[4] eq "FIRST") { $ALL = 0;}
elsif ($ARGV[4] eq "ALL") { $ALL = 1;}
$| = 1;
local($in,$analysis,$wrd,@anal,$cat,$tam,$rt,$tl_rt,$cnt,$emp,$tl_emp,$tam_emp);
while($in = <STDIN>)
{
chop($in);
#($wrd,$analysis) = split(/,/,$in,2); # 2 is added to avoid truncation, in case
# ana conitans ','.
$analysis = $in;
print $analysis,",";
if($analysis =~ /\+/) { $analysis =~ s/\+/\/\+/;}
#print "ana=",$analysis,"\n";
@anal = split(/\//,$analysis);
$cnt = 0;
foreach $anal (@anal)
{
if($anal =~ /\+/) { print "+"; $anal =~ s/\+//;}
#print $anal,"\n";
$per = "NW";
$gen = "NW";
$num = "NW";
$tam = "NW";
if($anal =~ /\*(.*)\*/) # Case of noun or verb
{
if($anal =~ /^([^{]*){([nP]) ([^ ]*) ([^ ]*) \*(.*)\* /) # Case of noun
{
$rt1 = $1; $cat = $2; $gen = $3; $num = $4; $tam = $5; $tam_emp = "";
$gen = ""; # Is it neccesary to produce noun gen in o/p?
if($tam eq "d") { $tam = 0;}
}
if($anal =~ /^([^{]*){n ([^ ]*) \*([^ ]*)\* (.*) }/) # Case of noun For BANGALA
{
$rt1 = $1; $cat = "n"; $num = $2; $tam = $3; $num = $num."-".$4; $tam_emp = "";
if($tam eq "d") { $tam = 0;}
if($num eq "e-0") { $num = "";} # TEMP FIX AMBA
}
elsif($anal =~ /^([^{]*){([nP]) ([^ ]*) ([^ ]*) \*(.*)\*_([^ ]*) /) # Case of noun + emp
{
$rt1 = $1; $cat = $2; $gen = $3; $num = $4; $tam = $5; $tam_emp = $6;
$gen = ""; # Is it neccesary to produce noun gen in o/p?
}
elsif($anal =~ /^([^{]*){n \*([^\*]*)\* /) # Case of noun for KANNADA
{
$rt1 = $1; $tam = $2; $tam_emp = "";
if($tam =~ /n_/) { $cat = "num";} 
elsif($tam =~ /adj/) { $cat = "adj";}
#print $cat,"\n";
}
elsif($anal =~ /^([^{]*){(adj) ([^ ]*) ([^ ]*) \*(.*)\* /) # Case of noun
{
$rt1 = $1; $cat = $2; $gen = $3; $num = $4; $tam = "0"; $tam_emp = "";
$gen = ""; # Is it neccesary to produce noun gen in o/p?
if($tam eq "d") { $tam = 0;}
}
elsif($anal =~ /^([^{]*){(adj) ([^ ]*) ([^ ]*) \*(.*)\*_([^ ]*) /) # Case of noun + emp
{
$rt1 = $1; $cat = $2; $gen = $3; $num = $4; $tam = "0"; $tam_emp = $6;
$gen = ""; # Is it neccesary to produce noun gen in o/p?
if($tam eq "d") { $tam = 0;}
}
elsif($anal =~ /^([^{]*){([Pn]) ([^ ]*) \*(.*)\* /) # Case of Pronoun
{
$rt1 = $1; $cat = $2; $num = $3; $tam = $4; $tam_emp = "";
}
elsif($anal =~ /^([^{]*){([Pn]) ([^ ]*) \*(.*)\*_([^ ]*) /) # Case of Pronoun + emp
{
$rt1 = $1; $cat = $2; $num = $3; $tam = $4; $tam_emp = $5;
}
elsif($anal =~ /^([^{]*){v \*(.*)\* ([^ ]*) ([^ ]*) ([^ ]*)/ ) # Case of verb
{
$rt1 = $1; $cat = "v"; $tam = $2; $tam_emp = ""; $gen = $3; $num = $4; $per = $5;
if($ARGV[3] eq "BNG") {
if($gen eq "koI") { $gen = "NW";}
if($per eq "koI") { $per = "NW";}
if($num eq "koI") { $num = "NW";}
}
if(($ARGV[3] eq "MAR") ||($ARGV[3] eq "KAN")){
if($gen eq "any") { $gen = "NW";}
if($per eq "any") { $per = "NW";}
if($num eq "any") { $num = "NW";}
}
}
elsif($anal =~ /^([^{]*){v \*(.*)\* ([^ ]*) / ) # Case of verb
{
$rt1 = $1; $cat = "v"; $tam = $2; $tam_emp = ""; $gnp = $3; 
if($ARGV[3] eq "BNG") {
($gen,$per,$num) = split(/:/,&get_bng_gnp($gnp));
}
}
elsif($anal =~ /^([^{]*){v \*(.*)\* / ) # Case of nf verbs
{
$rt1 = $1; $cat = "v"; $tam = $2; $tam_emp = "";
}
elsif($anal =~ /^([^{]*){v \*(.*)\*_([^ ]*) ([^ ]*) ([^ ]*) ([^ ]*)/ ) # Case of verb + emp
{
$rt1 = $1; $cat = "v"; $tam = $2; $tam_emp = $3; $gen = $4; $num = $5; $per = $6;
}
#print $rt1,"\n";
if($rt1 =~ /^(.+)_(.*)$/){ $rt = $1; $rt_emp = "_".$2;
$tl_rt = &get_derived_rt($rt,$cat,$cnt,$rt_emp);
}
else {
$rt = $rt1;$rt_emp = "";
$tl_rt = &get_rt($rt,$cat,$cnt,$ALL);
}
@tl_rts = split(/\//,$tl_rt);
$gen_bak = $gen;
$num_bak = $num;
$per_bak = $per;
foreach $tl_rt1 (@tl_rts)
{
$gen = $gen_bak;
$num = $num_bak;
$per = $per_bak;
#print $tl_rt1,$cat,$num,$tam,$TAM{$tam},$tam_emp;
if($num eq "eka") { $num = "e";}
elsif($num eq "bahu") { $num = "ba";}
#$| = 1;
$tl_tam = $TAM{$tam};
if($tl_tam eq "") { 
print $tl_rt1,"_",$tam;}
else{
if($tl_tam =~ /(.*)\~(.*)/) { $tl_tam1 = $1; $tl_tam2 = $2;}
else { $tl_tam1 = $tl_tam; $tl_tam2 = ""; }
#print $tl_rt1,$cat,$num,$tl_tam1;
if($cat eq "adj") { $cat = "n";}
#print $rt," ",$tl_rt1,$cat,$gen,$num,$per,$tl_tam,"##",$tl_tam1,"##\n";
if($rt eq $tl_rt1) { print "1.";}
if($cat eq "v") { print "V.";}
&gen($tl_rt1,$cat,$gen,$num,$per,$tl_tam1);
}
#print gnp info in curly braces\n";
if($gen eq "NW") { $gen = "";}
if($num eq "NW") { $num = "";}
if($per eq "NW") { $per = "";}
#if($gen eq "koI") { $gen = "";} # Added for Bangala
#if($num eq "koI") { $num = "";} # Added for Bangala
#if($per eq "koI") { $per = "";} # Added for Bangala
if($tl_tam2 ne "") { print "_",$tl_tam2;}
if($tam_emp ne "") { print "_",$tam_emp;}
if(($gen ne "") || ($num ne "") || ($per ne "")){ print "{";}
if($gen ne ""){ print $gen;}
if($num ne ""){ print $num;}
if($per ne ""){ print $per;}
if(($gen ne "") || ($num ne "") || ($per ne "")){ print "}";}
print "/";
}
#if($TAM{$tam} ne "0") { print "_",$TAM{$tam};}
#if($emp ne "") { print "_",$emp;}
#print "/";
}
else { # case of Avys
$anal =~ s/\/$//;
if($anal =~ /^(.+)_(.*)$/){
$rt = $1;
$emp = $2;
if($rt =~ /{Avy }/) { $rt =~ s/{Avy }//;}
if($emp =~ /{Avy }/) { $emp =~ s/{Avy }//;}
$tl_rt = &get_derived_rt($rt,"avy",$cnt,$emp);
if($rt eq $tl_rt1) { print "1.";}
}
else {
if($anal =~ /{Avy }/) { $anal =~ s/{Avy }//;}
$rt = $anal;$emp = "";
#print "VISITED AVY: ",$rt,"\n";
$tl_rt = &get_rt($rt,"avy",$cnt,$ALL);
if($rt eq $tl_rt1) { print "1.";}
}
print $tl_rt,$emp,"/";
}
$cnt++;
} # end of for loop for multipe morph analysis
print "\n";
} # End of while loop
if($ARGV[0] eq "GDBM") {
untie(%DICT);
untie(%TAM);
}
else {
dbmclose(DICT);
dbmclose(TAM);
}
