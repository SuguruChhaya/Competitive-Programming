from collections import deque
from itertools import permutations
from sys import stdin
input = stdin.readline
n, m, t = list(map(int, input().split()))
grid = [list(input()) for i in range(n)]

hiders = []
g = (0, 0)
for row in range(len(grid)):
    for col in range(len(grid[row])):
        if grid[row][col] == 'G':
            g = (row, col)
        if grid[row][col] == 'H':
            hiders.append((row, col))

dists = [[0 for i in range(5)]for y in range(6)] # griffy is 6
visited = [[0 for i in range(m)] for y in range(n)]
def BFS(start): # tuple
    global visited
    Q = deque([start])
    for i in range(n):
        for y in range(m):
            visited[i][y] = 0# stores the dist
    while Q: #!I don't think this would cause an issue but for simplicity's sake, I think it would be better. Yah never visit this one.  
        r, c = Q.pop() #!Basically the smallest number of steps it takes to get there from a certain node. 
        if r > 0 and not visited[r-1][c] and grid[r-1][c] != 'X':
            Q.appendleft((r-1, c))
            visited[r-1][c] = visited[r][c] + 1
        if r < n-1 and not visited[r+1][c] and grid[r+1][c] != 'X':
            Q.appendleft((r+1, c))
            visited[r+1][c] = visited[r][c] + 1
        if c > 0 and not visited[r][c-1] and grid[r][c-1] != 'X':
            Q.appendleft((r, c-1))
            visited[r][c-1] = visited[r][c] + 1
        if c < m-1 and not visited[r][c+1] and grid[r][c+1] != 'X':
            Q.appendleft((r, c+1))
            visited[r][c+1] = visited[r][c] + 1


    return visited

firstfind = BFS(g)
#!He first finds the shortest distance among paths then create the permutations and use stored data to find the length. 

for i in range(t): # from griffy
    r, c = hiders[i]
    dists[5][i] = firstfind[r][c]
for i in range(t):
    find = BFS(hiders[i])
    for y in range(t):
        r, c = hiders[y]
        dists[i][y] = find[r][c]

toperm = []
for i in range(t):
    toperm.append(i)
low = float('inf')
choices = permutations(toperm)
for i in choices:
    temp = 0
    temp += dists[5][i[0]]
    if t > 1:
        temp += dists[i[0]][i[1]]
    if t > 2:
        temp += dists[i[1]][i[2]]
    if t > 3:
        temp += dists[i[2]][i[3]]
    if t > 4:
        temp += dists[i[3]][i[4]]
    if temp < low:
        low = temp
print(low)