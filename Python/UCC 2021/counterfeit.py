
#*Naive approach will be to look for all 2s and if there is no 5 after it, counterfeit. 
def main(s):
    result = 0
    for i in range(len(s)):
        if s[i] == "2":
            if i + 1 >= len(s) or s[i+1] != "5":
                result += 1
    
    return result

print(main(input()))