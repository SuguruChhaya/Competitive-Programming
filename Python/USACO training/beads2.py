'''
LANG: PYTHON3
TASK: beads
'''



#*My attempt to write a more efficient version of the beads program. 
#*Compare by testing with correct file. 

fin = open("beads.in", "r")
#*We have to consider several other edge cases like:
#*The end results
#*What happens if there is only one "step"
fout = open("beads.out", "w")
numBeads, beads = fin.read().strip().split("\n")
numBeads = int(numBeads)
result = 0

#!There is apparantly an easier O(n) DP solution.
#*Create the arrays I am going to append to.
left = [[0, 0]]

double_beads = beads * 2
for char in double_beads:
    if char == "r":
        left.append([left[-1][0]+1, 0])
    elif char == "b":
        left.append([0, left[-1][1]+1])
    else:
        #*We could do both. 
        left.append([left[-1][0]+1, left[-1][1]+1])


right = [[0, 0]]
for char in double_beads[::-1]:
    #*Going from the right side. 
    if char == "r":
        right.insert(0, [right[0][0]+1, 0])
    elif char == "b":
        right.insert(0, [0, right[0][1]+1])
    else:
        right.insert(0, [right[0][0]+1, right[0][1]+1])

currMax = 0
for i in range(len(left)):
    currMax = max(currMax, max(left[i][0], left[i][1]) + max(right[i][0], right[i][1]))

#*Have to consider the fact that maximum could be 2 * len(bead) and we don't want that. 
m = min(numBeads, currMax)
fout.write(f"{m}\n")
'''
arr = []
for i in range(numBeads):
    arr.append(beads[i])

#!My idea that it wouldn't matter if "w" became "b" or "r" because step will only happen at different index/
#*Kind of incorrect because it will have an impact on indices other than that specific spot. 
#*The whites are causing pain. 
def recursive(i, checkIndex, arr, passed):
    if arr[checkIndex] != "w":
        return arr[checkIndex]
    elif checkIndex == i and passed==True:
        return "r"
    else:
        passed = True
        if checkIndex -1 == -1:
            arr[checkIndex] = recursive(i, len(arr)-1, arr, passed)
        #*Since we are assigning we need different variable to make sure no out of range. 
        else:
            arr[checkIndex] = recursive(i, checkIndex-1, arr, passed)
        
        return arr[checkIndex]
    
print(arr)
for i in range(numBeads):
    checkIndex = i
    passed = False
    recursive(i, checkIndex, arr, passed)
print(arr)
data = []
for i in range(numBeads):
    if arr[i] != arr[i-1]:
        data.append(i)
print(data)
#*Doesn't really matter if the length is 0 or 1. 
if len(data) == 0:
    fout.write(f"{numBeads}\n")

else:
    for i in range(len(data)):
        if i == 0:
            result = max(result, numBeads-data[-1] + data[i] + data[i+1] - data[i])
        elif i == len(data)-1:
            result = max(result, data[i]-data[i-1]+numBeads-data[i]+data[0])
        else:
            result = max(result, data[i]-data[i-1]+data[i+1]-data[i])

    fout.write(f"{result}\n")


fout.close()
'''