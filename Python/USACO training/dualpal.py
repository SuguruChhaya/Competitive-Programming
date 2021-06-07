'''
LANG: PYTHON3
TASK: dualpal
'''
def dec_to_base(num,base):  #Maximum base - 36
    base_num = ""
    while num>0:
        dig = int(num%base)
        if dig<10:
            base_num += str(dig)
        else:
            base_num += chr(ord('A')+dig-10)  #Using uppercase letters
        num //= base
    base_num = base_num[::-1]  #To reverse the string
    return base_num

def is_palindrome(s):
    a = 0
    b = len(s)-1
    #!Concern is leading and trailing 0s. 
    if s[a] == "0" or s[b] == "0":
        return False
    while a <= b:
        if s[a] != s[b]:
            break
        a += 1
        b -= 1
    if a > b:
        return True
    return False

fin = open("dualpal.in", "r")
fout = open("dualpal.out", "w")

info = fin.read().strip().split(" ")
n, s = int(info[0]), int(info[1])
curr = s+1
arr = []
while n > 0:
    #!Read the fricking question properly. 
    #*2 or more. 
    counter = 0
    for i in range(2, 11):
        arr.append(dec_to_base(curr, i))
        if is_palindrome(dec_to_base(curr, i)):
            #fout.write(f"{curr}\n")
            counter += 1
            
        if counter >= 2:
            fout.write(f"{curr}\n")
            n -= 1
            break
    curr += 1

print(arr)
fout.close()

