'''
LANG: PYTHON3
TASK: beads
'''

fin = open("beads.in", "r")
fout = open("beads.out", "w")

info = fin.read().strip().split('\n')
#*Gave me the string. 
numBeads = int(info[0])
beads = info[1]
beads *= 2
#*Have consecutive so that it covers everything. 
#*Left side is red and right side is blue. 
left = [[0, 0]]
right = [[0, 0]]

#?Should I run the loop on the 2x string or just the 1x?
#!The only time double traversal gets screwed up is when it is just the same color for the entire time. 
for i in range(len(beads)):
    if beads[i] == "r":
        left.append([left[-1][0]+1, 0])
    elif beads[i] == "b":
        left.append([0, left[-1][1]+1])
    elif beads[i] == "w":
        left.append([left[-1][0]+1, left[-1][1]+1])

for i in range(len(beads)-1, -1, -1):
    if beads[i] == "r":
        #!I have to be really careful with the insertion order. 
        right.insert(0, [right[0][0]+1, 0])
    elif beads[i] == "b":
        right.insert(0, [0, right[0][1]+1])
    elif beads[i] == "w":
        right.insert(0, [right[0][0]+1, right[0][1]+1])

#!I have to find the longest among the indices. 
#*So I think I will have to loop through and look for max.
m = 0
for i in range(len(beads)):
    m=max(m, max(left[i][0], left[i][1]) + max(right[i][0], right[i][1]))

m = min(m, numBeads)
fout.write(f"{m}\n")
fout.close()