N = int(input())
s = 0
for i in range(1, N+1):
    if i % 3 == 0: continue
    if i % 5 == 0: continue
    s += i
print(s)