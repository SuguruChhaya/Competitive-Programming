animal_to_feature = {}
feature_to_animal = {}
n = int(input())
allAnimal = []

for i in range(n):
    inp = input().strip().split(" ")
    animal = inp[0]
    k = inp[1]
    currFeatures = []
    for j in range(k):
        