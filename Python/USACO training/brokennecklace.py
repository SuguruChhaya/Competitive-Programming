'''
LANG: PYTHON3
TASK: beads
'''


#*A string reading ad-hoc problem. 
#*The obvious brute force would be to try an incision at every possible place and calculate score. 
#*O(n^2) worst case. 
fin = open("beads.in", "r")
fout = open("beads.out", "w")
numBeads, beads = fin.read().strip().split("\n")
numBeads = int(numBeads)
result = 0
#!Must be a better way to store all contiguous and run in linear time. 
#*Probably will use extra space though. 
#*Doesn't make sense to make a cut in between a contiguous sequence. 
#*Also, doesn't really matter if white becomes same as previous or next because same result happens at different index. 
#*First traverse and record all the changing points and possibly the most recent changing points to the left and to the right. 
#*Then do final traverse to find maximum. 
#*Cannot have a permlink so just keep submission link open.     

for i in range(numBeads):
    #left = i -1 
    #right = i
    #*Right doesn't necessarily have to be larger than left. 
    #*Since brute force, free to use as much memory. 
    newString = ""
    start = i
    while len(newString) != numBeads:
        newString += beads[start]
        start += 1
        if start >= numBeads:
            start = 0
    
    a = 0
    b = numBeads - 1
    while a < numBeads and newString[a] == "w":
        a +=1
    #*Just so when all are white. 
    if a == numBeads:
        start_must = "r"
    else:
        start_must = newString[a]
    
    while b >= 0 and newString[b] == "w":
        b -= 1
    
    if b == -1:
        end_must = "r"
    else:
        end_must = newString[b]

    a = 0
    b = len(beads)-1

    temp = 0 
    #!I don't think I considered the case when "w" could actually be the starting. 
    #*I have to also consider the case when all beads are white. 
    while a < numBeads and (newString[a] ==start_must or newString[a] == "w"):
        temp+=1
        a +=1
    
    #*Must consider the case of not exceeding. 
    while (b >= 0 and b >= a) and (newString[b] == end_must or newString[b] == "w"):
        temp += 1
        b -= 1
    
    result = max(result, temp)

fout.write(f"{result}\n")

