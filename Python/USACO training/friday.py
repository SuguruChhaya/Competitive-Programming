'''
LANG: PYTHON3
TASK: friday
'''

fin = open("friday.in", "r")
fout = open("friday.out", "w")
span = int(fin.read())

dates_per_month = [0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
result = [0] * 7
curr_year = 1900
curr_month = 1
curr_date = 1
curr_day_index = 0
#!Currently at a monday so I have to reorder that.
#*But anyways containing the wrong numbers. 
#*I didn't consider century years. 


while curr_year < 1900 + span:
    #!I think I had to put this on top if I wanted to correctly consider 1900. other than that everything would have worked!
    if curr_year % 100 == 0:
        if curr_year % 400 == 0:
            dates_per_month[2] = 29
        else:
            dates_per_month[2] = 28
    else:
        if curr_year % 4 == 0:
            dates_per_month[2] = 29
        else:
            dates_per_month[2] = 28
    if curr_date == 13:
        result[curr_day_index] += 1
    curr_date += 1
    curr_day_index += 1
    if curr_date >dates_per_month[curr_month]:
        curr_date = 1
        curr_month += 1
    if curr_month == 13:
        curr_month = 1
        curr_year += 1
        #?Honestly curious why it changed here. 

    if curr_day_index == 7:
        curr_day_index = 0

resultstr = ""
i = 5
while i != 4:
    resultstr += str(result[i]) + " "
    i+=1
    if i == 7:
        i = 0

resultstr += str(result[i]) + "\n"
    


fout.write(resultstr)