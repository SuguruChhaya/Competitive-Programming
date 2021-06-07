'''
LANG: PYTHON3
TASK: test
''' 
#!The online grading system isn't there for every single problem so I have to specify.
#*Don't really have to specify name because of my account info. 
#*I just need the LANG and TASK for USACO training submissions. 
import sys
fin = open ('test.in', 'r')
fout = open ('test.out', 'w')
x,y = map(int, fin.readline().split())
sum = x+y
#sys.stderr.write('message')
sys.stdout.write("hello")
#*Both can be used for debugging here. 
fout.write (str(sum) + '\n')

fout.close()

#*Also mentions how sys.stderr.write('message') helps debug, at least in the training version and stdout. 