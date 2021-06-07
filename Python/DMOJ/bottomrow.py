
#*I honestly think this is really an obvious BFS search question 
#*Maybe implement a recursive solution to this but it might fail the second test case due to recursion error. 
#!In this case recursion wouldn't work because that is breadth first. 
#!Since this is not breadth first and more similar to depth first, it becomes harder to check other possibilities. 
#*Plus I cannot just look at this based on 1 value but have to do manhattan distance. 
from queue import PriorityQueue

#*I need to be able to see what is currently in the priority queue.
def show(queue: PriorityQueue):
    result = []
    while not queue.empty():
        result.append(queue.get())
    
    for i in result:
        queue.put(i)
    
    return result
'''
def main(arr):
    #!Priorityqueue must pick based on the index. 
    #*Row is considered more than col. 
    #!Rather than inputting the index, I input the distance from correct. 
    queue = PriorityQueue()
    queue.put((len(arr)-1, len(arr)-1, ""))
    result = []
    len_limit = None

    while not queue.empty():
        print(show(queue))
        #!The priority queue is really mutable and is changed...
        curr = queue.get()
        if len_limit != None and len(curr[2]) > len_limit:
            break
        if curr[0] == curr[1] == 0:
            len_limit = len(curr[2])
            result.append(curr[2])
        #!I just have to modify 
        elif 0 <= curr[0] < len(arr) and 0 <= curr[1] < len(arr) and arr[len(arr) - 1- curr[0]][len(arr)-1-curr[1]] != "#":
            queue.put((curr[0]-1, curr[1], curr[2]+"U"))
            queue.put((curr[0]+1, curr[1], curr[2]+"D"))
            queue.put((curr[0], curr[1]-1, curr[2]+"R"))
            queue.put((curr[0], curr[1]+1, curr[2]+"L"))
    if len(result) == 0:
        return "IMPOSSIBLE"
    else:
        #*Among the many possibilities, how can I compare??
        i = 0
        #*Remove one by 1. 
        #*Create a new array again and again and paste it in. 
        min_letter = None
        while len(result) > 1:
            for j in result:
                if min_letter == None:
                    min_letter = ord(j[i])
                else:
                    min_letter = min(min_letter, ord(j[i]))
            #*Paste into new result arr. 
            temp = result
            result = []
            for a in temp:
                if ord(a[i]) == min_letter:
                    result.append(a)
            i+=1
        return result[0]
'''

def main(arr):
    #*The store the index and the current move pattern. 
    #!The string acts as a came_from so I don't think a dictionary will be needed. 
    #*Pick based on index. 
    
    queue = [(0, 0, "")]
    result = []
    len_limit = None
    #!The thing is that I cannot just return after I find because I need to check all others with that same len of moves. 
    #!The BFS just takes too much time. 
    while len(queue) > 0:
        curr = queue.pop(0)
        if len_limit != None and len(curr[2]) > len_limit:
            break   
        if curr[0]==curr[1] == len(arr)-1:
            len_limit = len(curr[2])
            result.append(curr[2])
        
        elif 0 <= curr[0] < len(arr) and 0 <= curr[1] < len(arr) and arr[curr[0]][curr[1]] != "#":
            #row+1 so up
            queue.append((curr[0]+1, curr[1], curr[2]+"U"))
            #queue.append((curr[0]-1, curr[1], curr[2]+"D"))
            queue.append((curr[0], curr[1]+1, curr[2]+"R"))
            #queue.append((curr[0], curr[1]-1, curr[2]+"L"))

    #!Everything here in the bottom is required so it must stay. 
    #*Try an A* algo approach? Maybe it might make it better. 
    
    if len(result) == 0:
        return "IMPOSSIBLE"
    else:
        #*Among the many possibilities, how can I compare??
        i = 0
        #*Remove one by 1. 
        #*Create a new array again and again and paste it in. 
        min_letter = None
        while len(result) > 1:
            for j in result:
                if min_letter == None:
                    min_letter = ord(j[i])
                else:
                    min_letter = min(min_letter, ord(j[i]))
            #*Paste into new result arr. 
            temp = result
            result = []
            for a in temp:
                if ord(a[i]) == min_letter:
                    result.append(a)
            i+=1
        return result[0]
    
    #return result[0]

