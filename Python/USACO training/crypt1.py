'''
LANG: PYTHON3
TASK: crypt1
'''

fin = open("crypt1.in", "r")
fout = open("crypt1.out", "w")

info = fin.read().strip().split("\n")
hashset = set(info[1].split(' '))

def recursive(curr, correct_len, arr):
    if len(curr) == correct_len:
        if curr[0] != "0":
            arr.add(curr)
    else:
        for i in hashset:
            recursive(curr+i, correct_len, arr)
#*Probably should be a set so that duplicates don't end up again. 
#?How exactly can there be duplicates though?
three_digit = set()
two_digit = set()
recursive("", 3, three_digit)
recursive("", 2, two_digit)

result = 0
for i in three_digit:
    for j in two_digit:
        add = True
        #*We actually have to iterate through i and j as well. 
        partial_1 = int(i) * int(j[1])
        partial_2 = int(i) * int(j[0])
        product = int(i) * int(j)
        
        if len(str(partial_1)) == len(str(partial_2)) == 3:
            pass
        else:
            add = False
        for a in str(i):
            if a not in hashset:
                add = False
        for a in str(j):
            if a not in hashset:
                add = False

        for a in str(partial_1):
            if a not in hashset:
                add = False
    
        for a in str(partial_2):
            if a not in hashset:
                add = False

        for a in str(product):
            if a not in hashset:
                add = False
            
        if add == True:
            result += 1

fout.write(f"{result}\n")
fout.close()

