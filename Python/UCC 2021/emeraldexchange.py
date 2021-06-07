
#*A ton of these types of array problems. Kind of like max contiguous subarray but with odd property. 
#*Can linearly iterate and add or set to 0. 

def main(arr):
    table = []
    for i in range(len(arr)):
        if i == 0:
            if arr[i] % 2 == 0:
                table.append(arr[i])
            else:
                table.append(0)
        else:
            if arr[i] % 2 == 0:
                table.append(table[-1] + arr[i])
            else:
                table.append(0)

    return max(table)
    
numEmeralds = int(input())
arr = input().strip().split(" ")
for i in range(len(arr)):
    arr[i] = int(arr[i])

print(main(arr))