#!Since the starting and ending point are at an edge, there is either no way to get there or we only move up or right. 
#*For tim's program, we could start anywhere and force it to move downward but not in this program. 
#*Any diagonal of blocked cell can be enclosed by a square. Shortest path doesn't pass through that square (because then I have to go left or down:bad moves)

#!First block out diagonal squares. 
#!Then

def show(arr):
    for row in range(len(arr)-1, -1, -1):
        print(" ".join(arr[row]))
def main(arr, d):
    #!What can take up so much space??
    #!I will probably have to do it without the extra all_keys array. 
    all_keys = []
    for i in range(len(d)):
        if d[i] != None:
            all_keys.append(i)
    #all_keys = sorted(list(d.keys()))
    #!I will do a 2 pointer where 1 pointer will mark the start and 2nd will mark the end. 
    
    a = len(all_keys)-1 #bottom right
    b = len(all_keys)-2 #top left
    prev = len(all_keys) - 1
    #!Also there is no guarantee that the current column checking will have blocked cell.
    #!I am marking somewhere that shouldn't be marked as "#" as "#". 
    #*Should be one of the loops that is causing the trouble. 
    #!b is only relevant in the loop when len(all_keys) >= 2
    #!Another possibility is that I didn't block it correctly and has entered no way out area. 
    #*Doesn't have to b strictly rising by 1 diagonal. Could drop but still I need to cover!
    #!I still have an impossible error at test case 6. 
    #!I was covering the wrong place. 
    #!Covers somewhere that shouldn't be covered!!
    #!Or fails to cover somewhere that should be covered!!
    while b >= 0:
        #all_keys[b] -> col
        #d[all_keys[b]] -> row
        #col = all_keys[b]
        #!A simple while statement will always give me true so I must check the location relationship.
        #*As long as the column difference == row difference it is all good.  
        #*No real need to lookup then. 
        #row of a -> d[all_keys[a]]
        #col of a -> all_keys[a]
        #col difference = all_keys[a] - all_keys[b]
        #row difference = all_keys[]
        '''
        while col -1 >= 0 and col in d and d[col] >= 0 and arr[d[col]][col] == "#":
            b -= 
        '''
        #!There must be both an upperbound and lowerbound. Can be the length because 1 index. 
        #!Interesting idea that I just have to cover the outlines. Also, since I am not moving left or down, the top right side doesn't have to be covered. 
        while b >= 0 and len(arr) >= all_keys[b] >= 1 and len(arr) >= d[all_keys[b]] >= 1 and all_keys[b] == all_keys[prev] - 1 and d[all_keys[b]] == d[all_keys[prev]]+1:
            prev = b
            b -= 1

        '''
        for row in range(d[all_keys[a]], d[all_keys[b+1]]+1):
            for col in range(all_keys[b+1], all_keys[a]+1):
                arr[row-1][col-1] = "#"
        '''
        a_col = all_keys[a]
        a_row = d[a_col]
        b_col = all_keys[b+1]
        b_row = d[b_col]
        #!a_row and b_row should be the same when no change. 
        #*But probably just overlap "#" is what happens. 
        #*I am covering up everything needed here. 
        #!Some issue with indexing and return value. 
        for row in range(a_row, b_row+1):
            arr[row-1][b_col-1] = "#"
        for col in range(b_col, a_col+1):
            arr[a_row-1][col-1] = "#"
        '''
        for row in range(a_row, b_row+1):
            for col in range(b_col, a_col+1):
                arr[row-1][col-1] = "#"
        '''
        #!Somehow this loop is just going on forever. 
        #!Happens after we move a once and when b
        a = b
        prev = a
        b -= 1
    
    #!I need to rule out the increasing diagonals at the edge. 
    #!Start off by iterating from the right.
    a = len(all_keys) - 2
    prev = len(all_keys) - 1
    #*Just need a single while loop. 
    #!Don't need to be lower because it could be both. 
    #*I honestly think it might be easier if I just do the 
    while a >= 0 and len(arr) >= all_keys[a] >= 1 and len(arr) >= d[all_keys[a]] >= 1 and all_keys[a] == all_keys[prev] - 1 and d[all_keys[a]] <= d[all_keys[prev]]+1:
        #*Run a forloop here to cover the gap on top. Run it before the change. 
        a_col = all_keys[a]
        a_row = d[a_col]
        prev_col = all_keys[prev]
        prev_row = d[prev_col]
        for row in range(a_row, prev_row+1):
            arr[row-1][prev_col-1] = "#"
        prev =a 
        a -= 1
        
    
    #*Just gotta cover up until I reach the bottom. 
    #!Esentially the same thing as looping through prev. 
    
    if len(all_keys) >= 1:
        for i in range(1, d[all_keys[prev]]+1):
            arr[i-1][all_keys[prev]-1] = "#"
    
    #!Could it possibly block the actual path. 
    #I cannot construct an impossible path if it is working properly...
    #show(arr)
    #!I don't think I need to do this for the above ones because I would always go right than up. 
    curr = [1, 1]
    result = []
    #!Index thing is only applicable to arr. 
    #!Some incorrect output saying impossible. 
    while curr != [len(arr), len(arr)]:
        #!After changing it correctly changes. 
        #!But I need to cover the gaps as well. 
        #*I obviously have to check for out of bounds. 
        if curr[1]+1-1 < len(arr) and arr[curr[0]-1][curr[1]+1-1] != "#":
            result.append("R")
            curr[1] = curr[1]+1
            #curr= (curr[0], 
        elif curr[0]+1-1 < len(arr) and arr[curr[0]+1-1][curr[1]-1] != "#":
            result.append("U")
            curr[0] = curr[0]+1
            

        else:
            #!For some cases, IMPOSSIBLE is working (like test case 1) but for others no. 
            #*Some failure in marking #
            return "IMPOSSIBLE"#, len(arr), result
    return "".join(result)

    #show(arr)
    '''
    for i in range(len(all_keys)-1, -1, -1):
        col = i
        row = d[i]
        #!I cannot just block out adjacent because might continue. 
        if col - 1 >= 0 and row - 1 >= 0 and arr[row][col] == "#":
    '''
    '''
    #!The problem really is in the BFS structure. 
    #!The interesting thing is that if I rule out all the possible places I cannot get stuck into, I can just greedily do it, saving so much time. 
    queue = [(0, 0, "")]
    result = []
    len_limit = None
    #!The thing is that I cannot just return after I find because I need to check all others with that same len of moves. 
    #!The BFS just takes too much time. 

    while len(queue) > 0:
        curr = queue.pop(0)
        if len_limit != None and len(curr[2]) > len_limit:
            break   
        if curr[0]==curr[1] == len(arr)-1:
            len_limit = len(curr[2])
            result.append(curr[2])
        
        elif 0 <= curr[0] < len(arr) and 0 <= curr[1] < len(arr) and arr[curr[0]][curr[1]] != "#":
            #row+1 so up
            queue.append((curr[0], curr[1]+1, curr[2]+"R"))
            queue.append((curr[0]+1, curr[1], curr[2]+"U"))
            #queue.append((curr[0]-1, curr[1], curr[2]+"D"))
            
            #queue.append((curr[0], curr[1]-1, curr[2]+"L"))

    #!Everything here in the bottom is required so it must stay. 
    #*Try an A* algo approach? Maybe it might make it better. 
    
    if len(result) == 0:
        return "IMPOSSIBLE"
    else:
        #*Among the many possibilities, how can I compare??
        i = 0
        #*Remove one by 1. 
        #*Create a new array again and again and paste it in. 
        min_letter = None
        while len(result) > 1:
            for j in result:
                if min_letter == None:
                    min_letter = ord(j[i])
                else:
                    min_letter = min(min_letter, ord(j[i]))
            #*Paste into new result arr. 
            temp = result
            result = []
            for a in temp:
                if ord(a[i]) == min_letter:
                    result.append(a)
            i+=1
        return result[0]
    '''
    '''
    if len(result) == 0:
        return "IMPOSSIBLE"
    return result[0]
    '''

