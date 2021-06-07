
#*Seriously have to learn what XOR is. 
'''
xor initially means that exclusively one of the chosen values is true. 
For example, 0 and 1 has XOR of true. 
A xor b is equivalent as a != b.  
Apparantly xor can be represented as ^. Or A!=B. 

When doing the AND, I can just append 0s on the left. 

If I am shifting a number by k, usually multiplies by 2^k, 
Left: x<<k. 
Right: if I shift by right by 2, I just cut the right 2 bits. 
x>>k = math.floor(x/2^k)
'''
#*If this is just a simple implementation problem it would be relatively easy but I won't know how to optimize. 

#!Simply storing the larger one is gonna be decently easy. 
#!Must have something to do with bitwise transitions. 
#!Why don't I upsolve this problem?
'''
numTests = int(input())
for test in range(numTests):
    n = int(input())
    result = 0
    #*Cannot store in a dictionary because then memory will be crazy. 
    store = [[-1, -1], [-1, -1]]
    for i in range(100):
        #!Actually, I need to store 2 values. 
        if len(store)==2:
            if store[0][0] == i:
                left = store[0][1]
            elif store[0][1] == i:
                left = store[1][1]
            else:
                left = i^(i+1)
        else:
            left = i^(i+1)
        right = (i+2)^(i+3)
        store[0], store[1] = store[1], [i, right]
        if left == right:
            result += 1
            print(i)

    print(result)   
'''
#*Literally what the hell?
#*When I print it out it is just all the even numbers!!
#import math
numTests = int(input())
for test in range(numTests):
    n = int(input())
    #print((2**n-1) % (10**9+7))
    #print(math.ceil((2**n-1) / 2) % (10**9+7))
    #!Integer overflow is an issue here. 
    #* /*2 works well and so does % 2. 
    #*So I can first calculate floor and if odd, add 1. 
    #a = 2**n-1
    #!TLE for this is kind of crazy...
    #?But unless n==0, wouldn't a always be an odd number?
    #*And n is always > 1 so always an odd number. 
    #*Also, // 2 really just means doing 2 ** (n-1) doesn't it?
    '''
    b = a // 2
    if a % 2 == 1:
        b += 1
    print(b % (10**9+7))
    '''
    #!Fast boi. 
    #print(10**9+7)
    #!Lesss goooooo. It was 10**7 that was taking up the time!!. 
    print(pow(2, n-1, 1000000007))
    
