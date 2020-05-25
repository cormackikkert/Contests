a1 = int(input())
a2 = int(input())
k1 = int(input())
k2 = int(input())
N = int(input())

if a1 * (k1 - 1) + a2 * (k2 - 1) >= N:
    minNum = 0
else:
    minNum = min(a1 + a2, N - (a1 * (k1 - 1) + a2 * (k2 - 1)))

occ = [k1 for i in range(a1)] + [k2 for i in range(a2)]
occ.sort()

n = N
i = 0
maxNum = 0

for n in range(N):
    occ[i] -= 1
    if occ[i] == 0:
        maxNum += 1
        i += 1

print(minNum, maxNum)

