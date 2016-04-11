# Cracking the Coding Interview
# Problem 9.4

def generate_sets(s):
    set_list = [set()]
    for elem in s:
        new_sets = []
        for cur_set in set_list:
            new_set = set(cur_set)
            new_set.add(elem)
            new_sets.append(new_set)
        set_list.extend(new_sets)
    return set_list


base = set([1,2,3,4])
out = generate_sets(base)
for o in out:
    print o
