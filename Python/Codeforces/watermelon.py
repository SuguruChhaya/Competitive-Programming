
#*Super easy. 
a = int(input())
#*Not that evens work all the time. 
#*Easiest way is to just loop until that number and see if any pair is even. 
#*Isn't there an easier way to solve this tho?
'''
printed = False
for i in range(1, a):
    if i % 2 == 0 and (a-i) % 2 == 0:
        print("YES")
        printed = True
        break
if printed == False:
    print("NO")
'''

#*Only exception is 2. 
if a != 2 and a % 2 == 0:
	print("YES")
else:
	print("NO")