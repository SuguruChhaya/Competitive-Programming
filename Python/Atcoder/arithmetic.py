
#*For an arithmetic sequence, easiest is probably to sort. 
arr = input().strip().split(" ")
for i in range(len(arr)):
    arr[i] = int(arr[i])

arr.sort()

if arr[2]-arr[1] == arr[1]-arr[0]:
    print("Yes")
else:
    print("No")