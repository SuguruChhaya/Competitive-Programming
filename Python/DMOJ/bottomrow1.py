#*Most intuitive solution based on editorial that simply runs out of memory. 
#*Mainly using 3 data structures. 
#*1. 2D array that stores non-blocked (".") and blocked ("#"): arr[row][col] (Accomodate for 1-index by subtracting 1 when accessing arr elements.)
#*2. Dictionary that stores 1-indexed index of blocked elements in the form of key:value = col:row (since we are more interested in column of blocked rather than row).
#*3. An array that stores the sorted keys of the dictionary. 
#*In the first while loop, I loop to find any downward diagonal blocked cells. Like the one below:
'''
....
.#..
..#.
...#
'''
#*Then I simply blocked the outlines so it looked like this:
'''
....
.#xx
.##x
.###
'''
#*Since I am never moving down or to the left, I didn't bother to cover the top right outline. (I didn't cover places marked with x)

#*The second loop is more complicated. 
#*I check for places I should cover, iterating from the rightmost column. Some examples based on editorial:
'''
....    ....
..#.    ..#.
...# -> ..##
....    ..#x (x doesn't specifically have to be covered as long as outline is covered)
'''

'''
....    ....
...# -> ...# 
....    ...#
..#.    ..#x 
'''
#*Look at the code below for more specific instructions and cases. 

#*After I marked all the cells I cannot move to, I greedly starting choosing. 
#*But memory error. 
#*Some optimizations I thought of but weren't successful. 
#*1. Really, we don't need to store all the non-blocked cells since we only care whether a cell is blocked. So I thought maybe I could eliminate the big array and just store all the (row, col) in a hashset or something.
#*Result: Passed the first test case but TLE for the second. Probably because I cannot immediately tell whether a cell is blocked or not since I have to do a lookup in the hashset. If I had the array, I can just check using row, col info but I cannot do that using a hashset. 
#*2. Use an array instead of a dictionary to store blocked celled. In this case blocked_arr[col] = row. This elminated the need for the sorted key arr (data structure 2 at the top of file) since I already have them in order. 
#*Result: Not much of a difference in memory usage and still MLE. 
#*3. I realized that if at the beginning a column doesn't have a blocked cell, it can never have it in the future. For the 2D array, instead of arr[row][col], I changed it to arr[col][row] and for columns without blocked cell, I just kept an empty arr. I tried not to waste memory on "." as much as possible. 
#*Result: Again, not much of difference in memory usage and still MLE. 

#*Please give me ideas on how I can optimize this program further to past second test case. 

def main(arr, d):
    all_keys = sorted(list(d.keys()))
    a = len(all_keys) - 1 #bottom right
    b = len(all_keys) - 2 #top left
    prev = len(all_keys) - 1
    while b >= 0:
        while b >= 0  and d[all_keys[b]] == d[all_keys[prev]]+1:
            prev = b
            b -= 1
        a_col = all_keys[a]
        a_row = d[a_col]
        b_col = all_keys[b+1]
        b_row = d[b_col]
        for row in range(a_row, b_row):
            arr[row-1][b_col-1] = "#"
        for col in range(b_col, a_col):
            arr[a_row-1][col-1] = "#"
        a = b
        prev = a
        b -= 1
    
    a = len(all_keys) - 2
    prev = len(all_keys) - 1
    while a >= 0 and all_keys[a] == all_keys[prev] - 1 and d[all_keys[a]] <= d[all_keys[prev]]+1:
        a_col = all_keys[a]
        a_row = d[a_col]
        prev_col = all_keys[prev]
        prev_row = d[prev_col]
        for row in range(a_row, prev_row):
            arr[row-1][prev_col-1] = "#"
        prev =a 
        a -= 1
    #!Cannot use the non-updated version of prev_col. 
    if len(all_keys) >= 1:
        for row in range(1, d[all_keys[prev]]+1):
            arr[row-1][all_keys[prev]-1] = "#"
    curr = [1, 1]
    result = []
    while curr != [len(arr), len(arr)]:
        if curr[1]+1 <= len(arr) and arr[curr[0]-1][curr[1]+1-1] != "#":
            result.append("R")
            curr[1] +=1
            
        elif curr[0]+1 <= len(arr) and arr[curr[0]+1-1][curr[1]-1] != "#":
            result.append("U")
            curr[0] +=1
        else:
            return "IMPOSSIBLE"
    return "".join(result)

n, k = input().strip().split(" ")
n, k = int(n), int(k)

arr = []
d = {}
for i in range(n):
    arr.append(["."] * n)
for i in range(k):
    row, col = input().strip().split(" ")
    row, col = int(row), int(col)
    arr[row-1][col-1] = "#"
    d[col] = row
print(main(arr, d)) 