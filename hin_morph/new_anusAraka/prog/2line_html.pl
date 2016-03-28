#!/usr/bin/perl
# $Id: 2line_html.pl,v 1.1 1997/12/30 12:55:33 amba Exp amba $

$SEP = $ARGV[0]; # possible values : 'LINE' , 'GT'

if(($SEP ne "LINE") && ($SEP ne "GT")) { 
print " Usage of 2line.pl:\n";
print "Usage : 2line.pl LINE/GT tel_file hin_file <DEBUG_FLAG>\n";
exit(0);
}

#We propose to store the basic information in a processed form for two line
#display in the following three arrays.

#@preceding_white_space
#@telugu_wrd_lst
#@hindi_wrd_lst


if($ARGV[3] eq "D") {$DEBUG = 1;}
else { $DEBUG = 0;}
#--------------------------------
#First we fill up first two arrays using the telugu file.
open(INFILE,"<$ARGV[1]");
$count = -1;
$line_count = 0;
while($inputline = <INFILE>){
chop $inputline;
        if($inputline =~ /./){
	while($inputline =~ m/([	 ]*)([^ 	]*)/g) {
		$count++;
		$preceding_white_space[$count] = $1;	
		$telugu_wrd_lst[$count] = $2;	
#		print pos $inputline,"\n";
		$count_to_line_number[$count] = $line_count;
		}
        }
	$count++;
		$preceding_white_space[$count] = "\n";	
		$telugu_wrd_lst[$count] = "__NEW-LINE__";	
		$line_number_info[$line_count] = $count;
		$count_to_line_number[$count] = $line_count;
		$line_count++;
	
	}
#-------------------------------------
#Now we fill up hindi_wrd_lst and prcdg_white_spc using the hindi file.
open(OUTFILE,"<$ARGV[2]");
$cnt = -1;
$line_cnt = 0;
while($outputline = <OUTFILE>){
chop $outputline;
        if($outputline =~ /./){
	while($outputline =~ m/([	 ]*)([^	 ]*)/g) {
		$cnt++;
		$prcdng_white_spc[$cnt] = $1;	
		$hindi_wrd_lst[$cnt] = $2;	
#		print pos $outputline,"\n";
		$cnt_to_line_nmbr[$cnt] = $line_cnt;
		}
	   }
	$cnt++;
		$prcdng_white_spc[$cnt] = "\n";	
		$hindi_wrd_lst[$cnt] = "__NEW-LINE__";	
		$line_nmbr_info[$line_cnt] = $cnt;
		$cnt_to_line_nmbr[$cnt] = $line_cnt;
		$line_cnt++;
	
	}
if($DEBUG){
print $cnt,"rAma rAma\n";
#print "Target_langauge array \n";
#$i=0;
#while($i<$cnt) { print "--->",$telugu_wrd_lst[$i],"<---\n";$i++;}
#print "Source_langauge array \n";
#$i=0;
#while($i<$cnt) { print "--->",$hindi_wrd_lst[$i],"<---\n";$i++;}
#print "White spaces \n";
#$i=0;
#while($i<$cnt) { print "--->",$preceding_white_space[$i],"<---\n";$i++;}
}
#-------------------------------------
#Testing equality of the white space files.
if($DEBUG){
if($cnt == $count) { print "COUNTS MATCH\n"; }
else {print "COUNTS DO NOT MATCH\n","count=",$count," ","cnt=",$cnt,"\n"}
}

$count_i = 0;
while($count>$count_i) {
	if($prcdng_white_spc[$count_i] ne $preceding_white_space[$count_i]) {
        if($DEBUG){
	print $count_i," t ",1+$count_to_line_number[$count_i]," h ",1+$cnt_to_line_nmbr[$count_i],"\n";
	print $telugu_wrd_lst[$count_i],"  ",$hindi_wrd_lst[$count_i],"\n";
	}
	}
	$count_i++;
	}
$count_j = 0;
while($line_count>$count_j) {
        if($DEBUG){
	print $count_j+1," : ",$line_number_info[$count_j],",",$line_nmbr_info[$count_j],"\n";
        }
	$count_j++;
	}
#-----------------------------------------
#Replacing non-mandatory "\n" by "\r"
#SPECIFICATIONS:
# Wherever possible make sure that line length does not exceed 80 chars.  DONE
# Preserve "\n	" (i.e. new-line followed by TAB)  DONE
# Preserve "\n[ ]{m,.}" (i.e. new-line followed by m or more spaces.(default m[=3]))  DONE
# Preserve "\n[\n]+" (i.e. 2 or more new-lines)  DONE

# Preserve "\n" if it has less than N[=55] characters precediting it. TOBE_DONE

#ALGORITHM:
# 1. Replace all "\n" cases which do not come under preserve category by "\r". DONE

# 2. If 80th character happens to be white-space add "\n" after it;  DONE
#    else add "\n" before the word which has 80th character. DONE
#    (Count is reset after each "\n")

