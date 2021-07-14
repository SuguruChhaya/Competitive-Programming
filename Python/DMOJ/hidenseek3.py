
#*Use USACO Guide's method that doesn't require sets and stuff to solve in constant time. 

arr = []

#*I think I have to store the number of hiders as well. 
hiders = []
distances = {}
#*It indeed would be a waste to just re-find the distance between the same path again and again. 
#*Especially since each path requires to use a queue so costs extra space. 
#*Guess I could store in a dictionary with the distance. 
'''
def find_length():
    global distances
    for h1 in range(0, len(hiders), 1):
        for h2 in range(h1+1, len(hiders), 1):
            #*No repeating so should cost less space. 
            #*hiders[h1] is gonna be an array. 
            #!I need to store the distance as well. 
            queue = [[0, hiders[h1]]]
            while len(queue) > 0:
                curr = queue[0]
                queue.pop(0)
                if (queue[1]==h2):
                    #!Python dicts cannot even contain a list inside tuple. 
                    distances[(h1, h2)] = queue[0]
                else:
                    #*I also have to check whether I visited or not. 
                    pass
                 
'''
#*I guess it would be first better to check whether this way of setting permutations works within memory or not. 
numPerms = 0
n = 0
m = 0
t = 0
'''
perm_arr = []
def perm():
    global numPerms, perm_arr
    if len(perm_arr) == len(hiders):
        numPerms+=1
    else:
        #*Really, I could just iterate through the hiders list to save time. 
        #!I guess recursion is just too heavy or something. 
        for row in range(n):
            for col in range(m):
                if (arr[row][col]=='H'):
                    arr[row][col] = '.'
                    perm_arr.append([row, col])
                    perm()
                    arr[row][col] = 'H'
                    perm_arr.pop()

'''

def main():
    global hiders
    global n, m, t
    global numPerms 
    inp = input().strip().split()
    n, m,t = inp
    n, m, t = int(n), int(m), int(t)
    
    for i in range(n):
        inp = input()
        temp = []
        for j in range(m):
            if (inp[j]=='H'):
                hiders.append((i, j))
            temp.append(inp[j])
        arr.append(temp)
    #find_length()
    
    #perm()
    print(numPerms)
        
main()