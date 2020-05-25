N = int(input())
V = list(map(int, input().split()))
V.sort()
cur = V[0]
for i in range(1, N):
    cur = (cur + V[i]) / 2
print(cur)
