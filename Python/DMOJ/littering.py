n, k = input().strip().split(" ")
n, k = int(n), int(k)
arr = input().strip().split(" ")
for i in range(len(arr)):
    arr[i] = int(arr[i])

arr.sort()
result = 0
for i in range(len(arr)-1, len(arr)-1-k, -1):
    result += arr[i]
print(result)