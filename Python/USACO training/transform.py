'''
LANG: PYTHON3
TASK: transform
'''
#*Doesn't tell us whether "@" is black or white but doesn't really matter. 
#*I think the whole point here is to notice how 
#2 90 degrees -> 180
#2 180 degrees -> No change
#!Horizontal reflection DOESN'T mean 180degree rotation. However, 2 reflections will give same as original. 
#Invalid: We must know this in one move so after we transformed in all possible ways
#!Actually even when valid and invalid, there will be one report. 
#*So just 1. 
#*Anything can be reached in 1 move but I have to print what move it is. 
#*Generate all possible moves. 
fin = open("transform.in", "r")
fout = open("transform.out", "w")
info = fin.read().strip().split("\n")
#*Need to also collect the correct pattern. 

n = int(info[0])
arr = []
curr_row = 1
for row in range(n):
    temp = []
    for col in range(n):
        temp.append(info[curr_row][col])
    arr.append(temp)
    curr_row += 1

final = []
for row in range(n):
    temp = []
    for col in range(n):
        temp.append(info[curr_row][col])
    final.append(temp)
    curr_row += 1



def rotate90(arr):
    result = []
    for col in range(n):
        temp = []
        for row in range(n-1, -1, -1):
            temp.append(arr[row][col])
        result.append(temp)
    return result

def flip(arr):
    result = arr.copy()
    for row in range(n):
        left = 0
        right = n-1
        while left < right:
            result[row][left], result[row][right] = result[row][right], result[row][left]
            left += 1
            right -= 1
    return result

#all_arr = []
zero = arr
ninety = rotate90(arr)
hunderedeighty = rotate90(ninety)
twoseventy = rotate90(hunderedeighty)
flipped = flip(arr)
#*Not too sure if combinations can replace reflection but I think fine. 
flipped_ninety = rotate90(flipped)
flipped_180 = rotate90(flipped_ninety)
flipped_270 = rotate90(flipped_180)

#!Probably easier to store in dictionary and consult each. 
d = {
    "1": [ninety],
    "2": [hunderedeighty],
    "3": [twoseventy],
    "4": [flipped],
    "5": [flipped_ninety, flipped_180, flipped_270],
    "6": [zero]
}
result = "7"
#!I mean the incorrect testcase could be both 180 and flipped 180. 
#*I have to run it in order. 
for i in sorted(d.keys()):
    if final in d[i]:
        result = i
        #*Could be in multiple but just break after finding. 
        break
fout.write(f"{result}\n")
fout.close()