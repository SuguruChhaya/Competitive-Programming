
#*CPP didn't work so quickly code this.

n = int(input())
a = input().strip().split(" ")
b = input().strip().split(" ")
c = input().strip().split(" ")

d = {}
for i in range(n):
    if a[i] not in d:
        d[a[i]] = 1
    else:
        d[a[i]] += 1
result = 0
for j in range(n):
    if b[int(c[j])-1] in d:
        result += d[b[int(c[j])-1]]

print(result)