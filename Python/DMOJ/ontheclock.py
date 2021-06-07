import math
#*N and M are integers so no worry about decimal stuff. 
#*Small diffence when it comes to negative numbers but 
#!Pretty sure negative numbers aren't allowed so shouldn't make a difference. 

def main(n, m):
    prev_x = 0
    result = []
    for curr_y in range(1, n+1):
        curr_x = m * (curr_y / n)
        #!Just looking, there must be the case where prev_x doesn't really equal to the left edge. 
        for target_x in range(prev_x, math.ceil(curr_x)):
            result.append([str(curr_y), str(target_x+1)])
        prev_x = int(curr_x)    
    return result

#!The less complex, the better I guess...
def main(n, m):
    #*The reason we can iterate through every column is because the next one starts at that point so we cannot start at a row lower than that. 
    #!Just print instead of storing it.
    #!But how will I know the length then... 
    result = []
    for i in range(1, m+1):
        left_edge = n * (i-1) / m
        right_edge = n * i / m
        for j in range(math.floor(left_edge), math.ceil(right_edge)):
            result.append(" ".join([str(j+1), str(i)]))
    return result

def main(n, m):
    #!What makes the previous one not pass then?
    result = []
    prev = 0
    for i in range(1, n+1):
        up_edge = m * i/ n
        
        for j in range(prev, math.ceil(up_edge)):
            result.append(" ".join([str(i), str(j+1)]))
        prev = int(up_edge)
    return result

#!Sometimes things as small as 
def main(n, m):
    prev_x = 0
    result = []
    for curr_y in range(1, n+1):
        curr_x = m * curr_y / n
        #!Just looking, there must be the case where prev_x doesn't really equal to the left edge. 
        for target_x in range(prev_x, math.ceil(curr_x)):
            result.append(" ".join([str(curr_y), str(target_x+1)]))
        prev_x = int(curr_x)    
    return result

n, m = input().strip().split(" ")
n, m = int(n), int(m)
arr = main(n, m)
print(len(arr))
for i in arr:
    print(i)