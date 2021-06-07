
#*Pretty obvious that I don't want to swap anything in a progression already. Brute force will be to simulate a swap 
#for every beneficial place and count what the length will be in that case. 

def main(arr):
    '''
    if len(arr) == 0:
        return 1
    else:
        m = 1
        temp = 1
        increment = int(arr[1]) - int(arr[0])
        i = 0
        while i < len(arr)-1:
            if int(arr[i]) + increment == int(arr[i+1]):
                temp += 1
                m = max(temp,m)
            else:
                #!The issue I have to consider here is what if the sequence continues. 
                m = max(temp+1, m)
                increment = int(arr[i+1]) - int(arr[i])  
                temp = 1
                i -= 1
                m = max(temp, m)
            i += 1

        return m
    '''

    #!Another idea in my head is to simply count from the beginning and allow upto one screw up. 
    #*Need to save the original array but what concerns me is the memory limit. 
    #*Sliding window is kind of coming to my head. 
    '''
    if len(arr) == 1:
        return 1

    m = 1
    #!I could create a brand new array and modify. 
    #*I need to create some kind of table to store pre computed data. 
    prev = (0, arr[0])
    for i in range(len(arr)-1):
        #!If I only store this, I could just just change this because this must be taking the most time. 
        #new = arr.copy()
        arr[prev[0]] = str(prev[1])
        curr = i
        temp = 1
        num_wrong = 0
        increment = int(arr[i+1]) - int(arr[i])
        while curr < len(arr)-1 and num_wrong <= 1:
            if int(arr[curr]) + int(increment) != int(arr[curr+1]):
                if num_wrong >= 1:
                    break
                #!Still changes regardless. 
                prev = (curr+1, arr[curr+1])
                arr[curr+1] = int(arr[curr]) + increment
                num_wrong += 1
                #!I probably have to immediately check because if 2 or larger, I cannot add anything. 
                    
                
            
            temp += 1
            m = max(temp, m)
            curr += 1

        #*Now check for the case that we change the original. 
        #!Make sure we get a progression of 3 or larger. 
        
        
        if i + 2 < len(arr):
            arr[prev[0]] = str(prev[1])
            prev = (i, arr[i]) #*Because this is the value I am changing. 
            increment = (int(arr[i+2]) - int(arr[i+1]))
            arr[i] = str(int(arr[i+1]) - increment)
            temp = 1
            curr = i
            while curr < len(arr)-1:
                if int(arr[curr]) + int(increment) != int(arr[curr+1]):
                    break
                    
                    if num_wrong >= 1:
                        break
                    #!Still changes regardless. 
                    prev = (curr+1, arr[curr+1])
                    arr[curr+1] = int(arr[curr]) + increment
                    num_wrong += 1
                    #!I probably have to immediately check because if 2 or larger, I cannot add anything. 
                    
                    
                
                temp += 1
                m = max(temp, m)
                curr += 1

    
    return m
    '''
    #!I kind of had this in mind but just create a table of all the increments. 

    '''
    
    if len(arr) == 1:
        return 1

    m = 1
    increment = int(arr[1]) - int(arr[0])
    i = 1
    prevChange = (0, arr[0])
    prevChanged = False

    while i < len(arr):
        if int(arr[i-1]) + increment != int(arr[i]):
            if prevChanged == False:
                prevChanged = True
                prevChange = (i, arr[i])
                arr[i] = int(arr[i-1])
                i += 1
            else:
                m = max(i-prevChange[1], m)
                prevChanged = False
                increment = int(arr[prevChange[0]+1]) - int(arr[prevChange[1]])
        else:
            i += 1
    '''
    #*Final check because might come at the end. 
    #m = max(i - prevChange[1], m)
    
    #!I honestly don't think this strat will work because there is a gap in between and incrememnt must work for everything in between as well. 
    
    #*Memory is not an issue as long as I can just copy the values in everytime I modify them. 

    #*Just logically try to block it out in blocks indicating their increments. 
    #!What data do I need to store?
    #*Maybe create an entire new array with all info?

    #?Another case I have to consider is when I have to change the first number (for e.g. 4555)
    '''
    for i in range(len(arr)):
        pass
    '''
            

numTests = int(input())
for i in range(numTests):
    length = int(input())
    arr = input().strip().split(" ")
    print(f"Case #{i+1}: {main(arr)}")