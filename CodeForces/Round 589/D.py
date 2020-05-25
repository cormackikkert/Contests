N, M = map(int, input().split())

neighbours = [[] for i in range(N)]

for i in range(M):
    a, b = map(lambda x:int(x)-1, input().split())
    neighbours[a].append(b)
    neighbours[b].append(a)

failed = False
poss = [[True, True, True] for i in range(N)]

for i in range(N):

    if poss[i][0] and all(poss[n][1] or poss[n][2] for n in neighbours[i]):
        poss[i][1] = False
        poss[i][2] = False
        col = 0

    elif poss[i][1] and all(poss[n][0] or poss[n][2] for n in neighbours[i]):
        poss[i][2] = False
        col = 1
        
    elif poss[i][2] and all(poss[n][0] or poss[n][1] for n in neighbours[i]):
        col = 2

    else:
        failed = True
        print(-1)
        break

    for n in neighbours[i]:
        poss[n][col] = False

def getT(d):
    if d[0]: return 1
    if d[1]: return 2
    if d[2]: return 3
    
if not failed:
    print(" ".join(map(str,[getT(pos) for pos in poss])))
