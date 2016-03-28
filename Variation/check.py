# -*- coding: utf-8 -*-
import sys
import translit 

if __name__ == "__main__":
    if len(sys.argv) < 3:
        sys.stderr.write("Usage: " + sys.argv[0] + " word1 word2\n " )
        sys.exit(2)
    word1 = sys.argv[1]
    word2 = sys.argv[2]
    a = translit.Transliterator()
    a = a.transliterate_xx_en(word1,"hi_IN")
    b = translit.Transliterator()
    b = b.transliterate_xx_en(word2,"hi_IN")
    if a==b:
        print "same"
    else:
        print "not same"
        #TODO 
        #Check wikinet and edit distance with rules
    #b = Transliterator().transliterate(word2,"en_US")
    #print a,b
        
