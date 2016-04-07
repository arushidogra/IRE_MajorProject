import sys
reload(sys)
sys.setdefaultencoding('UTF-8')
import nltk

def file_tokenize(filename):
    
    text = open(filename).read()
    text = text.decode("utf-8")
    tokens = nltk.word_tokenize(text)
    return tokens

def string_tokenize(string):
    text = string.decode("utf-8")
    tokens = nltk.word_tokenize(text)
    return tokens