for($i=0;$i<$cnt;$i++)
{
$in_len = length($telugu_wrd_lst[$i]);
#@hin_ar = split(/ : /,&main_expand($hindi_wrd_lst[$i]));
if($hindi_wrd_lst[$i] !~ /__NEW-LINE__/){
$hindi_wrd_lst[$i] =~ s/['`]/\1/g;
$hindi_wrd_lst[$i] =~ s/\|/\//g;
$hindi_wrd_lst[$i] =~ s/\~/\~/g;
#printf("echo $hindi_wrd_lst[$i] \n");
open(TMP,">tmp_in");
print TMP $hindi_wrd_lst[$i];
close <TMP>;
system("ir < tmp_in |/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/bison/VC/exp|ri > tmp");
open(TMP,"<tmp");
$cmnt1 = <TMP>;
close <TMP>;
chop($cmnt1);
if($cmnt1 eq "") { $cmnt1 = $hindi_wrd_lst[$i];}
@hin_ar = split(/\|/,$cmnt1);
#$out_len = length($hindi_wrd_lst[$i]);
$out_len = 0;
foreach $hin_ar (@hin_ar){
$hin_ar =~ s/_0//;
if(length($hin_ar) > $out_len) { $out_len = length($hin_ar);}
}
#if($hindi_wrd_lst[$i] =~ /^.*\]{(.*)}$/){$out_len = $out_len+length($1);}
if($#hin_ar > 0){$out_len = $out_len+2;}
}
else { $out_len = length($hindi_wrd_lst[$i]);}
	if($in_len < $out_len){
 	  $telugu_wrd_lst[$i] = &add_spaces($telugu_wrd_lst[$i],$out_len-$in_len);
	}
	if($out_len < $in_len){
 	  $hindi_wrd_lst[$i] = &add_spaces($hindi_wrd_lst[$i],$in_len-$out_len);
	}
}
if($DEBUG) { print "padded with blank spaces\n"; }
#
#Mark the new lines that are to be preserved.
#
$i=0;
while($i<$cnt)
{
if (($preceding_white_space[$i] eq "\n") && ($preceding_white_space[$i+1] eq "\t"))
{
$preceding_white_space[$i] = "\n\r";
if($DEBUG) {
print $i," 1.--->",$telugu_wrd_lst[$i],"<---";
}
$i++;
}
elsif (($preceding_white_space[$i] eq "\n") && ($preceding_white_space[$i+1] eq "\n"))
{
while(($preceding_white_space[$i] eq "\n") && ($i < $cnt)) { 
$preceding_white_space[$i] = "\n\r";
if($DEBUG){
print $i," 2.--->",$telugu_wrd_lst[$i],"<---";
}
$i++;
}
}
elsif (($preceding_white_space[$i] eq "\n") && ($preceding_white_space[$i+1] =~ /^ [ ]{2,}$/))
{
$preceding_white_space[$i] = "\n\r";
if($DEBUG){
print $i," 3.--->",$telugu_wrd_lst[$i],"<---";
}
$i++;
}
else { $i++;}
}
#Preserve all the TO_BE_PRESERVED_NEW_LINES
#Replace all single spaces & not_to_be_preserved_new_lines by 2_spaces
$i=0;
while($i<$cnt){
if($preceding_white_space[$i] eq "\n") { $preceding_white_space[$i] = "  ";}
elsif($preceding_white_space[$i] eq "\n\r") { $preceding_white_space[$i] = "\n";}
elsif($preceding_white_space[$i] eq " ") { $preceding_white_space[$i] = "  ";}
$i++;
}
# erase the __NEW-LINE__ wrds from wrd lst.
$i=0;
while($i<$cnt){
if($telugu_wrd_lst[$i] eq "__NEW-LINE__") { $telugu_wrd_lst[$i] = "";}
if($hindi_wrd_lst[$i] eq "__NEW-LINE__") { $hindi_wrd_lst[$i] = "";}
$i++;
}

#Put new_lines after 70th character
open(OUT1,">tel_out");
open(OUT2,">hin_out");

$char_count = 0;
$i=0;
while($i<$cnt)
{
$char_count = $char_count+length($telugu_wrd_lst[$i])+length($preceding_white_space[$i]);
if(($char_count > 70) || ($preceding_white_space[$i] eq "\n")){ 
print OUT1 "\n";
print OUT2 "\n";
$preceding_white_space[$i] = "";
$char_count = length($telugu_wrd_lst[$i]);
}
print OUT1 $preceding_white_space[$i],$telugu_wrd_lst[$i];
print OUT2 $preceding_white_space[$i],$hindi_wrd_lst[$i];
#if($preceding_white_space[$i] eq "\n") {
#$char_count = length($telugu_wrd_lst[$i]);
#}
$i++;
}
print OUT1 "\n";
print OUT2 "\n";
close(OUT1);
close(OUT2);

#Now produce 3 line output
open(OUT1,"<tel_out");
open(OUT2,"<hin_out");
$sepline = "----------------------------------------------------------------------";
while (<OUT1>) {
  $l2 = <OUT2>;
if($SEP eq "LINE") { print  $_;   print $l2;  print $sepline, $., "\n";}
if($SEP eq "GT" ) { print  " ",$_;   print ">",$l2;}
}
close(OUT1);
close(OUT2);


sub add_spaces
{
local($strng,$number_of_blanks) = @_;
local($i);

for($i=1;$i<=$number_of_blanks;$i++) {
	$strng = $strng." ";
		  		  }
$strng;
}
1;
