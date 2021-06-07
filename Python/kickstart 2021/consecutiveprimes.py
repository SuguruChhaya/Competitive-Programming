
#*I think this problem is more relatively straightforward. 
#*The brute force will be to find all prime numbers until that point and multiply all consucutive and find the best. 
#*But the better way may be to prime factor the number and see if it factor of 2 primes. Increment downward.

import math
#!Maybe some issues with this function because intended purpuse wasn't to prime factorize. 
def primefactors(n):
    #even number divisible
    arr = []
    while n % 2 == 0:
        arr.append(int(2))
        n = n / 2
        
    #n became odd
    for i in range(3,int(math.sqrt(n))+1,2):
        while (n % i == 0):
            arr.append(int(i))
            n = n / i
    if n > 2:
        arr.append(int(n))

    return sorted(arr)

def is_prime(n):
    for i in range(2, n):
        if n % i == 0:
            return False
    return True

#!Without using optimized version, it will run out of time. 
def is_prime(n):
    if (n <= 1) :
        return False
    if (n <= 3) :
        return True
    if (n % 2 == 0 or n % 3 == 0) :
        return False
    i = 5
    while(i * i <= n) :
        if (n % i == 0 or n % (i + 2) == 0) :
            return False
        i = i + 6
    return True


def main(n):
    '''
    for i in range(n, -1, -1):
        a = primefactors(i)
        #!Cannot be the same!!
        if len(a) == 2 and a[0] != a[1]:
            add = True
            #Have to check whether the numbers are consecutive so run a loop to check for all primes during the range. 
            for j in range(a[0]+1, a[1]):
                #*If there is a prime number then not OK. 
                if len(primefactors(j)) == 1:
                    add = False
            
            if add == True:
                return i
    '''
    #!Could possibly shave off some time by finding them in correct order. Make sure no overlap. 
    s = int(math.sqrt(n))
    smaller_1 = None #The larger of the smaller
    smaller_2 = None #The smaller of the larger
    larger_1 = None #The only larger. 
    curr = s
    #!Need to make sure that curr never goes below. 
    #*When talking about factors and stuff, halfway point is key. 
    while curr >= 2 and (smaller_1 == None or smaller_2 == None):
        #!This primefactors method may also have some problems. 
    
        if is_prime(curr):
            if smaller_1 == None:
                smaller_1 = curr
            else:
                smaller_2 = curr
        curr -= 1
    
    curr = s+1
    while larger_1 == None:
        if is_prime(curr):
            larger_1 = curr
        curr += 1

    #!I honestly think it is just the method I check for prime or not. 
    #*Knowing the prime gaps, I should just 
    if smaller_1 * larger_1 <= n:
        return smaller_1 * larger_1
    #*Since have to be consecutive, not much combination to take care of. 
    else:
        return smaller_1 * smaller_2
    
    

#*Use the sieve of eratostenes to find prime?
#*We must find a prime that is greater than sqrt(n). Then just multiply and find. So for test cases like 10^9 just find until 10^5. 
#*The maximal prime information is just kind of an FYI stuff and I do have to iterate over all and figure it out and maybe it may run in time. 
'''
numTests = int(input())
for i in range(numTests):
    n = int(input())
    print(f"Case #{i+1}: {main(n)}")
'''
'''
fin = open("consecutiveprimes/test_set_3/ts3_input.txt", "r")
fout = open("consecutiveprimes/test_set_3/my_output.txt", "w")
info = fin.read().strip().split("\n")
'''
numTests = int(input())
for i in range(numTests):
    n = int(input())
    print(f"Case #{i+1}: {main(n)}\n")
    #print('done')
#print(primefactors(4))
#fout.close()
