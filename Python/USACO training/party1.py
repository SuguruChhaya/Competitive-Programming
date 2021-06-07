
#*Example problem in the USACO training. 
#*Check time complexity using the most brute force way. 
#Template
'''
import time
start_time = time.time()

test = "party/party1"
fin = open(f"{test}.in", "r")
fout = open(f"{test}.out", "w")

fout.close()

print(f"{time.time()-start_time}seconds")
'''
import time
start_time = time.time()

folder = "party"
file = "party2"
fin = open(f"{folder}/{file}.in", "r")
fout = open(f"{folder}1/{file}.out", "w")

info = fin.read().strip().split("\n")
numLamps = int(info[0])
numPresses = int(info[1])
must_be_on = info[2].split(" ")
must_be_off = info[3].split(" ")
del(must_be_on[-1])
del(must_be_off[-1])

#*Recursive function. 
def recursive(num_switches_left, switch_no, curr, hashset):
    #global numRan
    if num_switches_left == 0:
        #*When we reach down to 0, we are going  to add into the arr. 
        #!We actually cannot append it into an array because then duplicates might occur. 
        #*Use a set instead. 
        for i in range(len(curr)):
            curr[i] = str(curr[i])
        hashset.add("".join(curr))
    else:
        #*Need to make the necessary modifications first. 
        #numRan += 1
        if switch_no ==1:
            for i in range(1, len(curr)+1):
                if curr[i-1] == 1:
                    curr[i-1] = 0
                else:
                    curr[i-1] = 1
        elif switch_no == 2:
            for i in range(1, len(curr)+1):
                if i % 2 == 1:
                    if curr[i-1] == 0:
                        curr[i-1] = 1
                    else:
                        curr[i-1] = 0
        elif switch_no == 3:
            for i in range(1, len(curr)+1):
                if i % 2 == 0:
                    if curr[i-1] == 0:
                        curr[i-1] = 1
                    else:
                        curr[i-1] = 0
        elif switch_no == 4:
            for i in range(1, len(curr)+1):
                if i % 3 == 1:
                    if curr[i-1] == 0:
                        curr[i-1] = 1
                    else:
                        curr[i-1] = 0

        recursive(num_switches_left-1, 1, curr, hashset)
        recursive(num_switches_left-1, 2, curr, hashset)
        recursive(num_switches_left-1, 3, curr, hashset)
        recursive(num_switches_left-1, 4, curr, hashset)

hashset = set()
#*Have to think about numswitches left. -> Correct
#numRan = 0
recursive(numPresses, 1,[1] * numLamps, hashset)
recursive(numPresses, 2, [1] * numLamps, hashset)
recursive(numPresses, 3, [1] * numLamps, hashset)
recursive(numPresses, 4, [1] * numLamps, hashset)
#print(numRan)
for i in hashset:
    #*Check whether adheres to the conditions. 
    add = True
    #*Somehow 0110110110 is getting printed. 
    for j in must_be_on:
        if i[int(j)-1] != "1":
            add = False
    for a in must_be_off:
        if i[int(a)-1] != "0":
            add = False
    
    if add == True:
        fout.write(f"{i}\n")
fout.write(f"{time.time()-start_time}seconds")
fout.close()

#print(f"{time.time()-start_time}seconds")
#*Let me not get too distracted but reference problems. Take up more time and attention. 
#*Plus I trust USACO. 
'''
Incorrectly apprearing:
00010000010000010000

Correct but not appearing:
00111000111000111000
11000111000111000111
'''
