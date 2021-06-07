
#*Doesn't order matter (compare the number of x and os and based on that. )
#!Kind of hard to understand the question but I think 1 happens if there is even a slight possibility that a player may win. 
#!Never mind, I just need to read the board and make a decision. 
#!No simulation and stuff. 
#*Just check all rows and diagonals and see who won. 
#*1. One won or draw. 
#*2. None has won yet (and there are still moves to be made)
#*3. Just impossible to reach (both won). One more example I can think of is when there is discrepancy in numbers. Number of x must be equal or larger by 1. 

def main(arr):
    #*Check the first row. 
    x_won = False
    o_won = False

    #*First check whether there are number discrepancy. 
    num_x = 0
    num_o = 0
    empty_exists = False
    for i in range(3):
        for j in range(3):
            if arr[i][j] == "X":
                num_x += 1
            elif arr[i][j] == "O":
                num_o += 1
            else:
                empty_exists = True
    
    if 0 <= num_x - num_o <= 1:      
        #!A person could win both a row and diagonal. A person cannot win 2 rows but that case is covered in the difference if-statement. 
        #empty_exists = False
        if arr[0][0] == arr[0][1] == arr[0][2]:
            if arr[0][0] == "X":
                x_won = True
            elif arr[0][0] == "O":
                o_won = True
            #!This whole idea of empty_exists is not registered here since checking whether empty exists shouldn't depend on whether there is correct or not. 
            
            else:
                empty_exists = True
        
        if arr[1][0] == arr[1][1] == arr[1][2]:
            if arr[1][0] == "X":
                x_won = True
            elif arr[1][0] == "O":
                o_won = True
            else:
                empty_exists = True

        if arr[2][0] == arr[2][1] == arr[2][2]:
            if arr[2][0] == "X":
                x_won = True
            elif arr[2][0] == "O":
                o_won = True
            else:
                empty_exists = True

        if arr[0][0] == arr[1][0] == arr[2][0]:
            if arr[0][0] == "X":
                x_won = True
            elif arr[0][0] == "O":
                o_won = True
            else:
                empty_exists = True

        if arr[0][1] == arr[1][1] == arr[2][1]:
            if arr[0][1] == "X":
                x_won = True
            elif arr[0][1] == "O":
                o_won = True
            else:
                empty_exists = True
        
        if arr[0][2] == arr[1][2] == arr[2][2]:
            if arr[0][2] == "X":
                x_won = True
            elif arr[0][2] == "O":
                o_won = True
            else:
                empty_exists = True

        if arr[0][0] == arr[1][1] == arr[2][2]:
            if arr[0][0] == "X":
                x_won = True
            elif arr[0][0] == "O":
                o_won = True
            else:
                empty_exists = True

        if arr[0][2] == arr[1][1] == arr[2][0]:
            if arr[0][2] == "X":
                x_won = True
            elif arr[0][2] == "O":
                o_won = True
            else:
                empty_exists = True
        
        #!Weird bugs that are destroying my program and wasting my time. 
        if x_won == True and o_won == True:
            return 3
            #!have to check whether there are no empty spaces. 
            #!An empty space doesn't exist isn't a correct condition. 
        elif (x_won or o_won) or empty_exists == False:
            return 1
        else:
            return 2


    #!No idea why this isn't passing. 
    return 3

#*Wrong answer right away so I must be missing some very basic thing. 
numTests = int(input())
for i in range(numTests):
    arr = []
    for j in range(3):
        temp = input().strip()
        temp_arr = []
        for char in temp:
            temp_arr.append(char)
        arr.append(temp_arr)
    print(f"{main(arr)}")