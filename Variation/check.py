# -*- coding: utf-8 -*-
import sys
import translit 
import soundex
import io

if __name__ == "__main__":
    if len(sys.argv) < 3:
        sys.stderr.write("Usage: " + sys.argv[0] + " word1 word2\n " )
        sys.exit(2)
    word1 = io.open(sys.argv[1],encoding="utf8")
    word2 = io.open(sys.argv[2],encoding="utf8")
    word1 = word1.read()[:-1]
    word2 = word2.read()[:-1]	  
    '''
    a = translit.Transliterator()
    a = a.transliterate_indic_en(word1,"hi_IN")
    b = translit.Transliterator()
    b = b.transliterate_indic_en(word2,"hi_IN")
    print a, b
    '''
    
    a = soundex.Soundex()
    
    a = a.compare(word1,word2)
    
    print a
    if a==1:
        print "phonetically same"
    else :
        print "no"
    '''
    if a==b:
        print "same"
    else:
        print "not same"
    '''
        #TODO 
        #Check wikinet and edit distance with rules
    #b = Transliterator().transliterate(word2,"en_US")
    #print a,b
        
