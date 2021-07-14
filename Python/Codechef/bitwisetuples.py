#*Try using stdin for faster input. 
import sys

numTests = int(input())

#*Honestly, I think the way to go is to create a table before hand so I can access the values in constant time. Might actually help.

arr = []
curr = 1


for i in range(numTests):
    n, m = input().split(" ")
    n, m = int(n), int(m)
    #*How can I make this faster??
    #*Still TLEs even with Pypy. 
    
    #print(pow(arr[n]-1, m, 1000000007))

    #*Calculate using mod. If the answer is 0, the actual answer is 1000000006 since we have to subtract 1. 
    temp = pow(2, n, 1000000007)
    if temp == 0:
        temp = 1000000006
    else:
        temp-=1
    print(pow(temp, m, 1000000007))

