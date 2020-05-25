n,m = [int(x) for x in input().split()]

p = [0 for _ in range(n)]
q = [0 for _ in range(m)]

for j in range(6):
    s = input()
    for i in range(n):
        if s[i] == '1':
            p[i] |= (1 << j)

for j in range(6):
    s = input()
    for i in range(m):
        if s[i] == '1':
            q[i] |= (1 << j)

v = [[] for _ in range(1 << 6)]

for i in range(n-1,-1,-1):
    v[p[i]].append(i+1)

ans = [-1 for _ in range(m)]
idx = [0 for _ in range(1 << 6)]

for i in range(m):
    best_j, best = -1, -1
    for j in range(1 << 6):
        if(q[i] & j) == q[i] and idx[j] != len(v[j]):
            if best_j == -1 or best < v[j][idx[j]]:
                best_j, best = j, v[j][idx[j]]
    ans[i] = best
    if best_j != -1:
        idx[best_j] += 1

print(" ".join(str(x) for x in ans))
