from itertools import permutations

#*Might use the permuations tool. 

n = input()
s = input()

d = {}
for i in s:
    if i in d:
        d[i] += 1
    else:
        d[i] = 1

numOdds = 0
for i in d.keys():
    #*Count the number of odd. 
    if d[i] % 2 == 1:
        numOdds += 1

print(max(1, numOdds))


'''
a = list(permutations(s, len(s)))

#!I see, technically, 1 letter is a palindromic substring so that will be the maximum. 
#*basically longest palindromic stringbut doesn't have to be same length. 
#*Number of character also apparantly matter which makes sense because without that many characters, palindrome cannot be formed. 

def is_palindrome(s):
    if s == reversed(s):
        return True
    return False

def recursive(curr_string):
    pass

result = 0
for word in a:
    #*How am I gonna check how many palindromic substrings exist? 
    #!Can kind of think of a recursive/depth-first approach but...
    #*Really confusing question so leave. 
    pass

#*Very interesting idea onto how to solve this. 
#*Letters that have even occurences can be combined to form one palindrome. 
'''

