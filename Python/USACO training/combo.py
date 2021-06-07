'''
LANG: PYTHON3
TASK: combo
'''
#!Instead of first generating all possible, why don't right away generate all the correct values??
fin = open("combo.in", 'r')
fout = open("combo.out", "w")

info = fin.read().strip().split("\n")
n = int(info[0])
john = info[1].split(" ")
master = info[2].split(" ")

#*Make everything an integer. 
for i in range(len(john)):
    john[i] = int(john[i])

for i in range(len(master)):
    master[i] = int(master[i])

def recursive(curr, arr):
    if len(curr) == 3:
        arr.append(curr)
    else:
        for i in range(1, n+1):
            #!Cannot do the keep adding approach becuase will overflow. 
            #*Store in arr and check arr length. 
            recursive(curr+[i], arr)
#!Rather than absolute value, probably easier to just iterate and check. 
order = []
for i in range(1, n+1):
    order.append(i)
order *= 3
#!In order to avoid weird negatives and index errors, I should do the triple thing. 

result = 0
#!I honestly don't know if this is a duplicate issue or what. 
arr = []
new_arr = []
#recursive([], arr)

#*curr will be the current length we have. Get the john, master value from here. 
#*person will be either john or master. 
#*Hashset will be mutable. 
#!Even though I made more efficient, still missing some.
def recursive(curr, person, hashset):
    #!The only issue here is that there is length can exceed and I have to accomodate. 
    #*Best way is to just manage by tuples. 
    if len(curr) == 3:
        hashset.add(curr)
    else:
        for i in range(n + person[len(curr)]-1-2, n+person[len(curr)]-1-2+5):
            if 0 <= i < len(order):
                #print(order[i])
                #!Tuple is separating it. 
                a = curr+(str(order[i]),)

                recursive(a, person, hashset)
#!I need to make sure there is no overlap so I can create a  set and finally take its length. 
hashset = set()
recursive((), john, hashset)
recursive((), master, hashset)
fout.write(f"{str(len(hashset))}\n")
new_arr = list(hashset)
#!Since stored in string, check doesn't recognize it. 
'''
#!Seems like whatever that comes below isn't being counted properly. 
#!I think my overall strategy was to check who's lock it must be close to and narrow it down. 
for i in range(len(arr)):
    #*Need to be consistent. 
    #!Kind of confusing because there could be overlap. 
    
    #*Store possible. 
    pick = []
    #!Maybe individual changes are influencing the overall thing. 
    #!Didn't consider the adjacent thing. 
    #*Similar to the necklace example, I think it might be good to combine 3 and iterate over the middle one. 
    
    for j in range(3):
        if j == 0:
            #!Which 3 numbers could this be based on given input?
            #!Changing this index literally gives me the same answer. 
            for a in range(n + john[j]-1-2, n+john[j]-1-2+5):
                #!Shouldn't I really be checking for i?
                
                if 0 <= a < len(order) and arr[i][j] == order[a]:
                    pick.append(john)
                
            for a in range(n + master[j]-1-2, n + master[j]-1-2+5):
                if 0 <= a < len(order) and arr[i][j] == order[a]:
                    pick.append(master)
            
            #!Absolute value even won't work because 
            if abs(arr[i][j]-john[j]) <= 2:
                pick.append(john)
            if abs(arr[i][j] - master[j]) <= 2:
                pick.append(master)
            #*As usual, check whether neither applies. 
            #!The bottom code doesn't really make a big difference. 
            
            #*Otherwise, as usual, I have to add 1. 
            
            if add == True:
                result += 1
            
        
        #*At any point, if the length of pick is 0, we have to exit. 
        else:
        #!In this case, I think add needs a special treatment. 
            add = False
            #!The thing is that we cannot be doing this 3 times. 
            person = 0
            #!The while loop is causing some kind of problem. 
            while person < len(pick):
                worked = False
                #!Shouldn't really be john but rather the person. 
                for a in range(n + pick[person][j]-1-2, n + pick[person][j]-1-2+5):
                    if 0 <= a < len(order) and order[a] == arr[i][j]:
                        add = True
                        #*Won't add 1 to person just yet. 
                        worked = True
                
                
                if worked == False:
                    pick.remove(pick[person])
                else:
                    person += 1
                
                if abs(arr[i][j]-pick[person][j]) <= 2:
                    add = True
                    person += 1
                else:
                    pick.remove(pick[person])
                    #!This just removes it and I don't get to check if the length of pick is smaller or not. 
                    #*Plus running a forloop may cause some issues. Probably should add the len check at the end. 
                
    #!Definitely getting smaller but not to the point where I want it to be.      
    #*Do I even need this?
    if len(pick) == 0:
        add = False      
    if add == True:
        result += 1
        #*Maybe append to result and see which type of answers don't exist. 
        new_arr.append(arr[i])

#!Missing all the huge numbers. 
fout.write(f'{result}\n')
'''
'''
#*Write a program that reads correct answer and outputs whatever was included and wasn't included. 
fin = open("combocorrect.txt", "r")
info = fin.read().strip().split("\n")
all_correct =  []
for i in range(len(info)):
    temp = info[i].strip().split("  ")
    for j in temp:
        comb = tuple(j.strip().split(","))
        all_correct.append(comb)

fout.write(f"Values that were in correct but not in mine:\n")
in_correct = []
for i in all_correct:
    if i not in new_arr:
        in_correct.append(i)

in_correct.sort()
for i in in_correct:
    fout.write(f"{i}\n")

fout.write(f"Values that were in my answer but not in correct\n")
in_mine = []
for i in new_arr:
    if i not in all_correct:
        in_mine.append(i)

in_mine.sort()
for i in in_mine:
    fout.write(f"{i}\n")

'''
fout.close()


