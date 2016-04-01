# -*- coding: utf-8 -*-
'''
Stop words for hindi
I am taking top 50 words
'''
from HindiTokenizer import Tokenizer
import sys
if __name__ == "__main__":
    if len(sys.argv) < 3:
        sys.stderr.write("Usage: " + sys.argv[0] + " <corpusfile> <outputfile>\n")
        sys.exit(2)
    file_name = sys.argv[1]
    fopen = open(file_name, "r")
    a = open(sys.argv[2], "w")
    dic_tok = {}
    while True:
        line = fopen.readline()[0:-1]
        if line == '':
            break
        else:
            t = Tokenizer(line)
            t.tokenize()
            for i in t.print_tokens():
                try:
                    dic_tok[i] += 1
                except KeyError:
                    dic_tok[i] = 1
    final_list = []
    for i in dic_tok.items():
        i = list(i)
        i.reverse()
        final_list.append(i)
    final_list.sort()
    final_list.reverse()
    final_list = final_list[50:]
    for i in final_list:
        a.write(i[1]+"\n")

    a.close()
    fopen.close()
