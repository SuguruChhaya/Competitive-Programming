import math

def main(n):
    '''
    a = math.log(n, 2)
    #!Just an integer?
    if math.log(n, 2) == int(math.log(n, 2)):
        return "YES"
    else:
        return "NO"
    '''
    if math.sqrt(n / 2) == int(math.sqrt(n/2)) or math.sqrt(n/4) == int(math.sqrt(n/4)):
        return "YES"
    else:
        return "NO"
        
numTests = int(input())
for i in range(numTests):
    n = int(input())
    print(main(n))