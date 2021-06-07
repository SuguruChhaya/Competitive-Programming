

#*The brute force seems simple enough: Just brute force until I reach the upper limit. 
#*But considering the 10^5 limit it might be tough. 
#!Time limit exceeded for even the first question?? Bruh...
#*There must be some kind of special property for modulus. 
def main(n, m):
    result = 0
    for a in range(1, n+1):
        for b in range(a+1, n+1):
            if ((m % a) % b) == ((m % b) % a):
                print((a, b))
                result += 1
    
    return result


numTests = int(input())
for i in range(numTests):
    n, m = input().strip().split(" ")
    n, m = int(n), int(m)
    print(main(n, m))