from Tokeniser import tokenizer
import json
train = open("train_data.dat","r")
total_tokens={}
line = train.readline()
no_of_documents = 0
gaya=open('trainvector.data','a')
purra=open('totaltokens.data','a')
number=open('no_of_docs.data','a')
while line!='':
    cat = open("category.txt","a")
    if line == '':
        break
    else:
        dicti = json.loads(line)
        tokens_list=[]
        if dicti.has_key('mCategory'):
            cat.write(dicti['mCategory']+"\n")
            no_of_documents  = no_of_documents + 1
            tokens_list=tokenizer.string_tokenize(dicti['text'])

        token={}
        for i in tokens_list:
        	if token.has_key(i):
        		token[i]+=1
        	else:
        		token[i]=1

        for i in tokens_list:
        	if total_tokens.has_key(i):
        		total_tokens[i]+=1
        	else:
        		total_tokens[i]=1

    line = train.readline()
    gaya.write(json.dumps(token))
purra.write(json.dumps(total_tokens))
number.write(str(no_of_documents))
cat.close()
#print tokens
train.close()