def main(arr, d):
    #!Kind of thought of ordered dict but we want it sorted based on col not based on order inserted. 
    #*In this scenario, a and b are indices but they are also columns. 
    #!That's why they must be larger than 1. 
    a = len(d) - 1
    b = len(d) - 2
    prev = len(d) - 1
    while b >= 1:
        #*Checking for row in range is dumb because everything is in range. 
        #*a is not necessarily a valid starting point.
        #*Don't think I need to check for prev because prev is only assigned for correct b.  
        #*Also, I b == prev+1 is the assumption. 
        while b >= 1 and d[a] != 0 and d[b] != 0 and d[b] == d[prev] + 1:
            prev = b
            b -= 1
        #*Could end up being here after breaking out of loop or becuase a is not valid. 
        if d[a] == 0:            
            a -= 1
            prev = a
            b = a - 1
        else:
            #a_col = a
            #a_row = d[a]
            #b_col = b
            #b_row = d[b+1]
            #*Add +1 if inclusion errors. 
            for row in range(d[a], d[prev]):
                arr[row-1][prev-1] = "#"
            for col in range(prev, a):
                arr[d[a]-1][col-1] = "#"
            a = b
            b = a-1
            prev = a
    #
    #!Now I have a weird error at case #10
    a = len(d) - 2
    prev = len(d) - 1
    
    #*Again the range restriction is unnecessary except for a>=1
    while a >= 1 and d[a] != 0 and d[prev] != 0 and d[a] <= d[prev] + 1:
        for row in range(d[a]+1, d[prev]):
            arr[row-1][prev-1] = "#"
        prev = a
        a -= 1
    
    #*Shouldn't over generalize to "at the end bar"
    #!Prev will most likely be >= 1 because looping through the entire frequency array. 
    #?I mean technically if prev exists shouldn't the range be (1,0) and will work fine?

    for row in range(1, d[prev]):
        arr[row-1][prev-1] = "#"
    #show(arr)

    curr = [1, 1]
    result = []
    #!Index thing is only applicable to arr. 
    #!Some incorrect output saying impossible. 
    while curr != [len(arr), len(arr)]:
        #!After changing it correctly changes. 
        #!But I need to cover the gaps as well. 
        #*I obviously have to check for out of bounds. 
        if curr[1]+1-1 < len(arr) and arr[curr[0]-1][curr[1]+1-1] != "#":
            result.append("R")
            curr[1] = curr[1]+1
            #curr= (curr[0], 
        elif curr[0]+1-1 < len(arr) and arr[curr[0]+1-1][curr[1]-1] != "#":
            result.append("U")
            curr[0] = curr[0]+1
        else:
            #!For some cases, IMPOSSIBLE is working (like test case 1) but for others no. 
            #*Some failure in marking #
            return "IMPOSSIBLE"#, len(arr), result
    return "".join(result)

