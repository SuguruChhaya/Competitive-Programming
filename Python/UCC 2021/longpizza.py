



#*Just brute force add it. 
#!But this may run out of time. 
#*10^7 kind of concerns me.     

def main(s, arr):
    result = 0
    for i in arr:
        if i[0] <= s[0]:
            #!Excluding the outside cases. 
            if s[0] <= i[1]: 
                result += (min(s[1], i[1]) - s[0] + 1)
        elif s[0] < i[0] <= s[1]:
            result += (min(s[1], i[1]) - i[0] + 1)
    return result

numSlices = int(input())
s = input().strip().split(" ")
s[0], s[1] = int(s[0]), int(s[1])
len_arr = int(input())
arr = []
for i in range(len_arr):
    temp = input().strip().split(" ")
    temp[0], temp[1] = int(temp[0]), int(temp[1])
    arr.append(temp)

print(main(s, arr))