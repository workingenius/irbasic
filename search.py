from os import path
import pickle


with open('inverted_index.tmp', 'r') as ivf:
    dictionary = pickle.load(ivf)


q = raw_input()
while q:
    ptr = path.join('shakespeare.index', str(dictionary.get(q)))
    if path.isfile(ptr):
        with open(ptr) as f:
            print f.read()
    else:
        print 'no such word'
    q = raw_input()
