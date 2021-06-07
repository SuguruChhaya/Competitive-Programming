

#*Easy brute force will be O(N^2) solution which won't pass 10^5 and better will use a dictionary. 

numElements = int(input())
arr = input().strip().split(" ")
d = {}
for i in range(numElements):
    #!Integers are not hashable so store as string. 
    if arr[i] in d:
        d[arr[i]].append(i)
    else:
        d[arr[i]] = [i]

result = 0
result_arr = []
#*In order for the sort to work correctly, I must be converting to int. 
all_arr = []
for i in d.keys():
    all_arr.append(int(i))

all_arr.sort()
for i in range(len(all_arr)):
    all_arr[i] = str(all_arr[i])
for j in all_arr:
    #*Have to check whether in arithmetic sequence. 
    #!Check whether length is 1 or not. 
    dif = 0
    is_arithmetic = True
    if len(d[j]) > 1:
        dif = d[j][1] - d[j][0]
        for a in range(len(d[j])-1):
            if d[j][a] + dif != d[j][a+1]:
                is_arithmetic = False
        
    if is_arithmetic == True:
        result += 1
        result_arr.append(f"{j} {dif}")

print(result)
print("\n".join(result_arr))



