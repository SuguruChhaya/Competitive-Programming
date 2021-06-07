
numTests = int(input())
curr_x = 0
curr_y = 0
curr_z = 0
#*Maybe it should be the individual x,y,z values that must be -
for i in range(numTests):
    x, y, z = input().strip().split(" ")
    x, y, z = int(x), int(y), int(z)
    curr_x += x
    curr_y += y
    curr_z += z

if curr_x == 0 and curr_y==0 and curr_z==0:
    print("YES")
else:
    print("NO")