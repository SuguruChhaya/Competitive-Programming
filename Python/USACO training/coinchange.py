def getWays(n, c):
    # Write your code here
    #?Are there 0 ways to get to 0 or 1 way?
    #*Since there may be 1 way to get to 1 so 0. 
    d = {0: {tuple([0])}}
    #*Since we aren't adding 1, 0 just has 1 way. 
    a =  recursive(n, d, c)
    #print(d)
    #!One issue here is that elements with same order must be treated as 1. 
    #*Degenerate cases are really tricky. 
    #*Just store in a set so it is less tricky. 
    return len(a)
    
#*The hackerrank version asks for the number of ways I can get there so kind of like apply knowledge. 
'''
def recursive(curr, d, c):
    if curr<0:
        #*Probably should return an empty set to show that nothing. 
        return set()
    #!There must be a way to distinguish between "not seen" and no way to get there. 
    elif curr in d:
        return d[curr] 
    else:
        d[curr] = set()
        for i in c:
            #*Find the minimum
            
            #!I have to check whether to even add it. 
            #*I AM calling the recursive function for every increment. 
            d[curr-i] = recursive(curr-i, d, c)
            #*If we cannot get there, this loop shouldn't run in the first place. 
            #!Time exceeded is definitely because of this inner loop. 
            #*Isn't there a way to check whether the matching is degenerate and has already covered?
            for j in d[curr-i]:
                #!Cannot assume it is there. 
                #*Loop through all and add the current number in. 
                d[curr].add(tuple(sorted(j + (i,))))
    return d[curr]
'''
'''
def recursive(i, curr, d, c):
    if curr < 0:
        return 0
    if curr == 0:
        return 1
    if i >= len(c):
        return 0
    
    if curr not in d:
        d[curr] = recursive(i+1, curr, d, c) + recursive(i, curr-c[i], d, c)
    return d[curr]
        

def getWays(n, c):
    # Write your code here
    #*First the top down approach: we have a set number of times we can use a certain coin or not. So we can either use that coin again or move on to the next coin. 
    d = {
        0:1
    }
    #*i is the current index we are lookin at. The current we are at too. 
    return recursive(0, n,d, c)
'''
#!The editorial page starts i from 1 because it is mentioned in the problem statement that 1 <= c[i] <= 50

def recursive(i, make, d, arr):
    if make == 0:
        return 1
    #*Shouldn't it be if i==-1?
    if i == -1:
        return 0
    
    if i not in d:
        d[i] = {}
    if make not in d[i]:
        if arr[i] > make:
            d[i][make] = recursive(i-1, make, d, arr)
        else:
            d[i][make] = recursive(i-1, make, d, arr) + recursive(i, make-arr[i], d, arr)
    return d[i][make]

def getWays(n, arr):
    d = {}
    return recursive(len(arr)-1, n, d, arr)

n =4
arr = [1, 2, 3]
print(getWays(n, arr))