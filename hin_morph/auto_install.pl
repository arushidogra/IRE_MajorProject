#!/usr/bin/perl
chomp($pwd=`pwd`);
$my_path=$pwd."/anusAraka/hindi/morph_SV";
system("echo Compiling; cp PORT_ANU/install_hnd_morph_test .;chmod +x install_hnd_morph_test;./install_hnd_morph_test 2> ERR");
print "****** Add the following line to your .bash_profile ******\n";
print "PATH=\$PATH:",$my_path,"\n";
