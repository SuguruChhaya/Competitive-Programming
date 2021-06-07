'''
LANG: PYTHON3
PROG: ride
'''

fin = open ('ride.in', 'r')
fout = open ('ride.out', 'w')
comet, group = (fin.read().strip().split("\n"))
comet_total = 1
group_total = 1
for i in comet:
    comet_total *= ord(i) % 65 +1
for j in group:
    group_total *= ord(j) % 65 +1

if group_total % 47 == comet_total % 47:
    #!This is what it means by end in a newline!!
    fout.write("GO\n")
else:
    fout.write("STAY\n")
fout.close()

'''

  > Run 1: Execution error: Your program did not produce an answer
        that was judged as correct. The program stopped at 0.024 seconds;
        it used 9020 KB of memory. Your answer length was 2; the correct
        length is 3. 

        Here are the respective outputs:
        ----- our output ---------
        GO
        ---- your output ---------
        GO
        --------------------------

        Note that your output did not end in a newline!  This is an error and
        must be repaired.

        ------ Data for Run 1 [length=14 bytes] ------
        COMETQ 
        HVNGAT 
'''