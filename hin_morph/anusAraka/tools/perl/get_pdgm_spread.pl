#!/usr/bin/perl
#This program calculates the average,max & min spread for the pdgms of a language
# ARGV[0] : location of *.p files
#Sample Usage : perl get_pdgm_spread.pl /home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/telugu/morph/grp0/pc_data
print $ARGV[0],"\n";
$max=0;
$min=10000;
chdir ($ARGV[0]);
system("ls *.p > lst");
open(LST,"lst");
foreach $f (<LST>)
{
$/ = "EOF";

$files++;
print $f," ";
open(FILE,$f);
$l = <FILE>;
close(FILE);
$ln_count =($l =~ tr/\n/\n/);
$l =~ s/\//\n/g;
$word_count =($l =~ tr/\n/\n/);

$total_ln_count+=$ln_count;
$total_word_count+=$word_count;
printf "%3d",$word_count;
print " ";
printf "%.3g", $word_count/$ln_count;
print "\n";
if($max<$word_count/$ln_count) {$max=$word_count/$ln_count;}
if($min>$word_count/$ln_count) {$min=$word_count/$ln_count;}
$/ = "\n";
}
close(LST);
print "\n";
print "Average Spread = ";
printf "%.3g",$total_word_count/($total_ln_count);
print "\n";
print "Maximum Spread = ";
printf "%.3g",$max;
print "\n";
print "Minimum Spread = ";
printf "%.3g",$min;
print "\n";
