N = int(input())
dh = [[] for i in range(N)]
du = [[] for i in range(N)]
for i in range(N):
    t = int(input())
    for j in range(t):
        x, y = map(int, input().split())
        if y == 1: dh[i].append(x-1)
        else: du[i].append(x-1)

best = 0
def check(bitmask):
    global best
    isH = [False for i in range(N)]
    isU = [False for i in range(N)]
    
    for i in range(N):
        if bitmask % 2:
            isH[i] = True
        else:
            isU[i] = True
        bitmask //= 2
    
    valid = True
    for i in range(N):
        if isU[i]: continue
        for t in dh[i]:
            if isU[t]: valid = False
        for t in du[i]:
            if isH[t]: valid = False

    if valid: best = max(best, sum(isH))

for i in range(pow(2, N)): check(i)

print(best)
