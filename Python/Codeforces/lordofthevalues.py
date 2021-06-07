
#*Try debugging this crap in python. Hopefully I don't feel like giving up today. 
from copy import deepcopy
numTests = int(input())
for i in range(numTests):
    n = int(input())
    start = input().strip().split(" ")
    end = []
    for k in range(len(start)):
        start[k] = int(start[k])
        end.append(-start[k])
    
    queue = [[start, []]]
    visited = set()
    #!Honestly, [1, 2] is the smallest data set I could think of that will be easy to debug. 
    while (len(queue) > 0):
        curr = queue.pop(0)

        #!Just unexpected quits after reaching the first point. 
        #*Check explicitly whether certain states are reached. 
        '''
        if (curr[0]== [1, 0, 1, 1]):
            print("reached1")
        elif (curr[0]==[1, -1, 1, 1]):
            print('reached2')
        elif (curr[0]==[1, -1, 0, 1]):
            print('reached3')
        elif (curr[0]==[1, -1, -1, 1]):
            print('reached4')
        elif (curr[0]==[1, -1, -1, 0]):
            #*The computer never seems to reach this value. Why?
            print('reached5')
            
        elif (curr[0]==[1, -1, -1, -1]):
            print('reached6')
        elif (curr[0]==[0, -1, -1, -1]):
            print('reached7')
        elif (curr[0]==[-1, -1, -1, -1]):
            print('reached8')
        '''
        if (curr[0]==end):
            print(len(curr[1]))
            for j in range(len(curr[1])):
                print(f"{curr[1][j][0]} {curr[1][j][1]} {curr[1][j][2]}")
            break

        #!It is reaching it but it just repeats too much values so taking so much time. 
        #*Works but just too slow. 
        elif tuple(curr[0]) not in visited:
            visited.add(tuple(curr[0]))
            for a in range(n):
                for b in range(a, n, 1):
                    if (a < b):
                        temp1 = deepcopy(curr)
                        temp2 = deepcopy(curr)
                        temp1[0][a] += temp1[0][b]
                        temp2[0][b] -= temp2[0][a]
                        temp1[1].append([1, a+1, b+1])
                        temp2[1].append([2, a+1, b+1])
                        queue.append(temp1)
                        queue.append(temp2)
    
        

