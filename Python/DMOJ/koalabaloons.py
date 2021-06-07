

#*Might be worth upsolving. 
#*I think I could use BFS-ish algo but if I run into an issue than I have to reduce the number of baloons by 1. 
#*Gonna be a harder upsolving question. I think it might involve some back-tracking or something?
#*I was kind of thinking of the smallest open square in the grid but I also have to consider that the squares must be connected. 

#*Space isn't a big issue. 

#!Still cannot pass batch #4... What is taking so much tiem???
def main(n, m, arr):
    #*The maximum balloon size will be minimum of row, column. 
    #current_size =
    #found = False
    #!Couple of optimization ideas:
    #*Other than the initial one, just check the borderlines. 

    #!Now time to implement the binary search method.
    low = 1
    high = min(n, m)
    last_successful = None
    #*Even if we can achieve, we will still keep looking so store in last successful one. 
    #!How can binary search take more time though? Supposed to be faster than linear!!
    #*Shouldn't this be faster?
    
    while low <= high:
        current_size = (low+high) // 2
        #*For the first item I need to check all but for others, technically I should probably be fine just checkinig the edges. 
        #!Actually leave at the top. 
        #*Information to store: current row, col. 
        #!No point just starting off at (1, 1) again since we know we can pass all the intermediates. 
        #*Store the nodes that didn't pass from previous round and retry them so less useless pass tries. 
        queue = [(1, 1)]
        chosen = False
        #*Maybe the issue is that I am moving 1 unit at a time??
        visited = set()
        while len(queue) != 0:
            curr = queue.pop(0)
            bottom_right = (curr[0]+current_size-1, curr[1]+current_size-1)
            valid = True
            #*In the loop, check whether contained in the dimensions. 
            
            #!Check whether it fits in beforehand. 
            if 1 <= curr[0] <= n and 1 <= curr[1] <= m and 1 <= curr[0]+current_size-1<=n and 1 <= curr[1]+current_size-1<=m and (curr[0], curr[1]) not in visited:
                visited.add((curr[0], curr[1]))
                if curr == (1, 1):
                    for row in range(curr[0], curr[0]+current_size):
                        if valid == False:
                            break
                        for col in range(curr[1], curr[1]+current_size):
                            if valid == False:
                                break
                            if arr[row-1][col-1] == "X":
                                valid = False
                                break
                else:
                    #!Need to store which direction I came from. 
                    if curr[2] == "up" or curr[2]=="down":
                        if curr[2] == "up":
                            curr_row = curr[0]
                        elif curr[2] == "down":
                            curr_row = curr[0] + current_size - 1
                        for col in range(curr[1], curr[1]+current_size):
                            if arr[curr_row-1][col-1] == "X":
                                valid = False
                                break
                    else:
                        if curr[2] == "left":
                            curr_col = curr[1]
                        elif curr[2] == "right":
                            curr_col = curr[1] + current_size -1
                        for row in range(curr[0], curr[0]+current_size):
                            if arr[row-1][curr_col-1] == "X":
                                valid = False
                                break


                #!I cannot just break at every single node that was not good. 
                if valid == True:
                    if bottom_right == (n, m):
                        last_successful = current_size
                        chosen = True
                        low = current_size + 1
                        break

                    #!My whole row column system is messed up so need to fix that. 
                    #!I think just for the sake of it, I can check before adding. 
                    #*Going down. 
                    queue.append((curr[0]+1, curr[1], "down"))
                    #*Going up. 
                    queue.append((curr[0]-1, curr[1], "up"))
                    #*Going left. 
                    queue.append((curr[0], curr[1]-1, "left"))
                    #*Going right. 
                    queue.append((curr[0], curr[1]+1, "right"))
        
        #!I cannot just move the high variable due to one node. 
        #*Move it when all options were chosen but none of them worked out. 
        if chosen == False:
            high = current_size - 1

    
    if last_successful==None:
        return 0
    else:
        #!I just need to make sure I add since I subtract after I break from while loop. 
        return last_successful

