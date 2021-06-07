'''
LANG: PYTHON3
TASK: palsquare
'''

#*Not too sure about the base system. 
#*Conversion must be done at some point but where exactly?
#*Am I converting N or am I just converting n^2

#!Honestly, the conversion shouldn't be the hard part. I can copy paste. 

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

#*Trust. 

fin = open("palsquare.in", "r")
fout = open("palsquare.out", "w")

b = int(fin.read().strip().split("\n")[0])
#*Does both integers being in base b make difference?
def is_palindrome(s):
    a = 0
    b = len(s)-1
    while a <= b:
        if s[a] != s[b]:
            break
        a += 1
        b -= 1
    if a > b:
        return True
    return False

#*Relationship is kind of messed up. 
#Convert n into base 10 -> s = n^2 -> convert s -> check whether palinrome -> if it is, output converted n and converted s. 
#Convert n. convert n ** 2. Check palindrome. 
for i in range(1, 301):
    #*First calculate the square and convert.
    #!No point converting i because it is already in base 10. 
    '''
    base_n = dec_to_base(i, 10)
    #*base_n doesn't contain strings so int() won't cause errors. 
    base_s = int(base_n) ** 2
    s = dec_to_base((base_s), b)
    if is_palindrome(s):
        fout.write(f"{i} {s}\n")
    '''
    converted_n = dec_to_base(i, b)
    converted_s = dec_to_base(i ** 2, b)
    if is_palindrome(converted_s):
        fout.write(f"{converted_n} {converted_s}\n")

fout.close()
    