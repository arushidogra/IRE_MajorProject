from Tokeniser import tokenizer
import json
from sklearn.feature_extraction.text import TfidfVectorizer

test = open("test_data.dat","r")
######KNN#########

results = open("results.txt","a")
acc = open("accuracy.txt","a")
k = 9
total = 0
correct = 0
while True:
    line_test = test.readline()
    if line_test=='':
        break
    else:
        dict_test = json.loads(line_test)
        if dict_test.has_key('mCategory'):
            train = open("train_data.dat","r")
            l1=[]
            while True:
                line_train = train.readline()
                if line_train=='':
                    break
                dict_train = json.loads(line_train)
                if dict_train.has_key('mCategory'):
                    vect = TfidfVectorizer(min_df=1)
                    tfidf = vect.fit_transform([dict_test['text'],dict_train['text']])
                    a = (tfidf * tfidf.T).A
                    #print "a",
                    l1.append([a[0,1],dict_train['mCategory']])
                line_train = train.readline()
            l1.sort()
            l1.reverse()
            l1 = l1[:k]
            print "."
            #print l1
            tmp_dic = {}
            for i in l1:
                if tmp_dic.has_key(i[1]):
                    tmp_dic[i[1]] = tmp_dic[i[1]] + 1
                else :
                    tmp_dic[i[1]] = 1
            maxi=0
            tag = ""
            for i in tmp_dic.viewitems():
                if(maxi < i[1]):
                   tag = i[0]
                   maxi=i[1]
            print tag + " " +dict_test['mCategory']
            results.write(tag + " " +dict_test['mCategory']+"\n")
            total = total + 1
            if(tag==dict_test['mCategory']):
                correct = correct + 1


Accuracy = float(correct)/total
acc.write(str(Accuracy))
