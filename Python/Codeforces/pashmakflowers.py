
def factorial(n):
    #!I think I have encountered a situation before when recursion goes too far then the computer just cannot handle it. 
    #*Make it iterative. 
    result = 1
    while n >=1:
        result *= n
        n -= 1
    return result


#*AS long as I find the two numbers and the number of times they appear, I got the answer. 
numFlowers = int(input())
flowers = input().strip().split(" ")
for i in range(len(flowers)):
    flowers[i] = int(flowers[i])

#*Rather than solving with O(logN) time, I should linearly traverse. 
#flowers.sort()
#min_val = flowers[0]
#max_val = flowers[-1]
min_val = flowers[0]
max_val = flowers[0]
numMax = 0
numMin = 0

for i in range(len(flowers)):
    if flowers[i] == min_val:
        numMin += 1
    if flowers[i] == max_val:
        numMax += 1
    if flowers[i] < min_val:
        min_val = flowers[i]
        numMin = 1
    if flowers[i] > max_val:
        max_val = flowers[i]
        numMax = 1



result = 0

#*If it is 1 1 then two approaches. If 2 2 2 then 3. I need some kind of combination algorithm to figure out the actual number. 
#*Just naively counting will not work. 
#*I could possibly do a 2 pointer counting technique. 

#*This naive approach doesn't exclude when same numbers are counted. 
'''
for i in range(numFlowers):
    if flowers[i] != min_val:
        break
    
    numMin += 1

for j in range(numFlowers-1, -1, -1):
    if flowers[j]!=max_val:
        break
    numMax +=1
'''

#print(numMax)
#print(numMin)
#*Simple combinatorics using factorials. 
#*Except that I do have to be careful about same values. 
#!I am missing on the fact that I need to include one of the pairs from each...
if min_val == max_val:
    #*I think this really should be a simple combinatorics thing...
    #*Maybe the -2 part might be catching some errors
    #!The whole point is to prevent cramming in so much factorials when I can reduce the time. 
    result = int((numMax * (numMax-1)) / 2)
else:
    result = numMax * numMin


'''
a = 0
#*Exceeds time limit. Makes sense because worst case O(n^2)
while a < len(flowers) and flowers[a] == min_val:
    b = len(flowers) -1
    while a < b and flowers[b] == max_val:
        result += 1
        b -= 1
    a += 1
'''
    

print(f"{max_val-min_val} {result}")


'''
Having a real issue with this one.
'''