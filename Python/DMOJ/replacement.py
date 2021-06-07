import math
n, p = input().strip().split(" ")
n, p = int(n), int(p)

def give_score(m, cs, e, p):
    return 4 * (math.sqrt(m)) + 3 * (cs ** p) - 4 * e

#*Never mentioned that cannot be negative. 
d = {}
curr_min_score = 9999999999999999999
curr_min_name = None
curr_max_score = -9999999999999999999
curr_max_name = None
for i in range(n):
    name, m, cs, e = input().strip().split(" ")
    m, cs, e = int(m), int(cs), int(e)
    #*Could do in one pass but just get it to pass.
    a = give_score(m, cs, e, p)

    if a < curr_min_score:
        curr_min_name = name
        curr_min_score = a

    if a > curr_max_score:
        curr_max_name = name
        curr_max_score = a

print(f"{curr_max_name} {math.floor(curr_max_score)}")
print(f"{curr_min_name} {math.floor(curr_min_score)}") 

    