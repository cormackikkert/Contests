N, M = map(int, input().split())
AC = [0 for i in range(N)]
WA = [0 for i in range(N)]
for i in range(M):
    p, v = input().split()
    p = int(p) - 1
    if v == "WA" and AC[p] == 0:
        WA[p] += 1
    elif v == "AC":
        AC[p] = 1

C = sum(AC)
F = 0
for i in range(N):
    if AC[i]: F += WA[i]
print(C, F)