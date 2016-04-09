import json
from textblob.classifiers import NaiveBayesClassifier

train = open("train_data.dat","r")
train_vector = []
while True :
    line = train.readline()
    if line == '':
        break
    else:
         dict_train = json.loads(line)
         if(dict_train.has_key('mCategory')):
             train_vector.append((dict_train['text'],dict_train['mCategory']))

test = open("test_data.dat","r")
test_vector = []
while True :
    line = test.readline()
    if line == '':
        break
    else:
         dict_test = json.loads(line)
         if(dict_test.has_key('mCategory')):
             test_vector.append((dict_test['text'],dict_test['mCategory']))

#print train_vector
cl = NaiveBayesClassifier(train_vector)
print cl.accuracy(test_vector)


