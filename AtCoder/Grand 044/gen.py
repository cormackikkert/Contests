import random
print(500)
arr = [i + 1 for i in range(500*500)]
random.shuffle(arr)
print(*arr)