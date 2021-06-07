
#*Iterate until common string breaks. Then add the individual lengths. 

def main(s1, s2):
    i = 0
    while i < min(len(s1), len(s2)) and s1[i] == s2[i]:
        i += 1
    return len(s1) - i + len(s2) - i

s1 = input()
s2 = input()
print(main(s1, s2))