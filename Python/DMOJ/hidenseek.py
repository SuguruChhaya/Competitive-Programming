from itertools import permutations as p
from copy import deepcopy
def main(n, m, t, start, hiders, arr):
    #!Creating permutations doesn't change but the idea that mix up indices to save space makes sense. 
    #*The permutation method really runs out of memory too. 
    #!The iterable cannot be hiders since 
    temp = []
    for i in range(t):
        temp.append(i)
    permutations = list(p(temp))
    #!But if this is the case, I need to make sure the front element actually comes at front. 
    '''
    queue = [[0]]

    while (len(queue) > 0):
        curr = queue.pop(0)
        if (len(curr) == t+1):
            permutations.append(curr)
        else:
            for i in range(len(hiders)):
                if i not in curr:
                    #*I think it is the array copying that really takes the toll. 
                    temp = curr.copy()
                    temp.append(i)
                    queue.append(temp)
    '''
    
    dp = {}
    queue = []
    result = 99999
    visited = deepcopy(arr)

    #*First have to do it separately for the first element. 
    


    #!Really cannot spend entire memory tupling stuff. 
    for i in range(len(permutations)):
        #*No issue for j+1 exceeding because since there must be a start point and at least one hider, no permutation will have length 2 or smaller. 
        curr_length = 0
        #!Since we aren't including the first element, the loop counter must change. 
        for j in range(t):
            #*Changing the visited array. Only use little extra memory. 
            for row in range(n):
                for col in range(m):
                    visited[row][col] = arr[row][col]
            #!Just need to adjust the hashability types. 
            if (tuple(hiders[permutations[i][j]]), tuple(hiders[permutations[i][j+1]])) in dp:
                curr_length += dp[tuple(hiders[permutations[i][j]], tuple(hiders[permutations[i][j+1]]))]
                break
            elif (tuple(hiders[permutations[i][j+1]]), tuple(hiders[permutations[i][j]])) in dp:
                curr_length += dp[tuple(hiders[permutations[i][j+1]]), tuple(hiders[permutations[i][j]])]
                break
            else:
                #*Last item to count how the distance. 
                #!Need to check the indexing a little bit. Since it has to be hiders[][0]
                #!Still 4. 
                queue = [[hiders[permutations[i][j]][0], hiders[permutations[i][j]][1], 0]]
                while len(queue) > 0:
                    curr = queue.pop(0)
                    if (curr[0]==hiders[permutations[i][j+1]][0] and curr[1]==hiders[permutations[i][j+1]][1]):
                        curr_length += curr[2]
                        dp[(tuple(hiders[permutations[i][j]]), tuple(hiders[permutations[i][j+1]]))] = curr[2]
                        break
                    #*Only checking visited also checks arr. 
                    elif 0 <= curr[0] < n and 0 <= curr[1] < m and visited[curr[0]][curr[1]] != 'X':
                        visited[curr[0]][curr[1]] = 'X'
                        queue.append([curr[0]+1, curr[1], curr[2]+1])
                        queue.append([curr[0]-1, curr[1], curr[2]+1])
                        queue.append([curr[0], curr[1]+1, curr[2]+1])
                        queue.append([curr[0], curr[1]-1, curr[2]+1])
                    
        result = min(result, curr_length)
    return result
    

n, m, t = input().strip().split(" ")
n, m, t = int(n), int(m), int(t)

arr = []
hiders = []
for i in range(n):
    s = input()
    temp = []
    for j in range(m):
        temp.append(s[j])
        #!I guess I could insert it to the beginning to ensure starting always shows up in the beginning.
        if s[j] == 'G':
            start = [i, j]
            #hiders.insert(0, [i, j])
        elif s[j] == 'H':
            hiders.append([i, j])
    arr.append(temp)

print(main(n, m, t, start, hiders, arr))



#*For Python, memory of creating all these permutations in row, col form is what causes the memory error. 
#*For that, I honestly think I need to first find out the individual lengths, store it in maybe a dictionary, then run a loop, storing the current length in an int using BFS. 
'''
def main(n, m, t, start, hiders, arr):
    d = {}
    visited = deepcopy(arr)
    #*Find the distance between hiders. 
    for i in range(len(hiders)):
        #*Don't run the reverse.
        for j in range(i+1, len(hiders)):
            
            for row in range(n):
                for col in range(m):
                    visited[row][col] = arr[row][col]
            queue = [(hiders[i][0], hiders[i][1], 0)]
            while len(queue) > 0:
                curr = queue.pop(0)
                if (curr[0] == hiders[j][0] and curr[1] == hiders[j][1]):
                    d[(hiders[i], hiders[j])] = curr[2]
                    break
                else:
                    queue.append((curr[0]+1, curr[1], curr[2]+1))
                    queue.append((curr[0]-1, curr[1], curr[2]+1))
                    queue.append((curr[0], curr[1]+1, curr[2]+1))
                    queue.append((curr[0], curr[1]-1, curr[2]+1))
    
    #*Starting queue. 
    queue = [start]
    result = 9999999
    
    while len(queue) > 0:
        #?How am I supposed to know which paths I have went to and which I haven't?
        #*Ultimately, storing all the possibilities costs me a lot of memory. 
        #*Travelling salesman problem in linear time.


    #*Just learn from bobhob's submission. https://dmoj.ca/src/88584
    #!Append all hiders into an array. 

    #*create a 6 by 5 matrix for what?
    #*Then create a visited matrix (wouldn't it be easier with a set?)
    #!It just seems like I am going to wherever I can go to. 
    #*Creative data structure. Instead of using queue to store every where visited, use array to know. 

    #*First go from griffy and check whether they can be visited?

            

n, m, t = input().strip().split(" ")
n, m, t = int(n), int(m), int(t)

arr = []
hiders = []
for i in range(n):
    s = input()
    temp = []
    for j in range(m):
        temp.append(s[j])

        if s[j] == 'H':
            hiders.append((i, j))
        if s[j] == 'G':
            start = (i, j)
            #!Technically, I could treat the starting point as one of the hiders. 
            hiders.append((i, j))
    arr.append(temp)

print(main(n, m, t, start, tuple(hiders), arr))
'''