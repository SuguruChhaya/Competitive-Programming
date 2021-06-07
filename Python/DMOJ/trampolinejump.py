n = input()
n = int(n)

arr = input().strip().split(" ")
prefix_sum = []
#*OK not ACing last batch is expected. 
for i in range(len(arr)):
    arr[i] = int(arr[i])
    if i==0:
        prefix_sum.append(arr[i])
    else:
        prefix_sum.append(arr[i]+prefix_sum[i-1])
result_arr = []
for i in range(n):
    arr.append(arr[i])
    prefix_sum.append(arr[-1]+prefix_sum[-1])

for i in range(n):
    curr_min = 9999999999999999999999999
    curr_split = i
    for j in range(n):
        team_a = prefix_sum[curr_split] - prefix_sum[i] + arr[i]
        curr_min = min(curr_min, abs(team_a - (prefix_sum[n-1]-team_a)))
        curr_split+=1
    result_arr.append(str(curr_min))

print(" ".join(result_arr))