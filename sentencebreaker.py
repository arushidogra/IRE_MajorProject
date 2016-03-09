# -*- coding: utf-8 -*-
'''
Tokeniser for hindi
'''
from HindiTokenizer import Tokenizer
import sys
if __name__ == "__main__":
    if len(sys.argv) < 2:
        sys.stderr.write("Usage: " + sys.argv[0] + " <corpusfile>\n")
        sys.exit(2)
    file_name = sys.argv[1]
    fopen = open(file_name, "r")
    a = open("output_sentences.txt", "w")
    while True:
        line = fopen.readline()[0:-1]
        if line == '':
            break
        else:
            t = Tokenizer(line)
            t.generate_sentences()
            for i in t.print_sentences():
                a.write(i+"\n")
                

    a.close()
    fopen.close()
