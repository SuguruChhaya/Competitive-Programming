
#!Some weird runtime error. 
def main(arr):
    #!Honestly it is just whether I can reduce the 2 iterations into 1, maybe...
    if len(arr) <= 3:
        return len(arr)
    '''
    increment_arr = []
    for i in range(1, len(arr)):
        increment_arr.append(int(arr[i])-int(arr[i-1]))
    
    d = {}
    a = 0
    b = 1
    while b < len(increment_arr):
        if increment_arr[b] != increment_arr[b-1]:
            d[a] = (b-a, increment_arr[a])
            a = b
        b += 1
    '''
    a = 0
    b = 1
    d = {}
    increment_arr = []
    sorted_index = []
    while b<len(arr):
        increment_arr.append(int(arr[b])-int(arr[b-1]))
        if len(increment_arr) == 1:
            d[a] = [b-a, increment_arr[-1]]
            sorted_index.append(a)
        else:
            if increment_arr[-1] == increment_arr[a]:
                d[a][0] += 1
            else:
                a = b-1
                d[a] = [b-a, increment_arr[-1]]
                sorted_index.append(a)
        b +=1
    
    #!I have to make sure to deal with adding the last. 
    #d[a] = (b-a, increment_arr[a])
    
    #!Just return if the length is 1. 
    #!Just trying to micro-optimize at this point. Maybe sorting might be taking time? Maybe create an array beforehand instead of sorting them after. 

    #sorted_index = sorted(d.keys())
    if len(sorted_index) == 1:
        return len(arr)
    #return d
    m = 1
    #!I have to make clear whether i is going to be the starting index or the range counter. 
    #!Let's make it the starting index. 
    #!But will things not break if I do that???
    for i in range(len(sorted_index)):
        original_index = sorted_index[i] + d[sorted_index[i]][0] - 1
        #original_value = increment_arr[original_index]
        if original_index < len(increment_arr)-1:
            original_right_index = original_index + 1
            original_right_value = increment_arr[original_right_index]
            #*Getting this weird index out of range error.
            num_add = d[sorted_index[i]][1] - d[sorted_index[i+1]][1]
            increment_arr[original_right_index] += num_add
        if original_index < len(increment_arr)-2:
            original_two_right_index = original_right_index + 1
            original_two_right_value = increment_arr[original_two_right_index]
            increment_arr[original_two_right_index] -= num_add

        #?The last iteration was kinda sus. 
        #!Should be fine since I am going to cover it in the left side iteration. 
        '''
        if i == 5:
            print("")
        '''
        has_calculated = False
        if original_index < len(increment_arr) - 3:
            if increment_arr[original_right_index] == increment_arr[original_two_right_index] == increment_arr[original_two_right_index+1]:
                has_calculated = True
                #!Since we are considering the current element and the increment_arr is already 1 smaller, add 1
                m = max(d[sorted_index[i]][0]+2+d[original_two_right_index+1][0]+1, m)
                
        if original_index < len(increment_arr)-2 and has_calculated==False:
            if increment_arr[original_right_index] == increment_arr[original_two_right_index]:
                has_calculated = True
                m = max(d[sorted_index[i]][0]+2+1, m)

        if original_index < len(increment_arr) - 1 and has_calculated == False:
            m = max(d[sorted_index[i]][0]+1+1, m)

        
        #!By starting by lower values, as soon as I hit a mistake it will exit. 
        try:
            increment_arr[original_right_index] = original_right_value
            increment_arr[original_two_right_index] = original_two_right_value
        except Exception:
            pass

    for i in range(len(sorted_index)):
        #!Going leftwards but iteration direction doesn't change. 
        #*Since we literally start at that index. 
        original_index = sorted_index[i]
        if original_index > 0:
            original_left_index = original_index - 1
            original_left_value = increment_arr[original_left_index]
            num_add = d[sorted_index[i]][1] - d[sorted_index[i-1]][1]
            increment_arr[original_left_index] += num_add
        if original_index > 1:
            original_two_left_index = original_left_index - 1
            original_two_left_value = increment_arr[original_two_left_index]
            increment_arr[original_two_left_index] -= num_add
        
        has_calculated = False
        #!Is this approach of looking at the original index really correct? I am getting so many key errors. 
        if original_index > 2:
            if increment_arr[original_left_index] == increment_arr[original_two_left_index] == increment_arr[original_two_left_index-1]:
                #!Little complicated but I need to go back and retrieve the legnth.
                #*1 possible way I can query the starting index is by looping through sorted_index from the back and see where I encounter a value first smaller. 
                #!Is this forloop possibly creating any issues maybe? There should be a more efficient way to do this...
                #*We know that the lower one should start to the lower side of the original so start looping from there?
                for j in range(i, -1, -1):
                    #*Could be equal but may not be as well. 
                    if sorted_index[j] <= original_two_left_index - 1:
                        break
                m = max(d[sorted_index[i]][0]+2+d[sorted_index[j]][0]+1, m)
                has_calculated = True
        if original_index > 1 and has_calculated==False:
            if increment_arr[original_left_index] == increment_arr[original_two_left_index]:
                m = max(d[sorted_index[i]][0]+2+1, m)
        
        if original_index > 0 and has_calculated == False:
            m = max(d[sorted_index[i]][0]+1+1, m)

        try:
            increment_arr[original_left_index] = original_left_value
            increment_arr[original_two_left_index] = original_two_left_value
        except Exception:
            pass

    return m

'''
numTests = int(input())
for i in range(numTests):
    length = int(input())
    arr = input().strip().split(" ")
    print(f"Case #{i+1}: {main(arr)}")
'''

#*For testing purposes, I will read from the test data. 
fin = open('longestprogression/test_set_2/ts2_input.txt', "r")
fout = open('longestprogression/test_set_2/my_output.txt', 'w')
info = fin.read().strip().split("\n")
curr_line = 1
for i in range(int(info[0])):
    numElements = int(info[curr_line])
    curr_line += 1
    fout.write(f"Case #{i+1}: {main(info[curr_line].strip().split(' '))}\n")
    curr_line += 1

fout.close()
