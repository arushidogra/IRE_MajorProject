$full_cons = "kfCxtTdDPrh";
$half_cons = "kKgGcjJFNwWXnpbBmylvSsR";
$conj_vowels = "AIEoO";
$spl_mAwrAs = "HMz";
$simple_vowels = "aiuUeq";
$pai = "j";
$halaMwa = "]";
$punct_marks = " \t\n,\.'\":;!\?%@";

while($in = <STDIN>)
{
$in =~ s/V//g;#handle telugu vowels short eV & oV
$in =~ s/lY/{/g;#pre-process lY : hard coded 
#while($in =~ /^([$full_cons$half_cons]*)([$conj_vowels$simple_vowels$spl_mAwrAs$punct_marks])/)
while($in =~ /([$spl_mAwrAs$conj_vowels$simple_vowels$punct_marks])/)
{
$left = $`;
$sep = $1;
#print "\n",$sep,"\n";
$in = $';
#print "1",$',"2";
if($left eq "") { 
#print "3",$left,"4";
#print "5",$sep,"6";
	if($sep =~ /[$punct_marks]/) { print $sep;}
        elsif($sep =~ /[$spl_mAwrAs]/) { &print_spl_mAwrA($sep);}
	else { &print_vowel($sep); }
	}
else { 
#print "7",$left,"8";
#print "1",$sep,"2";
        if($sep =~ /i/) { &print_mAwrA($sep);&print_cons($left);}
        else {
        &print_cons($left); 
	if($sep !~ /[a$spl_mAwrAs$punct_marks]/) { &print_mAwrA($sep);}
	elsif($sep =~ /[$spl_mAwrAs]/) { &print_spl_mAwrA($sep);}
	elsif($sep =~ /[$punct_marks]/)  { 
	if($left =~ /[$full_cons$half_cons]$/) { print $halaMwa;}
	 print $sep;
        }
       }
     }
 }
}

sub print_vowel
{
$vwl = $_[0];
if($vwl =~ /[$simple_vowels]/) { &print_simple_vowel($vwl); }
elsif($vwl =~ /[$conj_vowels]/) { &print_conj_vowel($vwl); }
}

sub print_simple_vowel
{
$vwl = $_[0];
if($vwl eq "a") { print "a";}
elsif($vwl eq "i") { print "f";}
elsif($vwl eq "u") { print "F";}
elsif($vwl eq "U") { print "Y";}
elsif($vwl eq "e") { print "A";}
elsif($vwl eq "q") { print "X";}
}

sub print_conj_vowel
{
$vwl = $_[0];
if($vwl eq "A") { print "aj";}
elsif($vwl eq "I") { print "f[";}
elsif($vwl eq "E") { print "Ae";}
elsif($vwl eq "o") { print "ao";}
elsif($vwl eq "O") { print "aO";}
}

sub print_cons
{
$cons = $_[0];
$prev_char = "half_cons";
while($cons =~ /^(.)(.*)$/)
{
$cns = $1;
$cons = $2;
if($prev_char eq "full_cons") { print $halaMwa;}
if($cns =~ /[$full_cons]/) { &print_full_cons($cns);$prev_char = "full_cons"; }
elsif($cns =~ /[$half_cons]/) { &print_half_cons($cns);$prev_char = "half_cons"; }
else { print $cns; $prev_char = "spl_char";}
}
if($prev_char eq "half_cons") { print $pai;}
}

sub print_full_cons
{
$cns = $_[0];
if($cns eq "k") { print "k";}
elsif($cns eq "f") { print "&";}
elsif($cns eq "C") { print "C";}
elsif($cns eq "x") { print "d";}
elsif($cns eq "t") { print "Z";}
elsif($cns eq "T") { print "V";}
elsif($cns eq "d") { print "L";}
elsif($cns eq "D") { print "S";}
elsif($cns eq "P") { print "P";}
elsif($cns eq "r") { print "r";}
elsif($cns eq "h") { print "H";}
}

sub print_half_cons
{
$cns = $_[0];
if($cns eq "k") { print "K";}
elsif($cns eq "K") { print "x";}
elsif($cns eq "g") { print "g";}
elsif($cns eq "G") { print "G";}
elsif($cns eq "c") { print "c";}
elsif($cns eq "j") { print "J";}
elsif($cns eq "J") { print "z";}
elsif($cns eq "F") { print "#";}
elsif($cns eq "N") { print "q";}
elsif($cns eq "w") { print "t";}
elsif($cns eq "W") { print "T";}
elsif($cns eq "X") { print "D";}
elsif($cns eq "n") { print "n";}
elsif($cns eq "p") { print "p";}
elsif($cns eq "b") { print "b";}
elsif($cns eq "B") { print "B";}
elsif($cns eq "m") { print "m";}
elsif($cns eq "y") { print "y";}
elsif($cns eq "l") { print "l";}
elsif($cns eq "v") { print "v";}
elsif($cns eq "S") { print "w";}
elsif($cns eq "s") { print "s";}
elsif($cns eq "R") { print "Q";}
}

sub print_mAwrA
{
$mAwrA = $_[0];
if($mAwrA eq "A") { print "h";}
else { print $mAwrA; }
}
sub print_spl_mAwrA
{
$spl_mAwrA = $_[0];
if($spl_mAwrA eq "M") { print "N";}
elsif($spl_mAwrA eq "H") { print ":";}
elsif($spl_mAwrA eq "z") { print "%";}
}
