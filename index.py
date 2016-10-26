from os import path
import pickle

dictionary = {}


def process(arg, dirname, fnames):
    for fname in fnames:
        abspath = path.abspath(path.join(dirname, fname))
        if path.isfile(abspath):
            with open(abspath) as f:
                build(abspath, f.read().decode('latin1'))


def build(id, text):
    for word in set(text.split()):
        word = word.replace('\x00', '').lower()

        if dictionary.has_key(word):
            dictionary[word].append(id)
        else:
            dictionary[word] = [id]


path.walk('shakespeare.corpus', process, None)
for word in dictionary:
    dictionary[word] = sorted(dictionary[word])


for id, word in enumerate(dictionary):
    with open(path.join('shakespeare.index', str(id)), 'w') as f:
        f.write('\n'.join(dictionary[word]))
    dictionary[word] = id


with open('inverted_index.tmp', 'w') as ivf:
    pickle.dump(dictionary, ivf)
