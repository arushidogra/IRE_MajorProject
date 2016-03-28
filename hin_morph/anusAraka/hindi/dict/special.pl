while($in = <STDIN>){
      $in =~ s/f([kKgG])/M\1/g;        
      $in =~ s/([^j])F([cCjJ])/\1M\2/g;        
      $in =~ s/N([tTdD])/M\1/g;        
      $in =~ s/n([wWxX])/M\1/g;        
      $in =~ s/m([pPbB])/M\1/g;        
      $in =~ s/z/M/g;
print $in;
}
