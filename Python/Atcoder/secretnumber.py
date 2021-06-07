
#*I need to do a lot of combination matching in this one. 

def recursive1(curr, length, available, arr):
    if len(curr) == length:
        arr.append(curr)
    else:
        for i in available:
            temp_str = curr + str(i)
            recursive1(temp_str, length, available, arr)

#!Not getting the correct number... 
def recursive2(curr, length, used, could, arr):
    #*curr is going to be a string and will be added to. 
    if len(curr) == length:
        arr.append(curr)
    else:
        for i in could:
            if i not in used:
                temp_str = curr + str(i)
                temp_set = used.copy()
                temp_set.add(i)
                recursive2(temp_str, length, temp_set, could, arr)

def recursive3(curr, length, must, must_could, arr):
    if len(curr) == length:
        add = True
        for i in must:
            if str(i) not in curr:
                add = False
        if add == True:
            arr.append(curr)
    
    else:
        for i in must_could:
            temp_str = curr + str(i)
            recursive3(temp_str, length, must, must_could, arr)

def main(s):
    needed = set()
    could = set()
    #could = {1, 2, 3, 4}
    
    for i in range(len(s)):
        if s[i] == "o":
            needed.add(i)
        elif s[i] == "?":
            could.add(i)
    
    #*Could use something like a queue?
    result = 0
    queue = [""]

    #!Similar problem where I did recursive but it didn't work out...
    while len(queue) != 0:  
        curr = queue.pop()
        if len(curr) == 4:
            add = True
            for i in needed:
                if str(i) not in curr:
                    add = False
            if add == True:
                result += 1
        else:
            for i in needed:
                queue.append(curr + str(i))
            for i in could:
                queue.append(curr + str(i)) 

    return result

    '''
    #*Should I just make the combinations here??
    #return recursive1("", 4, needed, could)
    #will_use = needed.copy()
    #!The hard part is that here, the length can be whatever. It is just that they should add up to 4. 
    #*I guess I should just build all of them in one recursive function. 
    arr = []
    #recursive2("", 4 - len(needed), set(), could, arr)
    
    #*Now loop through all the examples and and create 4 letter and check all permutations. 
    #!Use a big array for now but if space problems arise I can do something. 
    possible = set()
    for i in needed:
        possible.add(i)
    for j in could:
        possible.add(j)

    recursive3("", 4, needed, possible, arr)
    return len(arr)
    '''
    '''
    result_arr = []
    for i in arr:
        temp = will_use.copy()
        for j in i:
            temp.add(j)
        recursive2("", 4, set(), temp, result_arr)
    #!I see! I could use them multiple times!! Might have to make modifications with the used in the recursion. 
    #!Then I will have to make an entire new permutation out of the possibilities or no?
    #*May be easier to do it since I am checking by length. 
    #*Tricky thing about the must use arr is that all have to be in there but numbers can repeat. 
    #*This means just becuase there are 2 os and no coulds, I can just repeat the os. 
    return len(result_arr)
    '''




s = input()
print(main(s))