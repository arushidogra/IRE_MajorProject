while($in = <STDIN>){
$DBG = $ARGV[0];
if($ARGV[1] eq "U") {$USER_FRIENDLY = 1;} else { $USER_FRIENDLY = 0;}

chop($in);
$orig = $in;
$in =~ s/Z//g; ## Always words are written without nukwA in anusAraka hindi dict.
$ans = "";
$in =~ s/([EeoOiI])M/\1z/g;

open(TMP,">tmp");
print TMP $in;
close(TMP);
if($USER_FRIENDLY) {
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/mohu.sh < tmp >tmp.r");
}else{
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/moh.sh < tmp >tmp.r");
}
open(TMP,"<uword");
$ans = <TMP>;
close(TMP);
if($ans =~ /./){
  $in = $orig;
  $in =~ s/([aeiouAEIOU])([eiI])$/\1y\2/g;	# y insertion as in gae/gaye
  open(TMP,">tmp");
  print TMP $in;
  close(TMP);
if($USER_FRIENDLY) {
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/mohu.sh < tmp >tmp.r");
}else{
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/moh.sh < tmp >tmp.r");
}
  open(TMP,"<uword");
  $ans = <TMP>;
  if($DBG eq 'D') { print $ans;}
  close(TMP);
    if($ans =~ /./){
      $in = $orig;	
      $in =~ s/M([kKgG])/f\1/g;
      $in =~ s/M([cCjJ])/F\1/g;
      $in =~ s/M([tTdD])/N\1/g;
      $in =~ s/M([wWxX])/n\1/g;
      $in =~ s/M([pPbB])/m\1/g;
      open(TMP,">tmp");
      print TMP $in;
      close(TMP);
if($USER_FRIENDLY) {
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/mohu.sh < tmp >tmp.r");
}else{
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/moh.sh < tmp >tmp.r");
}
      open(TMP,"<uword");
      $ans = <TMP>;
      if($DBG eq 'D') { print $ans;}
      if($ans =~ /./){
        $in = $orig;
        $in =~ s/f([kKgG])/M\1/g;
        $in =~ s/F([cCjJ])/M\1/g;
        $in =~ s/N([tTdD])/M\1/g;
        $in =~ s/n([wWxX])/M\1/g;
        $in =~ s/m([pPbB])/M\1/g;
        open(TMP,">tmp");
        print TMP $in;
        close(TMP);
if($USER_FRIENDLY) {
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/mohu.sh < tmp >tmp.r");
}else{
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/moh.sh < tmp >tmp.r");
}
        open(TMP,"<uword");
        $ans = <TMP>;
	if($DBG eq 'D') { print $ans;}
        close(TMP);
        if($ans =~ /./){
          $in = $orig;
          $in =~ s/M/z/g;
          open(TMP,">tmp");
          print TMP $in;
          close(TMP);
if($USER_FRIENDLY) {
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/mohu.sh < tmp >tmp.r");
}else{
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/moh.sh < tmp >tmp.r");
}
          open(TMP,"<uword");
          $ans = <TMP>;
	  if($DBG eq 'D') { print $ans;}
          close(TMP);
          if($ans =~ /./){
            $in = $orig;
            $in =~ s/$/H/g;
            open(TMP,">tmp");
            print TMP $in;
            close(TMP);
if($USER_FRIENDLY) {
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/mohu.sh < tmp >tmp.r");
}else{
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/moh.sh < tmp >tmp.r");
}
            open(TMP,"<uword");
            $ans = <TMP>;
	    if($DBG eq 'D') { print $ans;}
            close(TMP);
            if($ans =~ /./){
              $in = $orig;
              $in =~ s/([kctwpKCTWPgjdxbGJDXBfFNnmyrlvsSRh])a$/\1/g;
              open(TMP,">tmp");
              print TMP $in;
              close(TMP);
if($USER_FRIENDLY) {
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/mohu.sh < tmp >tmp.r");
}else{
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/moh.sh < tmp >tmp.r");
}
              open(TMP,"<uword");
              $ans = <TMP>;
	      if($DBG eq 'D') { print $ans;}
              close(TMP);
              if($ans =~ /./){
                $in = $orig;
                $in =~ s/iyAM$/iyAz/;
                open(TMP,">tmp");
                print TMP $in;
                close(TMP);
if($USER_FRIENDLY) {
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/mohu.sh < tmp >tmp.r");
}else{
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/moh.sh < tmp >tmp.r");
}
                open(TMP,"<uword");
                $ans = <TMP>;
	        if($DBG eq 'D') { print $ans;}
                close(TMP);
                if($ans =~ /./){
                  $in = $orig;
                  $in =~ s/Q/q/g;
                  open(TMP,">tmp");
                  print TMP $in;
                  close(TMP);
if($USER_FRIENDLY) {
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/mohu.sh < tmp >tmp.r");
}else{
system("/home/arushi/Desktop/MajorProject/temp_pr/IRE_MajorProject/hin_morph/anusAraka/hindi/morph/test/moh.sh < tmp >tmp.r");
}
                  open(TMP,"<uword");
                  $ans = <TMP>;
	          if($DBG eq 'D') { print $ans;}
                  close(TMP);
                  if($ans =~ /./){
		    print "$orig,$orig<ajFAwa>\n";
         	  }
	          else { print $orig,",RL 9: $in:";open(TMP,"<tmp.r"); $ans = <TMP>; close(TMP); print $ans;}
         }
	else { print $orig,",RL 8: $in:";open(TMP,"<tmp.r"); $ans = <TMP>; close(TMP); print $ans;}
       }
	else { print $orig,",RL 7: $in:";open(TMP,"<tmp.r"); $ans = <TMP>; close(TMP); print $ans;}
      }
	else { print $orig,",RL 6: $in;";open(TMP,"<tmp.r"); $ans = <TMP>; close(TMP); print $ans;}
     }
	else { print $orig,",RL 5: $in:";open(TMP,"<tmp.r"); $ans = <TMP>; close(TMP); print $ans;}
    }
	else { print $orig,",RL 4: $in:";open(TMP,"<tmp.r"); $ans = <TMP>; close(TMP); print $ans;}
   }
	else { print $orig,",RL 3: $in:";open(TMP,"<tmp.r"); $ans = <TMP>; close(TMP); print $ans;}
  }
	else { print $orig,",RL 2: $in:";open(TMP,"<tmp.r"); $ans = <TMP>; close(TMP); print $ans;}
 }
 else { print $orig,",RL 1: $in:";open(TMP,"<tmp.r"); $ans = <TMP>; close(TMP); print $ans;}
}
