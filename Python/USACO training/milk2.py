'''
LANG: PYTHON3
TASK: milk2
'''

#*Very common type of problem:
#Cameron problem
#*Interval problem in leetcode. 
#*First try sorting based on start time and 

fin = open("milk2.in", "r")
fout = open('milk2.out', "w")

info = fin.read().strip().split("\n")
num_intervals = int(info[0])
arr = []
for i in range(num_intervals):
    #*First split it based on blank spaces. 
    temp = info[i+1].strip().split(" ")
    for i in range(len(temp)):
        temp[i] = int(temp[i])
    arr.append(temp)
arr.sort()

#*Let me instead merge intervals and then consider. 
merged = [arr[0]]
#*Check whether they merge in or not. 
for i in range(1, len(arr)):
    if arr[i][0] <= merged[-1][1]:
        #*Change the last value to the max of the endings. 
        merged[-1][1] = max(merged[-1][1], arr[i][1])
    else:
        #*Simply append. 
        merged.append(arr[i])

max_milk = 0
max_no_milk = 0
for i in range(len(merged)):
    max_milk = max(max_milk, merged[i][1]-merged[i][0])
    if i > 0:
        max_no_milk = max(max_no_milk, merged[i][0] - merged[i-1][1])

fout.write(f"{max_milk} {max_no_milk}\n")
fout.close()
'''
max_milk = 0
max_no_milk = 0
curr_milk = 0
curr_no_milk = 0

for i in range(len(arr)):
    if i == 0:
        start = arr[i][0]
        ending = arr[i][1]
        curr_milk = ending - start
        max_milk = max(max_milk, curr_milk)
    elif arr[i][0] <= arr[i-1][1]:
        #!This could be a mistake because if the initial interval completely encloses subsequent, current might even end up being smaller. 
        #*I think that issue might be simple to fix because I can just take max of curr and new value. 
        #*Inner gap may not even be a gap if there is an outer enclosement. 
        #*How can I detect this?
        #!I think I can put striver's O(n) approach of merging. 
        #*Or, I could implement an ending variable that keeps track of largest ending. 
        ending = max(ending, arr[i][1])
        curr_milk = ending - start
        max_milk = max(max_milk, curr_milk)
    else:
        #!Definitely want to check for the ending here because. 
        #*Not too keen about the correct intervals but correct values. 
        
        start = arr[i][0]
        curr_milk = arr[i][1] - start
        max_milk = max(max_milk, curr_milk)
        curr_no_milk = arr[i][0] - arr[i-1][1]
        max_no_milk = max(max_no_milk, curr_no_milk)

fout.write(f"{max_milk} {max_no_milk}\n")
fout.close()
'''
'''
for i in range(num_intervals):
    #!I still have to include the last element in the calculation
    #!I cannot just add it naively because I need to consider the overlap. 

    if i+1 < num_intervals and intervals[i][1] > intervals[i+1][0]:
        #*Cannot naively add. 
        #*Though of adding based on previous but there could be multiple overlaps. 
        #*Might be beneficial to have a start value. 
        curr_milk = intervals[i][1] - intervals[i][0]
        max_milk = max(max_milk, curr_milk)
        curr_milk = 0
        curr_no_milk = intervals[i][1] - intervals[i+1][0]
        max_no_milk = max(max_no_milk, curr_no_milk)
    
fout.write(f"{max_milk} {max_no_milk}")
fout.close()
'''