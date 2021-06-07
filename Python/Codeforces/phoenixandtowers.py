from queue import PriorityQueue
def main(n, m, x, arr):
    #!Whenever I pick one item, the item should either stay in the first tower or moved to all the other towers. 
    #!But for this solution, I cannot know in the middle whether the gap is gonna be something. Just gotta keep building it.  
    #!I might be able to eliminate duplicates but time and space will probably still exceed. 
    #*1st is gonna be array of len(m)
    default = [0] * m
    default[0] = sum(arr)
    #*2nd is gonna be the index I am dealing with. 
    default_position = [1] * n
    #!By default, all the blocks are going to the first tower. 
    queue = [(default, 0, default_position)]

    
    while len(queue) != 0:
        curr = queue.pop(0)

        if curr[1] == len(arr):
            #*Means we have finished making all the decisions. 
            #!To check for difference, just find the max and min and check if valid. 
            #*I also need to know which tower went into where. 
            mini, maxi = min(curr[0]), max(curr[0])
            if maxi - mini <= x:
                result = ""
                for i in range(len(curr[2])):
                    result += str(curr[2][i]) + " "
                return "YES\n" + result[:len(result)-1]
        else:
            #*Howmany ever options so forloop. 
            for i in range(len(curr[0])):
                temp = curr[0].copy()
                temp[i] += arr[curr[1]]
                temp[0] -= arr[curr[1]]
                '''
                if i == 0:
                    temp[i] -= arr[curr[1]]
                '''
                #*Need to modify position too. 
                temp_position = curr[2].copy()
                temp_position[curr[1]] = i+1
                queue.append((temp, curr[1]+1, temp_position))
    return "Suguru is gay"

def main(n, m, x, arr):
    #!Always think it is fricking BFS while in reality it isn't since all the n blocks don't exceed value. 
    #*I think BFS is such a pleasant algo that I just tend to run to it but usually there is a better logical way to solve it. 
    curr_order = []
    queue = PriorityQueue()
    for i in range(m):
        #curr_order.append([0, i+1])
        queue.put([0, i+1])
    #curr_order.sort()
    curr_index = 0
    result_arr = []
    #!Don't necessarily have to do .sort() since all I have to do is to place the modified node. 
    #!Now I get a wrong answer so I must have screwed up something. 
    while curr_index < len(arr):
        curr = queue.get()
        result_arr.append(str(curr[1]))
        curr[0] += arr[curr_index]
        curr_index += 1
        #*Adjust position. 
        queue.put(curr)
        #!Is it some mutability issue or what?
        #!I have to break after completing. 
        #*I could improve this by doing binary search and finding the correct index to insert but is that the issue?
        '''
        #*To prevent complicated edge cases, first check whether larger than extremes. 
        if curr_order[-1][0] <= curr[0]:
            curr_order.append(curr)
        else:
            low = 0
            high = len(curr_order) - 1
            while low <= high:
                mid = (low+high) // 2
                #*Condition could be mid is smaller but mid+1 is larger. This way, index 0 will work just fine. 
                if curr_order[mid][0] <= curr[0] and curr[mid+1][0] > curr[0]:
                    curr_order.insert(mid+1, curr)
        '''

        #!The whole insert operation might be runing the runtime. Instead just shift the elements as I go so one pass. 
        '''
        for i in range(1, len(curr_order)):
            if curr_order[i][0] > curr[0]:
                curr_order.insert(i, curr)
                placed = True
                break
        '''

        #!Maybe use the python priority queue data structure since less time and easy insertion. 
        '''
        i = 1
        while i < len(curr_order) and curr_order[i][0] <= curr[0]:
            curr_order[i-1] = curr_order[i]
            i += 1
        
        curr_order[i-1] = curr
        '''
        
            
        
    
    return f"YES\n{' '.join(result_arr)}"

numTests = int(input())
for i in range(numTests):
    n, m, x = input().strip().split(' ')
    n, m, x = int(n), int(m), int(x)
    arr = input().strip().split(" ")
    for j in range(len(arr)):
        arr[j] = int(arr[j])
    print(main(n, m, x, arr))