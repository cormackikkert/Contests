N, K = map(int, input().split())
ps = list(map(int, input().split()))

cursum = sum(ps[:K])
l = 0
h = K
i = 0
best = cursum
while h != N:
    cursum += ps[h] - ps[l]
    h += 1
    l += 1
    if (cursum > best):
        best = cursum
        i = l

ans = 0
for j in range(K):
    ans += (ps[i+j] + 1) / 2 
print(ans)
