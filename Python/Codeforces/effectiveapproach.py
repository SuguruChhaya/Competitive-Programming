
#*div 2b questions may be a little challenging but probably still manageable. 
#*Big part of this is creating permutations and probably manually. 
#*Permutations are pre-generated. 

numElements = int(input())
elements = input().strip().split(" ")
numQueries = int(input())
queries = input().strip().split(" ")

vasya = 0
petya = 0
'''
#*Kind of naive solution because time complexity is O(numElements * numQueries)
for i in range(numElements):
    for j in queries:
        if j == elements[i]:
            vasya += i + 1
            petya += numElements - i
    
print(f"{vasya} {petya}")
'''

#*Can use hashmap to store index and value. 
#*There may be duplicates in the query but not in original
#*To save memory, I could have also used a frequency array. 
arr = [0] * numElements
for i in range(numElements):
    arr[int(elements[i]) - 1] = i

for j in queries:
    vasya += arr[int(j)-1] + 1
    petya += numElements - arr[int(j)-1]

print(f"{vasya} {petya}")