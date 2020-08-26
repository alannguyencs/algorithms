from collections import defaultdict, OrderedDict

def default_dict():
    cnt = defaultdict(lambda : 0, OrderedDict()) #whatever parameters, return 0

def merge_dict():
    dict_1 = {'a': 1}
    dict_2 = {'b': 2}
    dict_1.update(dict_2)
    print (dict_1)

def add_one(seeds):
    for key in seeds:
        seeds[key] += 1


def test_pointer_v1():
    seeds = {'a': 1, 'b': 0, 'c': 2}
    add_one(seeds)  #this update seeds
    print (seeds)

def test_pointer_v2():
    seeds = {'a': 1, 'b': 0, 'c': 2}
    cp_seeds = seeds
    add_one(cp_seeds)
    print (seeds)

if __name__=='__main__':
    # default_dict()
    merge_dict()
    test_pointer_v1()
    test_pointer_v2()