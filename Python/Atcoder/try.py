
#*Using this file to debug my C++ code for the teleportation question. 
inp = input().strip().split(" ")
a, b, c, d = inp
a, b, c, d = int(a), int(b), int(c), int(d)

visited = set()
queue = [[a, 0]]

while len(queue) != 0:
    curr = queue.pop()
