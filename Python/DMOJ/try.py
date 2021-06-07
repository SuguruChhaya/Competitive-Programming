'''
#*Check how priority queue takes. 
from queue import PriorityQueue

a = PriorityQueue()
a.put((1))
a.put((2))
while not a.empty():
    curr = a.get()
    print(curr)

from itertools import permutations

a = permutations("abc", 3)
print(list(a))
'''

#*For the codechef long modulus question, I know that it is not strictly m = m % b. 

#*Just to test my hypothesis that if 1 <= a < b<= N then (M%a)%b == M%a. 

#*Generate a from 1 to n+1. 
#*Generate b from a+1 to n+1. 
#*Print out whatever doesn't match. 
#*m=20. 

m = 100
n = 2

for a in range(1, n+1):
    for b in range(a+1, n+1):
        if (m%a)%b != m%a:
            print(f"a: {a}, b: {b}. m%a%b = {(m%a)%b}, m%a = {m%a}")



