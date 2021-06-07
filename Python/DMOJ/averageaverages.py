
#*I really see where this thing is going. 
#*Just create a prefix table so I don't have to iterate so many times. 

n, q = input().strip().split(" ")
n, q = int(n), int(q)
arr = input().strip().split(" ")
curr_sum = 0
table = []
for i in range(len(arr)):
    arr[i] = int(arr[i])
    curr_sum += arr[i]
    table.append(curr_sum)

for i in range(q):
    l, r = input().strip().split(" ")
    l, r = int(l), int(r)
    print(int((table[r-1] - table[l-1] + arr[l-1]) / (r-l+1)))

#*Why not I try this in C++?

