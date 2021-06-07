
#*These are the ones that I actually should be doing for prep. 

def main(n, m, d, arr):
    total_level = 0
    for i in range(n):
        for j in range(m):
            #*Check how many apart property here. 
            if (arr[i][j] - arr[0][0]) % d != 0:
                return -1
            #*How will I know what number to adjust to??
            #*We can add it to some counter and get the average. 
            total_level += int((arr[i][j] - arr[0][0]) / d)

    set_num = round(total_level / (n*m), 0)
    result = 0
    for i in range(n):
        for j in range(m):
            result += (abs((set_num - arr[i][j])))

            
#*If all the elements aren't multiple of d apart from each other, adjusting will be impossible. 

n, m, d = input().strip().split(" ")
arr = []
for i in range(n):
    temp = input().strip().split(" ")
    for j in range(len(temp)):
        temp[j] = int(temp[j])
    arr.append(temp)

print(main(n, m, d, arr))