def main(n, d, all_blocked):
    all_keys = sorted(list(d.keys()))
    #all_keys = []
    '''
    for i in range(len(d)):
        if d[i] != None:
            all_keys.append(i)
    '''
    #all_keys = sorted(list(d.keys()))
    
    #!I will do a 2 pointer where 1 pointer will mark the start and 2nd will mark the end. 
    #additional = {}
    a = len(all_keys)-1 #bottom right
    b = len(all_keys)-2 #top left
    prev = len(all_keys) - 1
    #!Also there is no guarantee that the current column checking will have blocked cell.
    #!I am marking somewhere that shouldn't be marked as "#" as "#". 
    #*Should be one of the loops that is causing the trouble. 
    #!b is only relevant in the loop when len(all_keys) >= 2
    #!Another possibility is that I didn't block it correctly and has entered no way out area. 
    #*Doesn't have to b strictly rising by 1 diagonal. Could drop but still I need to cover!
    #!I still have an impossible error at test case 6. 
    #!I was covering the wrong place. 
    #!Covers somewhere that shouldn't be covered!!
    #!Or fails to cover somewhere that should be covered!!
    while b >= 0:
        #all_keys[b] -> col
        #d[all_keys[b]] -> row
        #col = all_keys[b]
        #!A simple while statement will always give me true so I must check the location relationship.
        #*As long as the column difference == row difference it is all good.  
        #*No real need to lookup then. 
        #row of a -> d[all_keys[a]]
        #col of a -> all_keys[a]
        #col difference = all_keys[a] - all_keys[b]
        #row difference = all_keys[]
        '''
        while col -1 >= 0 and col in d and d[col] >= 0 and arr[d[col]][col] == "#":
            b -= 
        '''
        #!There must be both an upperbound and lowerbound. Can be the length because 1 index. 
        #!Interesting idea that I just have to cover the outlines. Also, since I am not moving left or down, the top right side doesn't have to be covered. 
        while b >= 0 and n >= all_keys[b] >= 1 and n >= d[all_keys[b]] >= 1 and all_keys[b] == all_keys[prev] - 1 and d[all_keys[b]] == d[all_keys[prev]]+1:
            prev = b
            b -= 1

        '''
        for row in range(d[all_keys[a]], d[all_keys[b+1]]+1):
            for col in range(all_keys[b+1], all_keys[a]+1):
                arr[row-1][col-1] = "#"
        '''
        a_col = all_keys[a]
        a_row = d[a_col]
        b_col = all_keys[b+1]
        b_row = d[b_col]
        #!a_row and b_row should be the same when no change. 
        #*But probably just overlap "#" is what happens. 
        #*I am covering up everything needed here. 
        #!Some issue with indexing and return value. 
        #*Instead of modifying arr values, just add into the dictionary. 
        for row in range(a_row, b_row+1):
            #arr[row-1][b_col-1] = "#"
            #d[b_col-1] = row-1
            #?I think I should store the key value pairs in a dictionary with the values being the list. 
            #!Add in the additional dictionary. 
            if b_col in all_blocked:
                all_blocked[b_col].add(row)
            else:
                all_blocked[b_col] = {row}

        for col in range(b_col, a_col+1):
            #d[col-1] = 
            #arr[a_row-1][col-1] = "#"
            #additional.add((a_row, col))
            if col in all_blocked:
                all_blocked[col].add(a_row)
            else:
                all_blocked[col] = {a_row}
        
        '''
        for row in range(a_row, b_row+1):
            for col in range(b_col, a_col+1):
                arr[row-1][col-1] = "#"
        '''
        #!Somehow this loop is just going on forever. 
        #!Happens after we move a once and when b
        a = b
        prev = a
        b -= 1
    
    #!I need to rule out the increasing diagonals at the edge. 
    #!Start off by iterating from the right.
    a = len(all_keys) - 2
    prev = len(all_keys) - 1
    #*Just need a single while loop. 
    #!Don't need to be lower because it could be both. 
    #*I honestly think it might be easier if I just do the 
    while a >= 0 and n >= all_keys[a] >= 1 and n >= d[all_keys[a]] >= 1 and all_keys[a] == all_keys[prev] - 1 and d[all_keys[a]] <= d[all_keys[prev]]+1:
        #*Run a forloop here to cover the gap on top. Run it before the change. 
        a_col = all_keys[a]
        a_row = d[a_col]
        prev_col = all_keys[prev]
        prev_row = d[prev_col]
        for row in range(a_row, prev_row+1):
            #arr[row-1][prev_col-1] = "#"
            #additional.add((row,prev_col))
            if prev_col in all_blocked:
                all_blocked[prev_col].add(row)
            else:
                all_blocked[prev_col] = {row}
        prev =a 
        a -= 1
        
    
    #*Just gotta cover up until I reach the bottom. 
    #!Esentially the same thing as looping through prev. 
    
    if len(all_keys) >= 1:
        for i in range(1, d[all_keys[prev]]+1):
            #arr[i-1][all_keys[prev]-1] = "#"
            #additional.add((i, all_keys[prev]))
            if all_keys[prev] in all_blocked:
                all_blocked[all_keys[prev]].add(i)
            else:
                all_blocked[all_keys[prev]] = {i}
    
    #!Could it possibly block the actual path. 
    #I cannot construct an impossible path if it is working properly...
    #show(arr)
    #!I don't think I need to do this for the above ones because I would always go right than up. 
    curr = [1, 1]
    result = []
    #!Index thing is only applicable to arr. 
    #!Some incorrect output saying impossible. 
    #*Still some kind of issue.
    #*TLE then MLE and repeat forever. 
    #*Maybe store in a separate dictionary with column keys and a set of rows that are blocked.  
    #!Stupid TLE!!!
    #!I bet it is the set lookup that takes up time. 
    #*If there is no blocked item initially, there would never be a blocked item, even after modification. 
    #*Could I only store columns with blocked maybe?
    #!But for the big array, the indexing should be arr[col][arr] which isn't much of a problem. 
    while curr != [n, n]:
        #!After changing it correctly changes. 
        #!But I need to cover the gaps as well. 
        #*I obviously have to check for out of bounds. 
        #!No longer checking based on arr. 
        #*Cannot just check the tuple of additional but rather with the modifications. 
        if curr[1]+1 <= n and ((curr[1]+1 not in d or d[curr[1]+1] != curr[0]) and (curr[1]+1 not in all_blocked or curr[0] not in all_blocked[curr[1]+1])):
            result.append("R")
            curr[1] +=1
            #curr= (curr[0], 
        elif curr[0]+1 <= n and ((curr[1] not in d or d[curr[1]] != curr[0]+1) and (curr[1] not in all_blocked or curr[0]+1 not in all_blocked[curr[1]])):
            result.append("U")
            curr[0] +=1

        else:
            #!For some cases, IMPOSSIBLE is working (like test case 1) but for others no. 
            #*Some failure in marking #
            return "IMPOSSIBLE"#, len(arr), result
    return "".join(result)

