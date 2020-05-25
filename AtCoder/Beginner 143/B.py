N = int(input())
D = list(map(int, input().split()))

t = 0
for i in range(N):
    for j in range(i+1, N):
        t += D[i] * D[j]

print(t)
