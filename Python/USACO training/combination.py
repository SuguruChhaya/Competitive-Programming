
#*Based on the namenum problem, I want to tackle the permutation (or combination) problem. 



#*Permutation is order-sensitive. 

def permutation(curr, result, used):
    if len(curr) == l:
        result.add(tuple(sorted(curr)))
        return
    else:
        #*I think the used set is working for the others as well. 
        for i in arr:
            #*I think a new set should be created whever the string is empty. 
            if len(curr) == 0:
                check_set = set()
            else:
                check_set = used
            if i not in used:
                temp = curr + [i]
                check_set.add(i)
                permutation(temp, result, check_set)
                
arr = [1, 2, 3, 4]
l = 2
result = set()
used = set() 
permutation([], result, used)
print(result)
'''
from itertools import combinations
a = combinations(arr, l)
for i in list(a):
    print(i)
'''