#!How damn confusing can this problem be?


'''
n, k = input().strip().split(" ")
n, k = int(n), int(k)
#*I can just create an array of representations. 
table = []
#d = {}
#!d kind of acts like a frequency array. 
d = [0] * (n+1)
for i in range(n):
    #!I definitely need to store blocked values but open values? Maybe not. 
    table.append(["."] * n)
for i in range(k):
    row, col = input().strip().split(" ")
    row, col = int(row), int(col)
    #!Table must remain an array. 
    table[row-1][col-1] = "#"
    #!Could it be helpful to store the locations of blocked in a hashset or hashmap?
    #!The problem about using a hashset is that it is unordered so I cannot iterate over hashset. 
    #*But since I might be shifting from left to right, create hashmap based on col. 
    #!Maybe use a frequency array instead of hashmap to save space. 
    d[col] = row
    has_blocked = True
print(main(table, d))
'''


'''
n, k = input().strip().split(" ")
n, k = int(n), int(k)
d = {}
all_blocked = {}
for i in range(k):
    row, col = input().strip().split(" ")
    row, col = int(row), int(col)
    d[col] = row
    all_blocked[col] = {row}

print(main(n, d, all_blocked))
'''

#!Case #6 really tested whether I covered both diagonal cases or not. 
def main(arr, d):
    n = len(arr)
    all_keys = sorted(list(d.keys()))
    a = len(all_keys)-1 #bottom right
    b = len(all_keys)-2 #top left
    prev = len(all_keys) - 1
    while b >= 0:
        while b >= 0 and n >= all_keys[b] >= 1 and n >= d[all_keys[b]] >= 1 and all_keys[b] == all_keys[prev] - 1 and d[all_keys[b]] == d[all_keys[prev]]+1:
            prev = b
            b -= 1
        a_col = all_keys[a]
        a_row = d[a_col]
        b_col = all_keys[b+1]
        b_row = d[b_col]
        for row in range(a_row, b_row+1):
            #arr[row-1][b_col-1] = "#"
            #d[b_col-1] = row-1
            #?I think I should store the key value pairs in a dictionary with the values being the list. 
            #!Add in the additional dictionary. 
            '''
            if b_col in all_blocked:
                all_blocked[b_col].add(row)
            else:
                all_blocked[b_col] = {row}
            '''
            arr[b_col-1][row-1] = "#"
        for col in range(b_col, a_col+1):
            #d[col-1] = 
            #arr[a_row-1][col-1] = "#"
            #additional.add((a_row, col))
            arr[col-1][a_row-1] = "#"
            '''
            if col in all_blocked:
                all_blocked[col].add(a_row)
            else:
                all_blocked[col] = {a_row}
            '''
        a = b
        prev = a
        b -= 1
    a = len(all_keys) - 2
    prev = len(all_keys) - 1
    while a >= 0 and n >= all_keys[a] >= 1 and n >= d[all_keys[a]] >= 1 and all_keys[a] == all_keys[prev] - 1 and d[all_keys[a]] <= d[all_keys[prev]]+1:
        #*Run a forloop here to cover the gap on top. Run it before the change. 
        a_col = all_keys[a]
        a_row = d[a_col]
        prev_col = all_keys[prev]
        prev_row = d[prev_col]
        for row in range(a_row, prev_row+1):
            #arr[row-1][prev_col-1] = "#"
            #additional.add((row,prev_col))
            '''
            if prev_col in all_blocked:
                all_blocked[prev_col].add(row)
            else:
                all_blocked[prev_col] = {row}
            '''
            arr[prev_col-1][row-1] = "#"
        prev =a 
        a -= 1
    if len(all_keys) >= 1:
        for row in range(1, d[all_keys[prev]]+1):
            #arr[i-1][all_keys[prev]-1] = "#"
            #additional.add((i, all_keys[prev]))
            '''
            if all_keys[prev] in all_blocked:
                all_blocked[all_keys[prev]].add(i)
            else:
                all_blocked[all_keys[prev]] = {i}
            '''
            arr[all_keys[prev]-1][row-1] = "#"
    curr = [1, 1]
    result = []
    while curr != [n, n]:
        #!Have to check for index out of range as well. 
        if curr[1]+1 <= n and (len(arr[curr[1]+1-1]) == 0 or arr[curr[1]+1-1][curr[0]-1] != "#"):
            result.append("R")
            curr[1] +=1
            #curr= (curr[0], 
        elif curr[0]+1 <= n and (len(arr[curr[1]-1]) == 0 or arr[curr[1]-1][curr[0]+1-1] != "#"):
            result.append("U")
            curr[0] +=1
        else:
            return "IMPOSSIBLE"
    return "".join(result)

