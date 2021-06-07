
#*Maximum degree will obviously be 100 degrees. 
#*Literally the answer shows how to do it. 

numTests = int(input())
for i in range(numTests):
    x, a, b = input().strip().split(" ")
    x, a, b = int(x), int(a), int(b)
    print(f"{(a + (100 - x) * b) * 10}")
