N = int(input())
a = 0
b = 0
for i in range(1, N+1):
    b += 1
    if i % 2 == 1: a+=1

print(a/b)
