import itertools
N = 9
best = 0
bestP = []
oldPerm = [i for i in range(N)]
for perm in itertools.permutations(oldPerm):
    total = 0
    for i in range(N):
        total += abs(perm.index(i) - oldPerm.index(i))
    if total > best:
        bestP = perm
        best = total
print(bestP)