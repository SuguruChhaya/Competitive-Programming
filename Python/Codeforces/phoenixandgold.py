
#*I guess I can use BFS and weed out ones that hit x. 
'''
def recursive(curr_arr, curr_total, index, arr, x, sum_arr):
    #!Not adding is not an option because we have to add all to get there. It is just the order I add it. 
    if curr_total == sum_arr:
        return curr_arr
    elif index >= len(arr) or curr_total == x:
        return None
    else:
        temp1 = curr_arr
        temp2 = curr_arr
        #!Maybe I should just deal with it after returning 
        #*One return of a recursive call should exit the whole thing but if I am just calling, it wouldn't do that. 
        add_curr = recursive(temp1+[arr[index]], curr_total+arr[index], index+1, arr, x, sum_arr)
        move_next = recursive(temp2, curr_total, index+1, arr, x, sum_arr)

        if add_curr != None:
            return add_curr
        elif move_next != None:
            return move_next
'''

'''
if add_curr != None:
    for i in range(len(add_curr)):
        add_curr[i] = str(add_curr[i])
    return f"YES\n{' '.join(add_curr)}"
elif move_next != None:
    for i in range(len(move_next)):
        move_next[i] = str(move_next[i])
    return f"YES\n{' '.join(move_next)}"
else:
    return "NO"
'''
    
    #!How should I call these methods? What if I don't return anything?

#*Keep a set of all the numbers already added. 
def recursive(curr_arr, curr_total, already_added, arr, x, sum_arr):
    if curr_total == sum_arr:
        return curr_arr
    elif curr_total == x:
        return None
    else:
        #!How am I gonna store all the recursive calls though?
        for i in range(len(arr)):
            if arr[i] not in already_added:
                temp_set = already_added
                temp_set.add(arr[i])
                temp_arr = curr_arr
                call = recursive(temp_arr+[arr[i]], curr_total+arr[i], temp_set, arr, x, sum_arr)
                if call != None:
                    return call


def main(n, x, arr):
    #*(curr_total, remaining_elements)
    #!But the memory limit is gonna destroy me. 
    #*I don't think I have to BFS but rather do a greedy. 
    #!At each step, I have 2 options. 
    #*Either to add that number or move on to the next number. 
    #*Maybe try recursion and see if it works. 
    #*curr_arr, curr_total, index, arr
    #a = recursive([], 0, set(), arr, x, sum(arr))
    #!There should be some way to improve this. 
    #!I essentially just have to cross that x limit then I can just choose randomly after that. 
    sum_arr = sum(arr)
    #!Recursion could be really complicated. 
    queue = [([], 0, set())]
    
    #!Rather than an array lookup, much better to do set. But order matters so I can create separate set for values to lookup. 
    while len(queue) != 0:
        curr = queue.pop(0)
        #!First have to check for explosion. 
        if curr[1] == x:
            pass

        elif curr[1] > x:
            result = curr[0]
            hashset = curr[2]
            for i in range(len(arr)):
                if arr[i] not in hashset:
                    result.append(arr[i])
            
            for i in range(len(result)):
                result[i] = str(result[i])
            return f"YES\n{' '.join(result)}"
        else:
            for i in range(len(arr)):
                
                if arr[i] not in curr[2]:
                    #!Hashset mutability issues?
                    temp = curr[0].copy()
                    temp.append(arr[i])
                    temp_set = curr[2].copy()
                    temp_set.add(arr[i])
                    queue.append((temp, curr[1]+arr[i], temp_set))
    return "NO"
                    
    '''
    elif curr[1] == sum_arr:
        #*Wanna straight up return.
        result = curr[0]
        for i in range(len(result)):
            result[i] = str(result[i])
        return f"YES\n{' '.join(result)}"
    '''

    '''
    if a != None:
        for i in range(len(a)):
            a[i] = str(a[i])
        return f"YES\n{' '.join(a)}"
    return "NO"
    '''


#I just overthought it. 
#I mean if every number is distict obviously the only case not possible is if equal

def main(n, x, arr):
    sum_arr = sum(arr)
    if sum_arr == x:
        return "NO"
    else:
        temp_sum = 0
        temp_arr = []
        used = set()
        while temp_sum != sum_arr:
            if arr[0] not in used and temp_sum + arr[0] != x:
                curr = arr.pop(0)
                temp_arr.append(str(curr))
                temp_sum += curr
            else:
                curr = arr.pop(1)
                temp_arr.append(str(curr))
                temp_sum += curr
        return f"YES\n{' '.join(temp_arr)}"

numTests = int(input())
for j in range(numTests):
    n, x = input().strip().split(" ")
    n, x = int(n), int(x)
    arr = input().strip().split(" ")
    for i in range(len(arr)):
        arr[i] = int(arr[i])
    print(main(n, x, arr))
