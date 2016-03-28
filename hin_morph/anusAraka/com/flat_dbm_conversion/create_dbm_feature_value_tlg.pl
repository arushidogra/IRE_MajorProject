if($ARGV[0] eq "GDBM"){
require "/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/tools/include/use.pl";
tie(%TGNP,GDBM_File,$ARGV[1],0666,0);
}
else { dbmopen(TGNP,$ARGV[1],0666); }
$i=1;
while(<STDIN>)
{
chop();
if(/person:23_ba:/) { 
$one = $_;
$two = $_;
$three = $_;
$one =~ s/person:23_ba/person:2_ba/;
$two =~ s/person:23_ba/person:3_na_ba/;
$three =~ s/person:23_ba/person:3_\~_na_ba/;
if($TGNP{$one} ne "") { $TGNP{$one} = $TGNP{$one}."#".$i;} else { $TGNP{$one} = $i;}
if($TGNP{$two} ne "") { $TGNP{$two} = $TGNP{$two}."#".$i;} else { $TGNP{$two} = $i;}
if($TGNP{$three} ne "") { $TGNP{$three} = $TGNP{$three}."#".$i;} else { $TGNP{$three} = $i;}
}
elsif(/person:3:/) { 
$one = $_;
$two = $_;
$three = $_;
$four = $_;
$one =~ s/person:3/person:3_pu_e/;
$two =~ s/person:3/person:3_\~_pu_e/;
$three =~ s/person:3/person:3_na_ba/;
$four =~ s/person:3/person:3_\~_na_ba/;
if($TGNP{$one} ne "") { $TGNP{$one} = $TGNP{$one}."#".$i;} else { $TGNP{$one} = $i;}
if($TGNP{$two} ne "") { $TGNP{$two} = $TGNP{$two}."#".$i;} else { $TGNP{$two} = $i;}
if($TGNP{$three} ne "") { $TGNP{$three} = $TGNP{$three}."#".$i;} else { $TGNP{$three} = $i;}
if($TGNP{$four} ne "") { $TGNP{$four} = $TGNP{$four}."#".$i;} else { $TGNP{$four} = $i;}
}
elsif(/person:3_e_3_na_ba:/) { 
$one = $_;
$two = $_;
$three = $_;
$one =~ s/person:3_e_3_na_ba/person:3_pu_e/;
$two =~ s/person:3_e_3_na_ba/person:3_\~_pu_e/;
$three =~ s/person:3_e_3_na_ba/person:3_na_ba/;
if($TGNP{$one} ne "") { $TGNP{$one} = $TGNP{$one}."#".$i;} else { $TGNP{$one} = $i;}
if($TGNP{$two} ne "") { $TGNP{$two} = $TGNP{$two}."#".$i;} else { $TGNP{$two} = $i;}
if($TGNP{$three} ne "") { $TGNP{$three} = $TGNP{$three}."#".$i;} else { $TGNP{$three} = $i;}
}
elsif(/person:2_e_3_na_ba:/) { 
$one = $_;
$two = $_;
$three = $_;
$one =~ s/person:2_e_3_na_ba/person:2_e/;
$three =~ s/person:2_e_3_na_ba/person:3_na_ba/;
if($TGNP{$one} ne "") { $TGNP{$one} = $TGNP{$one}."#".$i;} else { $TGNP{$one} = $i;}
if($TGNP{$two} ne "") { $TGNP{$two} = $TGNP{$two}."#".$i;} else { $TGNP{$two} = $i;}
if($TGNP{$three} ne "") { $TGNP{$three} = $TGNP{$three}."#".$i;} else { $TGNP{$three} = $i;}
}
elsif(/person:2_ba_3_non_na_ba:/) { 
$one = $_;
$two = $_;
$one =~ s/person:2_ba_3_non_na_ba/person:2_ba/;
$two =~ s/person:2_ba_3_non_na_ba/person:3_\~_na_ba/;
if($TGNP{$one} ne "") { $TGNP{$one} = $TGNP{$one}."#".$i;} else { $TGNP{$one} = $i;}
if($TGNP{$two} ne "") { $TGNP{$two} = $TGNP{$two}."#".$i;} else { $TGNP{$two} = $i;}
}
else
{
if($TGNP{$_} ne "") { $TGNP{$_} = $TGNP{$_}."#".$i;} else { $TGNP{$_} = $i;}
}
#print $TGNP{$_},$i,"\n";
$i++;
}
if($ARGV[0] ne "GDBM"){ untie(%TGNP);}
else {dbmclose(TGNP);}