#!Somehow the non-BFS version is faster. 
def main2(n, m, arr):
    current_size = min(n, m)
    found = False
    #!Or even if it is binary search, I can keep note of the highest number that was allowed to pass through that point. 
    while current_size >= 1 and found == False:
        queue = [(1, 1)]
        #chosen = False
        visited = set()
        while len(queue) != 0:
            curr = queue.pop(0)
            bottom_right = (curr[0]+current_size-1, curr[1]+current_size-1)
            valid = True
            if 1 <= curr[0] <= n and 1 <= curr[1] <= m and 1 <= curr[0]+current_size-1<=n and 1 <= curr[1]+current_size-1<=m and (curr[0], curr[1]) not in visited:
                visited.add((curr[0], curr[1]))
                if curr == (1, 1):
                    for row in range(curr[0], curr[0]+current_size):
                        if valid == False:
                            break
                        for col in range(curr[1], curr[1]+current_size):
                            if valid == False:
                                break
                            if arr[row-1][col-1] == "X":
                                valid = False
                                break
            
                else:
                    #!Need to store which direction I came from. 
                    if arr[curr[0]-1][curr[1]-1] != ".":
                        if curr[2] == "up" or curr[2]=="down":
                            if curr[2] == "up":
                                curr_row = curr[0]
                            elif curr[2] == "down":
                                curr_row = curr[0] + current_size - 1
                            for col in range(curr[1], curr[1]+current_size):
                                if arr[curr_row-1][col-1] == "X":
                                    valid = False
                                    break
                        else:
                            if curr[2] == "left":
                                curr_col = curr[1]
                            elif curr[2] == "right":
                                curr_col = curr[1] + current_size -1
                            for row in range(curr[0], curr[0]+current_size):
                                if arr[row-1][curr_col-1] == "X":
                                    valid = False
                                    break
                
                if valid == True:
                    arr[curr[0]-1][curr[1]-1] = "."
                    if bottom_right == (n, m):
                        #last_successful = current_size
                        found = True
                        #low = current_size + 1
                        break

                    #!My whole row column system is messed up so need to fix that. 
                    #!I think just for the sake of it, I can check before adding. 
                    #*Going down. 
                    queue.append((curr[0]+1, curr[1], "down"))
                    #*Going up. 
                    queue.append((curr[0]-1, curr[1], "up"))
                    #*Going left. 
                    queue.append((curr[0], curr[1]-1, "left"))
                    #*Going right. 
                    queue.append((curr[0], curr[1]+1, "right"))

        if found == False:
            current_size -= 1

    if current_size < 1:
        return 0
    else:
        #!I just need to make sure I add since I subtract after I break from while loop. 
        return current_size

