'''
LANG: PYTHON3
TASK: gift1
'''
fin = open ('gift1.in', 'r')
fout = open ('gift1.out', 'w')
info = fin.read().strip().split("\n")
#*Store all info in a dictionary and create key based on name (that's why probably unique)
numPeople = int(info[0])
d = {}
currRow = 1
for i in range(numPeople):
    #*First item stores money amount 
    #!I have to be saving the total amount of money because I cannot mix giving money and receiving money. 
    #*0th index: total money (result) (int)
    #*1st index: amount giving.  (int)
    #*2nd index: number of ppl giving (int)
    #*3rd index: people giving (list)
    d[info[currRow]] = [0, 0, 0, []]
    currRow += 1

#*Since everyone's name is mentioned, I think I can check using loop. 
for i in range(numPeople):
    person = info[currRow]
    currRow += 1
    amountGiving, numPeopleGiving = info[currRow].split(" ")
    amountGiving, numPeopleGiving = int(amountGiving), int(numPeopleGiving)
    #!The current amount should be the negative of the amount giving. 
    d[person][0] = -amountGiving
    d[person][1] = amountGiving
    d[person][2] = numPeopleGiving
    currRow += 1
    for j in range(numPeopleGiving):
        d[person][3].append(info[currRow])
        currRow += 1

for person in d.keys():
    if d[person][2] == 0:
        perPerson = 0
    else:
        perPerson = d[person][1] // d[person][2]
        d[person][0] += d[person][1] % d[person][2]
    for givingperson in d[person][3]:
        d[givingperson][0] += perPerson

for person in d.keys():
    fout.write(f"{person} {d[person][0]}\n")