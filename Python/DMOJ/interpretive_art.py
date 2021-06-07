from copy import deepcopy
#*If hard to debug in C++, will do it in Python. 

def custom_sort(arr, l, h):
    #*l and h include the index. 
    temp = []
    for i in range(l, h+1):
        temp.append(arr[i])
    temp.sort()
    curr = 0
    for i in range(l,h+1):
        arr[i] = temp[curr]
        curr+=1
    return arr

n = input()
n = int(n)

a_num = 0
b_num = 0

a = input().strip().split(" ")
b = input().strip().split(" ")
for i in range(n):
    if a[i] == '0':
        a_num+=1

for i in range(n):
    if b[i] == '0':
        b_num+=1

if a_num != b_num:
    print(-1)
else:
    queue = [[a, []]]
    while len(queue) > 0:
        curr = queue.pop()
        if (curr[0]==b):
            print(len(curr[1]))
            for i in range(len(curr[1])):
                print(f"{curr[1][i][0]} {curr[1][i][1]}")
            break
        else:
            for i in range(len(curr[0])):
                for j in range(i, len(curr[0]), 1):
                    temp = deepcopy(curr)
                    custom_sort(temp[0], i, j)
                    temp[1].append([i, j])
                    #*Why do I just don't seem to reach the correct answer?
                    queue.append(temp)
                
