
def posting_list_and(l1, l2):
    r = []
    i, j = 0, 0
    len1, len2 = len(l1), len(l2)
    while i < len1 and j < len2:
        v1, v2 = l1[i], l2[j]
        if v1 < v2:
            i += 1
        elif v1 == v2:
            r.append(v1)
            i += 1
            j += 1
        elif v1 > v2:
            j += 1
    return r


def posting_list_or(l1, l2):
    r = []
    i, j = 0, 0
    len1, len2 = len(l1), len(l2)
    while i < len1 or j < len2:
        if i >= len1:
            v2 = l2[j]
            r.append(v2)
            j += 1
        elif j >= len2:
            v1 = l1[i]
            r.append(v1)
            i += 1
        else:
            v1 = l1[i]
            v2 = l2[j]
            if v1 < v2:
                r.append(v1)
                i += 1
            elif v1 == v2:
                r.append(v1)
                i += 1
                j += 1
            elif v1 > v2:
                r.append(v2)
                j += 1
    return r


def posting_list_diff(l1, l2):
    r = []
    i, j = 0, 0
    len1, len2 = len(l1), len(l2)
    while i < len1:
        if j >= len2:
            v1 = l1[i]
            r.append(v1)
            i += 1
        else:
            v1, v2 = l1[i], l2[j]
            if v1 < v2:
                r.append(v1)
                i += 1
            elif v1 == v2:
                i += 1
                j += 1
            elif v1 > v2:
                j += 1
    return r


if __name__ == '__main__':
    import random

    MAX = 1000
    I = range(MAX)
    case_count = 100


    def random_posting_list():
        return random.sample(I, random.randint(0, MAX))


    def and_(l1, l2):
        return sorted(set(l1) & set(l2))


    def or_(l1, l2):
        return sorted(set(l1) | set(l2))


    def diff_(l1, l2):
        return sorted(set(l1) - set(l2))


    def comp(testing_func, correct_func, *args):
        testing_result = testing_func(*args)
        correct_result = correct_func(*args)
        assert testing_result == correct_result


    for i in range(case_count):
        pl1 = sorted(random_posting_list())
        pl2 = sorted(random_posting_list())
        args = [pl1, pl2]

        comp(posting_list_and, and_, *args)
        comp(posting_list_or, or_, *args)
        comp(posting_list_diff, diff_, *args)

