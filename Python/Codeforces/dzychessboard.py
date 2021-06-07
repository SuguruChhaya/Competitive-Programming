numRows, numCols = input().strip().split(" ")
numRows, numCols = int(numRows), int(numCols)
board = []
for i in range(numRows):
    #"." means good and "-" means bad. 
    #*Doesn't really matter is I put a while one or not because interchangeable. 
    temp = []
    a = input()
    for j in a:
        temp.append(j)
        #*Have to be careful about index errors here. 
    board.append(temp)
'''
print(board)

for i in range(numRows):
    for j in range(numCols):   
        if board[i][j] == ".": 
            if (i-1 >= 0 and board[i-1][j] == "W") or (i+1 < numRows and board[i+1][j] == "W") or (j-1 >= 0 and board[i][j-1]== "W") or (j+1 < numCols and board[i][j+1]=="W"):
                board[i][j] = "B"
            #elif (i-1 >= 0 and board[i-1][j] == "B") or (i+1 < numRows and board[i+1][j] == "B") or (j-1 >= 0 and board[i][j-1]== "B") or (j+1 < numCols and board[i][j+1]=="B"):
            #*I pretty much created a scenario where no choice was really valid.
            #*How do I make sure my next choice is going to be valid or not?
            else:
                board[i][j] = "W"

#*How do I prevent side by side . collisions?
#*It sometimes becomes impossible. 
#*I have to consider the spaces in between. If there are like "B..B" I really have no choice. 
#*But 
for i in board:
    print("".join(i))

#DZY loves chessboard
#*All I really have to do is input it in a template and remove all non filled. This way I won't run into any errors.
'''
alternate_arr = ["W", "B"]
counter = 0

#*Creating a board is way more complicated than just boards. 
#*Based on the previous or top (except the first one), we can pick "W" pr "B"
#*But since we are just building a template...
model = []
for i in range(numRows):
    temp = []
    for j in range(numCols):
        if i==0 and j == 0:
            temp.append("W")
        elif j-1 >= 0:
            if temp[-1] == "W":
                temp.append("B")
            else:
                temp.append("W")
        elif i-1>=0:
            if model[i-1][j] == "W":
                temp.append("B")
            else:
                temp.append("W")
    model.append(temp)

for i in range(numRows):
    for j in range(numCols):
        if board[i][j] == ".":
            board[i][j] = model[i][j]

for i in board:
    print("".join(i))