'''
LANG: PYTHON3
TASK: milk
'''

fin = open("milk.in", "r")
fout = open("milk.out", "w")
info = fin.read().strip().split("\n")

first_line = info[0].strip().split(" ")
target = int(first_line[0])
num_farmers = int(first_line[1])

arr = []
for i in range(num_farmers):
    line = info[i+1].strip().split(" ")
    arr.append([int(line[0]), int(line[1])])

arr.sort()
curr_milk = 0
price = 0
i = 0

while curr_milk < target:
    amount = min(target-curr_milk, arr[i][1])
    price += arr[i][0] * amount
    curr_milk += amount
    i += 1

fout.write(f"{price}\n")

