      cut -d, -f1 dict.final > f1
      perl special.pl < f1 > f2 
## Contents of special.pl
      #$in =~ s/f([kKgG])/M\1/g;
      #$in =~ s/F([cCjJ])/M\1/g;
      #$in =~ s/N([tTdD])/M\1/g;
      #$in =~ s/n([wWxX])/M\1/g;
      #$in =~ s/m([pPbB])/M\1/g;
      #$in =~ s/z/M/g;
cut -d, -f2- dict.final > f3
paste -d, f2 f3 > dict.special
