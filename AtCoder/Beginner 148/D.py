N = int(input())
seq = list(map(int, input().split()))
best = float('inf')
if 1 in seq:
    best = N - 1
else:
    print(-1)
    quit()

cur = 1
todel = 0
for i in range(N):
    if seq[i] == cur:
        cur += 1
    else:
        todel += 1
best = min(best, todel)

print(best)
