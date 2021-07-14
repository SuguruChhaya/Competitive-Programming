
#*Might have to use better data structure that list but think about that if I TLE. 

n = int(input())
result = []
queue = []
arr = input().strip().split()
result_num = 0

for i in range(1, 2*n+1, 1):
    if len(queue)==0 or arr[i-1]==queue[0][0]:
        queue.append((arr[i-1], i))
    else:
        result.append((i, queue[0][1]))
        queue.pop(0)
        result_num+=1

print(result_num)

for i in range(result_num):
    print(f"{result[i][0]} {result[i][1]}")

for i in range(0, len(queue), 2):
    print(f"{queue[i][1]} {queue[i+1][1]}")

