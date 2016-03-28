#!/usr/bin/perl
open(FEATURES,"$ARGV[0]");
$i=1;
while($feature=<FEATURES>)
{
chomp($feature);
if($features{$feature} != NULL)
{
$features{$feature}=$features{$feature} ."#". $i;
$i++;
}
else
{
$features{$feature}=$i;
$i=$i+1;
}
}
close(FEATURES);

$b[1]=$features{"v tam koVn person any "};
print "#define KO ", $b[1],"\n";
$b[2]=$features{"v tam aka_po person any "}; 
$b[3]=$features{"v tam aka_wappu person any "};
$b[4]=$features{"v tam aka_mAnu person any "};
$b[5]=$features{"v tam akuMdA_uMdu person any "}; 
$b[6]=$features{"v tam akuMdA_cUdu person any "}; 
$b[7]=$features{"v tam i_po person any "}; 
$b[8]=$features{"v tam i_vaccu person any "}; 
$b[9]=$features{"v tam i_uMdu person any "}; 
$b[10]=$features{"v tam i_cUdu person any "}; 
$b[11]=$features{"v tam i_wIru person any "}; 
$b[12]=$features{"v tam i_peVttu person any "}; 
$b[13]=$features{"v tam i_pAreVyyi person any "}; 
$b[14]=$features{"v tam i_veVyyi person any "}; 
$b[15]=$features{"v tam a_le person any "}; 
$b[16]=$features{"v tam a_badu person any "}; 
$b[17]=$features{"v tam a_gala person any "}; 
$b[18]=$features{"v tam a_bo person any "};
$b[19]=$features{"v tam a_nAraMBiMcu person any "}; 
$b[20]=$features{"v tam a_neru person any "}; 
$b[21]=$features{"v tam a_bUnu person any "}; 
$b[22]=$features{"v tam a_goru person any "}; 
$b[23]=$features{"v tam a_ivvu person any "}; 
$b[24]=$features{"v tam a_uMdu person any "}; 
$b[25]=$features{"v tam a_manu person any "}; 
$b[26]=$features{"v tam a_walacu person any "}; 
$b[27]=$features{"v tam a_goVttu person any "}; 
$b[28]=$features{"v tam a_beVttu person any "}; 
$b[29]=$features{"v tam a_wagu person any "}; 
$b[30]=$features{"v tam a_gUdu person any "}; 
$b[31]=$features{"v tam a_galugu person any "}; 
$b[32]=$features{"v tam a_wiyyi person any "}; 
$b[33]=$features{"v tam a_joVccu person any "}; 
$b[34]=$features{"v tam a_vaccu person any "}; 
$b[35]=$features{"v tam a_jAlu person any "}; 
$b[36]=$features{"v tam a_paracu person any "}; 
$b[37]=$features{"v tam a_komanu person any "}; 
$b[39]=$features{"v tam a_sAgu person any "}; 
$b[40]=$features{"v tam a_valayu person any "}; 
$b[41]=$features{"v tam a_buxXiputtu person any "}; 
$b[42]=$features{"v tam a_buxXavvu person any "}; 
$b[43]=$features{"v tam a_buxXeVyyi person any "}; 
$b[44]=$features{"v tam wU_po person any "}; 
$b[45]=$features{"v tam wU_vaccu person any "}; 
$b[46]=$features{"v tam wU_uMdu person any "};
$b[47]=$features{"v tam aka_uMdu person any "};
$b[34]=~ s/[0-9]*\#//;
print  "#define AUX_AKA_UMDU ",$b[47],"\n"; 
print  "#define AUX_AKA_PO ",$b[2],"\n";
print  "#define AUX_AKA_WAPPU ",$b[3],"\n";
print "#define AUX_AKA_MANU ",$b[4],"\n"; 
print "#define AUX_AKUMDA_UMDU ",$b[5],"\n"; 
print "#define AUX_AKUMDA_CUDU ",$b[6],"\n"; 
print "#define AUX_I_PO ",$b[7],"\n";
print "#define AUX_I_VACCU ",$b[8],"\n"; 
print "#define AUX_I_UMDU ",$b[9],"\n";
print "#define AUX_I_CUDU ",$b[10],"\n"; 
print "#define AUX_I_WIRU ",$b[11],"\n";  
print "#define AUX_I_PEVTTU ",$b[12],"\n"; 
print "#define AUX_I_PAREVYYI ",$b[13],"\n";  
print "#define AUX_I_VEVYYI ",$b[14],"\n";
print "#define AUX_A_LE ",$b[15],"\n";
print "#define AUX_A_BADU ",$b[16],"\n";
print "#define AUX_A_GALA ",$b[17],"\n";
print "#define AUX_A_BO ",$b[18],"\n";
print "#define AUX_A_NARAMBIMCU ",$b[19],"\n";
print "#define AUX_A_NERU ",$b[20],"\n";
print "#define AUX_A_BUNU ",$b[21],"\n"; 
print "#define AUX_A_GORU ",$b[22],"\n"; 
print "#define AUX_A_IVVU ",$b[23],"\n";
print "#define AUX_A_UMDU ",$b[24],"\n"; 
print "#define AUX_A_MANU ",$b[25],"\n"; 
print "#define AUX_A_WALACU ",$b[26],"\n";  
print "#define AUX_A_GOVTTU ",$b[27],"\n";  
print "#define AUX_A_BEVTTU ",$b[28],"\n";  
print "#define AUX_A_WAGU ",$b[29],"\n";
print "#define AUX_A_GUDU ",$b[30],"\n";
print "#define AUX_A_GALUGU ",$b[31],"\n";
print "#define AUX_A_WIYYI ",$b[32],"\n"; 
print "#define AUX_A_JOVCCU ",$b[33],"\n";
print "#define AUX_A_VACCU ",$b[34],"\n"; 
print "#define AUX_A_JALU ",$b[35],"\n";
print "#define AUX_A_PARACU ",$b[36],"\n";  
print "#define AUX_A_KOMANU ",$b[37],"\n";  
print "#define AUX_A_SAGU ",$b[39],"\n";
print "#define AUX_A_VALAYU ",$b[40],"\n";  
print "#define AUX_A_BUXXIPUTTU ",$b[41],"\n";  
print "#define AUX_A_BUXXAVVU ",$b[42],"\n";
print "#define AUX_A_BUXXEVYYI ",$b[43],"\n"; 
print "#define AUX_WU_PO ",$b[44],"\n";
print "#define AUX_WU_VACCU ",$b[45],"\n";

print "#define AUX_WU_UMDU ",$b[46],"\n";
