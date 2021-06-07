
#!I can easily use memoization to store the minimum number of minutes it took me to reach that house so that I prevent stupid back and forth. 
#*Ran into a recursion error...
#*Can I do this iteratively?
#*Can I possibly iterate and do all movements?
import sys
#sys.setrecursionlimit(99999999999999999999999999)
def recursive(n, currHouse, currMin, arr, memo):
    '''
    if currHouse == n:
        return currMin
    elif currHouse > n or currHouse < 1:
        return 9999999999999999999999999999999999999
    #!I really should be able to access it while precomputing. 
    elif memo[currHouse-1] != -1 and memo[currHouse] < currMin:
        return memo[currHouse-1]
    else:
        memo[currHouse-1] = min(recursive(n, currHouse+1, currMin+1, arr, memo),
        recursive(n, currHouse-1, currMin+1, arr, memo),
        recursive(n, currHouse+arr[currHouse-1], currMin+1, arr, memo))
        
        return memo[currHouse-1]
    '''
    if 1 <= currHouse <= n:
        #*Probably can connect using or. 
        if memo[currHouse-1] == -1 or memo[currHouse-1] > currMin:
            memo[currHouse-1] = currMin
            recursive(n, currHouse+1, currMin+1, arr, memo)
            recursive(n, currHouse-1, currMin+1, arr, memo)
            recursive(n, currHouse+arr[currHouse-1], currMin+1, arr, memo)
            recursive(n, currHouse-arr[currHouse-1], currMin+1, arr, memo)
        '''
        else:
            #!Really need to put a stop at it here. 
            #*If smaller, no point even doing it. 
            if memo[currHouse-1] > currMin:
                memo[currHouse-1] = currMin
                recursive(n, currHouse+1, currMin+1, arr, memo)
                recursive(n, currHouse-1, currMin+1, arr, memo)
                recursive(n, currHouse+arr[currHouse-1], currMin+1, arr, memo)
        '''
        '''
            memo[currHouse-1] = min(memo[currHouse-1], currMin)
        recursive(n, currHouse+1, currMin+1, arr, memo)
        recursive(n, currHouse-1, currMin+1, arr, memo)
        recursive(n, currHouse+arr[currHouse-1], currMin+1, arr, memo)
        '''

def main(n):
    fib = [1, 1]
    for i in range(n-2):
        fib.append(fib[-1]+fib[-2])

    arr = []
    for i in range(n):
        arr.append((fib[i] % 2021) + ((i+1) % 50))
    memo = [-1] * n 
    #memo[0] = 0
    #!Maybe I should just modify memo and return the last elment. 
    #return recursive(n, 1, 0, arr, memo)
    #*Problem in the initial starting value. 
    #recursive(n, 1, 0, arr, memo)
    #return memo[-1]
    #!Very interesting question want to upsolve tbh. 
    #for i in range()

#*I think I can just use BFS instead of recursion. 
def main(n):
    #!Using A*, this is the furthest I can really get to. 
    #*There must be something regarding the fibonacci function that makes it unique. 
    #!Fibonaccis can get really big soon (especially for 10*5) so I should build the function array and store the 2 previous fibonaccis separately. 
    if n > 10:
    first_fib = 1
    second_fib = 1
    arr = [2, 3]
    #!Couldn't it really be this loop that is taking up so much time?
    #?Maybe I don't even have to compute all the values? Maybe I can just find along the way so I only find values I need. 
    #!But then I do need to calculate fib. 
    
    for i in range(3, n+1):
        first_fib, second_fib = second_fib, first_fib + second_fib
        arr.append((second_fib % 2021 + (i) % 50))
        #fib.append(fib[-1]+fib[-2])
    print(arr)
    '''
    fib = [1, 1]
    for i in range(n-2):
        fib.append(fib[-1]+fib[-2])
    arr = [0] * n 
    '''
    

    #!If I can find a repetitive pattern to this, it would really good. 
    '''
    for i in range(n):
        fib[i] = ((fib[i] % 2021) + ((i+1) % 50))
    '''
    
    #print(arr)
    
    #*What data might I need?
    #*Queue structure will probably work for first test case but memory will probably exceed for the second one. 
    #*(current house number, number of minutes)
    #*Create a min_steps to reduce number. 
    #min_minutes = [99999999999999] * n
    queue = [(1, 0)]
    seen = [False] * n
    while len(queue) != 0:
        curr = queue.pop(0)
        if curr[0] == n:
            return curr[1]
        #*Check if out of range. 
        #!Since this is BFS this condition is really useless because curr[1] will never be smaller. 
        #*Pre check isn't working in this case. 
        elif 1 <= curr[0] <= n:# and seen[curr[0]-1] == False:
            '''
            if arr[curr[0]-1] == 0:
                arr[curr[0]-1] = ((fib[curr[0]-1] % 2021) + ((curr[0]) % 50))
            '''
            '''
            queue.append((curr[0]+1, curr[1]+1))
            queue.append((curr[0]-1, curr[1]+1))
            queue.append((curr[0]+arr[curr[0]-1], curr[1]+1))
            queue.append((curr[0]-arr[curr[0]-1], curr[1]+1))
            '''
            #!OK if TLE at Case #3, the queue must be going on forever. 
            #seen[curr[0]-1] = True
            if 0 <= curr[0]+1-1 < len(arr) and seen[curr[0]+1-1] == False:
                queue.append((curr[0]+1, curr[1]+1))
            if 0 <= curr[0]-1-1 < len(arr) and seen[curr[0]-1-1] == False:
                queue.append((curr[0]-1, curr[1]+1))
            if 0 <= curr[0]+arr[curr[0]-1]-1 < len(arr) and seen[curr[0]+arr[curr[0]-1]-1] == False:
                queue.append((curr[0]+arr[curr[0]-1], curr[1]+1))
            if 0 <= curr[0]-arr[curr[0]-1]-1 < len(arr) and seen[curr[0]-arr[curr[0]-1]-1] == False:
                queue.append((curr[0]-arr[curr[0]-1], curr[1]+1))
            
        '''
        elif 1 <= curr[0] <= n and curr[1] < min_minutes[curr[0]-1]:
            min_minutes[curr[0]-1] = curr[1]
            queue.append((curr[0]+1, curr[1]+1))
            queue.append((curr[0]-1, curr[1]+1))
            queue.append((curr[0]+arr[curr[0]-1], curr[1]+1))
            queue.append((curr[0]-arr[curr[0]-1], curr[1]+1))
        '''
    
    '''
    while len(queue) != 0:
        curr = queue.pop(0)
        if curr[0] == n:
            return curr[1]
        min_minutes[curr[0]-1] = curr[1]
        if 0 <= curr[0]+1-1 < len(arr) and curr[1]+1 < min_minutes[curr[0]+1-1]:
            queue.append((curr[0]+1, curr[1]+1))
        if 0 <= curr[0]-1-1 < len(arr) and curr[1]+1 < min_minutes[curr[0]-1-1]:
            queue.append((curr[0]-1, curr[1]+1))
        if 0 <= curr[0]+arr[curr[0]-1]-1 < len(arr) and curr[1] + 1 < min_minutes[curr[0]+arr[curr[0]-1]-1]:
            queue.append((curr[0]+arr[curr[0]-1], curr[1]+1))
        if 0 <= curr[0]-arr[curr[0]-1]-1 < len(arr) and curr[1] + 1 < min_minutes[curr[0]-arr[curr[0]-1]-1]:
            queue.append((curr[0]-arr[curr[0]-1], curr[1]+1))
    '''
n = int(input())
print(main(n))