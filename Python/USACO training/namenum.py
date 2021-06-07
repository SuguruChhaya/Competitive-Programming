'''
LANG: PYTHON3
TASK: namenum
'''

#*Brute force will be quite ugly but no other choice. 
fin = open("namenum.in", "r")
fout = open("namenum.out", "w")
d = open("dict.txt", "r")

#*Create a set for all the elements in the dictionary. 
allNames = d.read().strip().split("\n")

#?Not really sure whether 1 can be in the solution. 
n = fin.read().strip().split("\n")[0]

char = {
    "2": ["A","B","C"],
    "3": ["D","E","F"],
    "4": ["G","H","I"],
    "5": ["J","K","L"],
    "6": ["M","N","O"],
    "7": ["P","R","S"],
    "8": ["T","U","V"],
    "9": ["W","X","Y"]
}
#iter_arr = []
#*I think java code basically did what I did. 
#*There is this while loop that I don't know what it is doing. 
#*Based on https://www.tutorialspoint.com/difference-between-plusplus-p-pplusplus-and-plusplusp-in-c#:~:text=In%20C%20programming%20language%2C%20%2Ap%20represents%20the%20value,same%20and%20both%20are%20right%20to%20left%20associative., 
#*"*p" represents pointers in C++. 
#*As long as the number of the string doesn't exceed the limit, keep adding. 
'''
for i in n:
    #*I basically need to generate all possible permutations from the arrays with a specific length but don't know how.
    #!Interesting since I cannot naively use itertools.permutations and similar combinatorics problem showed up in codejam. 
    #*Numbers can repeat. two occurences of "4" could give "G" 2 times. 
    iter_arr.append(char[i])


possibilities = []
for i in iter_arr:
    for j in range(len(i)):
        pass
    #*I am honestly kind of confused how to iterate over so many arrays. 
'''
#fout.write("GREG\n")

'''
curr_str = ""
#*Rather than a while loop solution, a recursive solution makes more sense. 
result = []
def recursive(name, numbers, i):
    #*Kind of acts like a base case. 
    if len(name) == len(numbers):
        if name in allNames:
            result.append(name)
        return 
    
    for k in char[numbers[i]]:
        temp = name + k
        #*I think I can do this without the check as well but more efficient in wiping out already incorrect answers. 
        for dName in allNames:
            #*There is a built in called startswith but too lazy. 0
            if dName[:len(temp)] == temp:
                recursive(temp, numbers, i+1)
                #*We know that if we find it in one, we don't really have to look for others. 
                break

recursive("", n, 0)

if len(result) == 0:
    fout.write("NONE\n")
else:
    for i in result:
        fout.write(f"{i}\n")
'''

'''
Above was honestly probably impossible to write with a forloop. 
While loop checks whether a string can be constructed based on every single name possible. 
'''
result = []
#*First read everything in dictionary. 
#!Trouble printing in order because unordered set. 
for name in allNames:
    #*Process the word and num at the same time. 
    #*But the pointers may have different boundaries. 
    #p1 = p2 = 0
    #!p1 checks based on the numbers and p2 followes the picked up name. 
    #while p1 < len(n) and p2 < len(name):
        #*If I am using this while loop do I even need a while loop and pointers?
    p1 = 0
    while p1 < len(n) and p1 < len(name):
        #*Check whether word is in it or not. 
        #!Check for a break condition rather than good condition. 
        if name[p1] not in char[n[p1]]:
            break

        p1 +=1
    
    #*Because of index system
    if p1 == len(n) == len(name):
        result.append(name)

if len(result) == 0:
    fout.write("NONE\n")
else:
    for i in result:
        fout.write(f"{i}\n")

    
fout.close()

#*I have to try to understand the solution. 