def main3(n, m, arr):
    low = 1
    high = min(n,m)
    last_successful = None
    #!Somehow I still cannot pass this one...
    while low <= high:
        current_size = (low+high) // 2
        queue = [(1,1)]
        chosen = False
        #!Actually, chosen does change so that is OK. 
        visited = set()
        while len(queue) != 0:
            curr = queue.pop(0)
            bottom_right = (curr[0]+current_size-1, curr[1]+current_size-1)
            valid = True
            #!visited should only add in the location!! Not including the direction because otherwise there really is no point!!
            if 1 <= curr[0] <= n and 1 <= curr[1] <= m and 1 <= curr[0]+current_size-1<=n and 1 <= curr[1]+current_size-1<=m and (curr[0], curr[1]) not in visited:
                visited.add((curr[0], curr[1]))
                if curr == (1, 1):
                    for row in range(curr[0], curr[0]+current_size):
                        if valid == False:
                            break
                        for col in range(curr[1], curr[1]+current_size):
                            if valid == False:
                                break
                            if arr[row-1][col-1] == "X":
                                valid = False
                                break
                else:
                    if arr[curr[0]-1][curr[1]-1] == "X":
                        valid = False
                        #*Cannot break for one node!!
                    elif arr[curr[0]-1][curr[1]-1] >= current_size:
                        pass
                    else:
                        if curr[2] == "up" or curr[2]=="down":
                            if curr[2] == "up":
                                curr_row = curr[0]
                            elif curr[2] == "down":
                                curr_row = curr[0] + current_size - 1
                            for col in range(curr[1], curr[1]+current_size):
                                if arr[curr_row-1][col-1] == "X":
                                    valid = False
                                    break
                        else:
                            if curr[2] == "left":
                                curr_col = curr[1]
                            elif curr[2] == "right":
                                curr_col = curr[1] + current_size -1
                            for row in range(curr[0], curr[0]+current_size):
                                if arr[row-1][curr_col-1] == "X":
                                    valid = False
                                    break
                if valid == True:
                    #*Update the prefix table. 
                    arr[curr[0]-1][curr[1]-1] = max(current_size, arr[curr[0]-1][curr[1]-1])
                    if bottom_right == (n, m):
                        last_successful = current_size
                        chosen = True
                        low = current_size + 1
                        break

                    #!My whole row column system is messed up so need to fix that. 
                    #!I think just for the sake of it, I can check before adding. 
                    #*Going down. 
                    queue.append((curr[0]+1, curr[1], "down"))
                    #*Going up. 
                    queue.append((curr[0]-1, curr[1], "up"))
                    #*Going left. 
                    queue.append((curr[0], curr[1]-1, "left"))
                    #*Going right. 
                    queue.append((curr[0], curr[1]+1, "right"))

        if chosen == False:
            high = current_size - 1

    if last_successful==None:
        return 0
    else:
        #!I just need to make sure I add since I subtract after I break from while loop. 
        return last_successful

def main4(n, m, arr):
    #*I don't think I can do this implementation with binary search method. Only going from larger to smaller. 
    current_size = min(n, m)
    #!I mean I could make a binary search version for this one. If it passes, I just reuse the queue and keep trying until low exceeds high. 
    found = False
    queue = [(1, 1)]
    #*Since I am just trying to visit all once, I don't need to renew hashset. 
    visited = set()
    while current_size >= 1 and found == False:
        #*For each size I need an array that stores all the failed values from previous try.
        next_arr = []
        while len(queue) != 0:
            curr = queue.pop(0)
            bottom_right = (curr[0]+current_size-1, curr[1]+current_size-1)
            valid = True
            if 1 <= curr[0] <= n and 1 <= curr[1] <= m and 1 <= curr[0]+current_size-1<=n and 1 <= curr[1]+current_size-1<=m and (curr[0], curr[1]) not in visited:
                #visited.add((curr[0], curr[1]))
                #!Since visited won't be renewed, I can only add valid ones. 
                if curr == (1, 1):
                    for row in range(curr[0], curr[0]+current_size):
                        if valid == False:
                            break
                        for col in range(curr[1], curr[1]+current_size):
                            if valid == False:
                                break
                            if arr[row-1][col-1] == "X":
                                valid = False
                                break
                else:
                    #*We don't have to check whether already visited or not. 
                    if curr[2] == "up" or curr[2]=="down":
                        if curr[2] == "up":
                            curr_row = curr[0]
                        elif curr[2] == "down":
                            curr_row = curr[0] + current_size - 1
                        for col in range(curr[1], curr[1]+current_size):
                            if arr[curr_row-1][col-1] == "X":
                                valid = False
                                break
                    else:
                        if curr[2] == "left":
                            curr_col = curr[1]
                        elif curr[2] == "right":
                            curr_col = curr[1] + current_size -1
                        for row in range(curr[0], curr[0]+current_size):
                            if arr[row-1][curr_col-1] == "X":
                                valid = False
                                break
                
                #*I don't even need to consider if out of bounds. 
                if valid == True:
                    visited.add((curr[0], curr[1]))
                    if bottom_right == (n, m):
                        found = True
                        break
                    queue.append((curr[0]+1, curr[1], "down"))
                    #*Going up. 
                    queue.append((curr[0]-1, curr[1], "up"))
                    #*Going left. 
                    queue.append((curr[0], curr[1]-1, "left"))
                    #*Going right. 
                    queue.append((curr[0], curr[1]+1, "right"))
                else:
                    next_arr.append(curr)

        if found == False:
            current_size -=1
            queue = next_arr

    if current_size < 1:
        return 0
    else:
        #!I just need to make sure I add since I subtract after I break from while loop. 
        return current_size

