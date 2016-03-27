# -*- coding: utf-8 -*-

#!/usr/bin/env python


import sys
import os

if __name__ == '__main__':
    suffixes = {1: ["ो", "े", "ू", "ु", "ी", "ि", "ा"],2: ["कर", "ाओ", "िए", "ाई", "ाए", "ने", "नी", "ना", "ते", "ीं", "ती", "ता", "ाँ", "ां", "ों", "ें"],3: ["ाकर", "ाइए", "ाईं", "ाया", "ेगी", "ेगा", "ोगी", "ोगे", "ाने", "ाना", "ाते", "ाती", "ाता", "तीं", "ाओं", "ाएं", "ुओं", "ुएं", "ुआं"],4: ["ाएगी", "ाएगा", "ाओगी", "ाओगे", "एंगी", "ेंगी", "एंगे", "ेंगे", "ूंगी", "ूंगा", "ातीं", "नाओं", "नाएं", "ताओं", "ताएं", "ियाँ", "ियों", "ियां"],5: ["ाएंगी", "ाएंगे", "ाऊंगी", "ाऊंगा", "ाइयाँ", "ाइयों", "ाइयां"]}
    tag = [1,2,3,4,5]
    if len(sys.argv) < 3:
        sys.stderr.write("Usage: " + sys.argv[0] + " <corpusfile> <outputfile>\n")
        sys.exit(2)
    print sys.argv
    print sys.argv[2]
    
    fopen = open(sys.argv[1],"r")
    oopen = open(sys.argv[2],"w")
    output = ""
    while True:
        line = fopen.readline()
	if line=='':
            break
	line = line[0:-1]
        for word in line.split():
            for L in tag:
                if len(word) > L + 1:
                    for suf in suffixes[L]:
                        if word.endswith(suf):
                            output = output + word[:-L]+ "\n"
    print output
    a = "echo \"" +  output + "\" >> " + sys.argv[2]                       
    os.system(a)
    oopen.close()
    fopen.close()
