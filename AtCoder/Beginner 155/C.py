N = int(input())

occ = {}

for i in range(N):
    s = input()
    occ[s] = occ.get(s, 0) + 1

best = 0
for s in occ: best = max(best, occ[s])

res = []
for s in occ:
    if occ[s] == best: 
        res.append(s)

res.sort()

for i in res:
    print(i)