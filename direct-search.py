from os import path


def process(query_text, dirname, fnames):
    for fname in fnames:
        abspath = path.abspath(path.join(dirname, fname))
        if not path.isfile(abspath):
            continue
        with open(abspath, 'r') as f:
            if query_text in f.read().replace('\x00', ''):
                print abspath


q = raw_input()
while q:
    path.walk('shakespeare.corpus', process, q)
    q = raw_input()
