#from Tokeniser import HindiTokenizer

import json


train = open("train_data.dat","r")

line = train.readline()
no_of_documents = 0

while line!='':
    cat = open("category.txt","a")
    if line == '':
        break
    else:
        dicti = json.loads(line)
        if dicti.has_key('mCategory'):
            cat.write(dicti['mCategory']+"\n")
            no_of_documents  = no_of_documents + 1
    line = train.readline()
    cat.close()

train.close()


