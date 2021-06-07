
#*A little bit of a tricky problem to be marked as A but a lot of info tho. 
#*Seems like it would definitely involve some %. 
#*Could run a for loop until 5 and check. 

numFriends = int(input())
arr = input().strip().split(" ")

for i in range(len(arr)):
    arr[i] = int(arr[i])

result = []
s = sum(arr)
for j in range(1,6):
    if (j + s) % (numFriends + 1) != 1:
        result.append(j)

print(len(result))