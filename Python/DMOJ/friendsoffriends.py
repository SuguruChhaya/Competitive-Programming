
#*Use a dictionary to indicate all the friends. 

n, q = input().strip().split(" ")
n, q = int(n), int(q)
d = {}

#*I cannot just keep recursively going through friends because mutual friends mean never stop. 
#*Have to store in dictionary or freq array. 
#*Another approach may be, if current a certain person were to be called how many ppl. 
#!But no need to store that info separately since I need to store names so just get length and stuff. 

#!Really like a graph structure but taking too much time. 
#!Like will I even get correct answer with this thing?
#*I don't want them to just go so in-depth because we aren't spreading out possibility but rather collect all I could collect. 
def recursive(curr, person, hashset):
    if person not in hashset:
        curr[0] += 1
        hashset.add(person)
        for friend in d[person]:
            temp = hashset.copy()
            #temp.add(friend)
            # #!I don't think I really should be adding at this point. 
            recursive(curr, friend, temp)
    
for i in range(q):
    arr = input().strip().split(" ")
    if arr[0] == "1":
        if arr[1] not in d:
            d[arr[1]] = []
        if arr[2] not in d:
            d[arr[2]] = []

        d[arr[1]].append(arr[2])
        d[arr[2]].append(arr[1])
    else:
        if arr[1] not in d:
            #*I could try recursion but might be heavy on memory. A good method might be to store all the friends so I don't have to do recursion. 
            #heard = 1
            d[arr[1]] = []
        temp = [0]
        a = set()
        #a.add(arr[1])
        recursive(temp, arr[1], a)
        print(temp[0])
    

        
        #recursive([1], arr[1])

'''
n, q = input().strip().split(" ")
n, q = int(n), int(q)
d = {}

for i in range(q):
    arr = input().strip().split(" ")
    if arr[0] == "1":
        if arr[1] not in d:
            d[arr[1]] = []
        if arr[2] not in d:
            d[arr[2]] = []
        
        #*Now add into arr. 
        #!We cannot just keep updating because we don't really know which one is connected to which. 
        #!Honestly might be better giving it a shot with recursion maybe using a set or something to keep track of what I already visited. 
        temp_1_add = d[arr[1]].copy()
        temp_2_add = d[arr[2]].copy()
        d[arr[1]] += [arr[2]] + temp_2_add
        d[arr[2]] += [arr[1]] + temp_1_add
        
        d[arr[2]].append(arr[1])
        d[arr[2]] += d[arr[1]]
        d[arr[1]].append(arr[0])
        #*Need to make sure I don't add duplicates. 
        d[arr[1]] += d[arr[0]]
        

    else:
        print(1 + len(d[arr[1]]))
'''
