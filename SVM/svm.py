# -*- coding: utf-8 -*-

#1600 400
import json
import numpy as np
from sklearn.pipeline import Pipeline
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.svm import LinearSVC
from sklearn.feature_extraction.text import TfidfTransformer
from sklearn.multiclass import OneVsRestClassifier
from sklearn import preprocessing

filename = open("../hi.data","r")
start = 0

#Data
X_train = []
#Class-labels
Y_train = []

#Data
X_test = []
#Class-labels
Y_test = []

#Possible Class-labels
target_names = []

while True:
    line = filename.readline()
    if line == '' or start>210463:
        break
    dict_train = json.loads(line)
    if dict_train.has_key('mCategory'):	
    	if start < 168000:
        	X_train.append(dict_train['text'])
        	Y_train.append([dict_train['mCategory']])
    	else:
        	X_test.append(dict_train['text'])
        	Y_test.append([dict_train['mCategory']])
        categ = dict_train['mCategory']
        if categ not in target_names:
        	target_names.append(categ)
    start = start + 1

X_train = np.array(X_train)
X_test= np.array(X_test)
y_train_text = Y_train

lb = preprocessing.MultiLabelBinarizer()
Y = lb.fit_transform(y_train_text)

classifier = Pipeline([
    ('vectorizer', CountVectorizer()),
    ('tfidf', TfidfTransformer()),
    ('clf', OneVsRestClassifier(LinearSVC()))])


classifier.fit(X_train, Y)
predicted = classifier.predict(X_test)
all_labels = lb.inverse_transform(predicted)

true_count = 0
total_count = 0

print "All labels : " + str(len(all_labels))
print "Y_test:  " + str(len(Y_test))

for i in range(len(all_labels)):
	#print all_labels[i]
	#print Y_test[i]
	if len(all_labels[i]) != 0:
		if all_labels[i][0] == Y_test[i][0]:
			true_count += 1
	total_count+=1

accuracy = (float(true_count)/total_count)*100
print "accuracy is  : " + str(accuracy)

'''
for labels in zip(X_test, all_labels):
    print '%s => %s' % (item, ', '.join(labels))
'''
filename.close()
