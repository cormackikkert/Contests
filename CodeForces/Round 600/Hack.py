print(pow(10, 5))
N = pow(10, 5) // 4
a = list(range(1, N+1))
a = a + [-x for x in a]
for i in range(N):
    a.append(1)
    a.append(-1)
print(*a)
    
