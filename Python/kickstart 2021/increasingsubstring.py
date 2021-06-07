
#*Kind of saw this problem before: kadane-ish for 

def main(s):
    #*Can just try the brute force. 
    arr = []
    for i in range(len(s)):
        temp = 1
        start = i-1
        while start >= 0 and ord(s[start]) < ord(s[start+1]):
            temp += 1
            start -= 1
        arr.append(str(temp))
    return " ".join(arr)


numTests = int(input())
for i in range(numTests):
    length = int(input())
    print(f"Case #{i+1}: {main(input())}")