'''
#!I am gonna try the frequency array implementation but if this doesn't work that's just plain crazy. 
n, k = input().strip().split(" ")
n, k = int(n), int(k)
d = {}
arr = [] 
for i in range(n):
    arr.append([])
for i in range(k):
    row, col = input().strip().split(" ")
    row, col = int(row), int(col)
    d[col] = row
    if len(arr[col-1]) == 0:
        #*Don't really know if this is correct syntax. 
        arr[col-1] = ["."] * n
    arr[col-1][row-1] = "#"
print(main(arr, d))
'''

def main(arr, d):
    a = len(d) - 1
    b = len(d) - 2
    prev = len(d) - 1
    while b >= 1:
        while b >= 1 and d[a] != 0 and d[b] != 0 and d[b] == d[prev] + 1:
            prev = b
            b -= 1
        else:
            #a_col = a
            #a_row = d[a]
            #b_col = b
            #b_row = d[b+1]
            #*Add +1 if inclusion errors. 
            for row in range(d[a], d[prev]):
                #arr[row-1][prev-1] = "#"
                arr[prev-1][row-1] = "#"
            for col in range(prev, a):
                #arr[d[a]-1][col-1] = "#"
                arr[col-1][d[a]-1]
            a = b
            b = a-1
            prev = a
    a = len(d) - 2
    prev = len(d) - 1
    while a >= 1 and d[a] != 0 and d[prev] != 0 and d[a] <= d[prev] + 1:
        for row in range(d[a]+1, d[prev]):
            #arr[row-1][prev-1] = "#"
            arr[prev-1][row-1] = "#"
        prev = a
        a -= 1

    #!Simply not covering the enture thing properly
    for row in range(1, d[prev]):
        #arr[row-1][prev-1] = "#"
        arr[prev-1][row-1] = "#"
    
    curr = [1, 1]
    result = []
    while curr != [len(arr), len(arr)]:
        #!Need to check for arr length. 
        if curr[1]+1-1 < len(arr) and (len(arr[curr[1]+1-1]) == 0 or arr[curr[1]+1-1][curr[0]-1] != "#"):
            result.append("R")
            curr[1] = curr[1]+1
        elif curr[0]+1-1 < len(arr) and (len(arr[curr[1]-1]) == 0 or arr[curr[1]-1][curr[0]+1-1] != "#"):
            result.append("U")
            curr[0] = curr[0]+1
        else:
            return "IMPOSSIBLE"
    return "".join(result)

#!Memory is seriously not budging. 
n, k = input().strip().split(" ")
n, k = int(n), int(k)
arr = []
d = [0] * (n+1)
for i in range(n):
    arr.append([])
for i in range(k):
    row, col = input().strip().split(" ")
    row, col = int(row), int(col)
    if len(arr[col-1]) == 0:
        arr[col-1] = ["."] * n
    arr[col-1][row-1] = "#"
    d[col] = row
print(main(arr, d))

#!The only 2 locations I need to know whether they are blocked are nearby. Couldn't I start from the end to possibly solve along the way?
#I do have to address different concerns if that is the case. 

