
#*I think the easiest way to do this is to just simulate. 
#*Never mind I can just directly calculate.

numTests = int(input())
for i in range(numTests):
    n, x, k = input().strip().split(" ")
    n, x, k = int(n), int(x), int(k)
    if (x/k == int(x/k)) or (((n+1)-x)/k == int(((n+1)-x)/k)):
        print("YES")
    else:
        print("NO")