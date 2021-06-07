

#*For this question,I think I can do linear search and 
#*There is just too much uncertainty to brute force everything (number of cookies, the bowl he is moving from, the bowl he is moving to).

#*Current standing does mean something right?
#*Maybe I can just identify the number we want the cookie to be and check for numbers so that they don't exceed. 
#*No overflow limit. 

def main(arr, d):
    #*Just construct an array with the frequency and number reversed and sort based on that. 
    #!This is where I got the problem wrong!! All ai are unique so there can only be 1 frequency!!
    new_arr = []
    for i in d.keys():
        new_arr.append((d[i], i))
    new_arr.sort()

    #*I don't even know how many I really should check...
    #*Let me just check values with largest frequency since I can intuitively tell that they could have greater values. 
    #*second largest + 2 may exceed largest frequency so I could also check the largest one. 
    



def main(arr):
    #*Just check whether I can find an arithmetic sequence of length 3. 
    #*Brute force will be to loop through all the elements using 3 pointer. 
    #*Better will be to store in set and find missing value. 
    hashset = set(arr)

    if len(arr) == 2:
        if sum(arr) % 2 == 0:
            return 2
        else:
            return 1
    for i in arr:
        for j in arr:
            if i!=j and ((i+j) / 2) in hashset:
                return 3
    return 2

n = input()
arr = input().strip().split(" ")

for i in range(len(arr)):
    arr[i] = int(arr[i])
    #*Input the frequency in the dictionary. 
print(main(arr))