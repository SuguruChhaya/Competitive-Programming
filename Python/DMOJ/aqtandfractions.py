t = int(input())
for i in range(t):
    inp = input().strip().split(" ")
    a, b = inp
    a, b = int(a), int(b)
    if (b==3 and (a==1 or a==2 or a==4 or a==5)):
        print(-1)
    else:
        c = str(a / b)
        index = len(c) -1
        #*There could be cases with no decimal points. 
        #!Need to make sure I can pass that. 
        result = 0
        #!Have to consider trailing zeros too. 
        while (index >= 0 and c[index]!='.'):
            index-=1
            result+=1
        if (index==-1):
            print(0)
        else:
            print(result)
