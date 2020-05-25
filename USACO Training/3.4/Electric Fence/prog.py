"""
ID: cormac.1
LANG: PYTHON3
TASK: fence9
"""

with open("fence9.in") as file:
    N, M, P = map(int, file.readline().split())

def getNum(A, B, rev=False):
    if A == 0:
        return 0
    m = B / A
    total = 0
    for i in range(A):
        if not rev and abs((m * i)- int(m * i + 0.5)) < 1e-7:
            total += max(0, int(m * i) - 1)
        else:
            total += max(0, int(m * i + (1e-4 if rev else 0)))
    return total

if P >= N:
    cost = getNum(N, M) + getNum(P - N, M)
    if N != P and N != 0:
        cost += max(M - 1, 0)
else:
    cost = getNum(N, M) - getNum(N - P, M, rev=True)
    
with open("fence9.out", "w") as file:
    file.write(str(cost) + "\n")
