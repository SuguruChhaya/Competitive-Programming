
#numTests = int(input())
arr = []
for i in range(5):
    arr.append(input().strip().split(" "))

for i in range(5):
    for j in range(5):
        if arr[i][j] == "1":
            print(abs(i-2) + abs(j-2))
