'''
LANG: PYTHON3
TASK: barn1
'''
fin = open("barn1.in", "r")
fout = open("barn1.out", "w")
info = fin.read().strip().split("\n")
first_line = info[0].strip().split(" ")
max_use = int(first_line[0])
contain_cow = int(first_line[2])

occupied = []
for i in range(contain_cow):
    occupied.append(int(info[i+1]))

occupied.sort()

result = occupied[-1] - occupied[0] + 1
used = 1

gaps = []
for i in range(1, len(occupied)):
    gaps.append(occupied[i] - occupied[i-1]-1)
i = len(gaps)-1
gaps.sort()

while used < max_use and result > contain_cow:
    result -= gaps[i]
    i -= 1
    used += 1

fout.write(f"{result}\n")
