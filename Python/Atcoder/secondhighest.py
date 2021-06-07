
#*Sorting will be easy but definitely can do it linearly. 

n = int(input())

largest = None
second = None
for i in range(n):
    name, height = input().strip().split(" ")
    height = int(height)

    #*We cannot just assign straight up like this since the second largest could come right after the first. 
    if largest == None:
        largest = (height, name)
    elif height > largest[0]:
        largest, second = (height, name), largest
    elif second == None:
        second = (height, name)
    elif height > second[0]:
        second = (height, name)

print(second[1])