#*Try to optimize but still doesn't work...
def main5(n, m, arr):
    low = 1
    high = min(n, m)
    last_successful = None
    queue = [(1, 1)]
    #*Similar to the queue, I need to make sure I have the set right. 
    visited = set()
    #*I don't need a DP type solution because if I larger one passes, it would be forgotten. 
    while low <= high:
        current_size = (low+high) // 2
        next_arr = []
        temp_queue = queue.copy()
        temp_visited = visited.copy()
        chosen = False
        while len(queue) != 0:
            curr = queue.pop(0)
            bottom_right = (curr[0]+current_size-1, curr[1]+current_size-1)
            valid = True
            if 1 <= curr[0] <= n and 1 <= curr[1] <= m and 1 <= curr[0]+current_size-1<=n and 1 <= curr[1]+current_size-1<=m and (curr[0], curr[1]) not in visited:
                if curr == (1, 1):
                    for row in range(curr[0], curr[0]+current_size):
                        if valid == False:
                            break
                        for col in range(curr[1], curr[1]+current_size):
                            if valid == False:
                                break
                            if arr[row-1][col-1] == "X":
                                valid = False
                                break
                else:
                    #*We don't have to check whether already visited or not. 
                    if curr[2] == "up" or curr[2]=="down":
                        if curr[2] == "up":
                            curr_row = curr[0]
                        elif curr[2] == "down":
                                break
                    else:
                        if curr[2] == "left":
                            curr_col = curr[1]
                        elif curr[2] == "right":
                            curr_col = curr[1] + current_size -1
                        for row in range(curr[0], curr[0]+current_size):
                            if arr[row-1][curr_col-1] == "X":
                                valid = False
                                break
                if valid == True:
                    visited.add((curr[0], curr[1]))
                    if bottom_right == (n, m):
                        last_successful = current_size
                        chosen = True
                        low = current_size + 1
                        #*Re-do the thing using the previous arr and set. 
                        queue = temp_queue
                        visited = temp_visited
                        break
                    queue.append((curr[0]+1, curr[1], "down"))
                    #*Going up. 
                    queue.append((curr[0]-1, curr[1], "up"))
                    #*Going left. 
                    queue.append((curr[0], curr[1]-1, "left"))
                    #*Going right. 
                    queue.append((curr[0], curr[1]+1, "right"))
                else:
                    next_arr.append(curr)

        if chosen == False:
            high = current_size - 1
            #*Queue is next_arr. 
            #*Just keep visited.
            queue = next_arr

    if last_successful==None:
        return 0
    else:
        #!I just need to make sure I add since I subtract after I break from while loop. 
        return last_successful

#!I try all these BFS and they are accurate but they are just not fast enough.       
n, m = input().strip().split(" ")
n, m = int(n), int(m)
arr = []
for i in range(n):
    temp = []
    inp = input()
    for j in inp:
        temp.append(j)
    #!Prefix array is already mentioned so this must be correct. 
    #*When this table says prefix table, it might not even mean the storing array. 
    #*If I loop from the largest and if if one position for the top left is valid, all the smaller squares can fit in there for the top
    #*So I don't even have to check for further. 
    arr.append(temp)
#!Now have to hardcore optimize using dp.
print(main(n,m, arr))