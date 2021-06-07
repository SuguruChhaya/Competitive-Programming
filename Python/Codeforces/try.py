from queue import PriorityQueue

a = PriorityQueue()
#*Smaller value gets chosen
a.put(5)
a.put(3)
print(a.get())