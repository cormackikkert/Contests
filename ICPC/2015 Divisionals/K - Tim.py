umbrellaN,k,ballX,ballY = map(int,input().split())

edges = {i:{} for i in range(umbrellaN)}
umbrellas = [list(map(int,input().split())) for _ in range(umbrellaN)]

carEdges = {}
ballEdges = {}

for i in range(umbrellaN):
    for j in range(i+1,umbrellaN):
        dist = max(0,((umbrellas[i][0]-umbrellas[j][0])**2+(umbrellas[i][1]-umbrellas[j][1])**2)**.5-umbrellas[i][2]-umbrellas[j][2])
        if dist <= k:
            edges[i][j] = dist
            edges[j][i] = dist
    dist = max(0,(umbrellas[i][0]**2+umbrellas[i][1]**2)**.5-umbrellas[i][2])
    if dist <= k:
        carEdges[i] = dist
    dist = max(0,((umbrellas[i][0]-ballX)**2+(umbrellas[i][1]-ballY)**2)**.5-umbrellas[i][2])
    if 2*dist <= k:
        ballEdges[i] = dist

initSeen = [False]*umbrellaN

memo = {}
def f(umb, direc, seen):
    if (umb,direc) in memo:
        return memo[(umb,direc)]
    best = -1
    newSeen = list(seen)
    newSeen[umb] = True
    for dest in edges[umb]:
        if not seen[dest]:
            val = edges[umb][dest] + f(dest, direc, newSeen)
            if best == -1 or val < best:
                best = val
    if direc == 1 and umb in carEdges:
        if best == -1:
            best = carEdges[umb]
        else:
            best = min(best,carEdges[umb])
    elif direc == 0 and umb in ballEdges:
        best2 = -1
        for dest in ballEdges:
            if not seen[dest] and ballEdges[dest] <= k-ballEdges[umb]:
                val = ballEdges[umb] + ballEdges[dest] + f(dest, 1, initSeen)
                if best2 == -1 or val < best2:
                    best2 = val
        if best == -1:
            best = best2
        elif best2 != -1:
            best = min(best,best2)
    memo[(umb,direc)] = best
    return best

best = -1
for start in carEdges:
    val = carEdges[start] + f(start, 0, initSeen)
    if best == -1 or val < best:
        best = val

dist = (ballX**2+ballY**2)**.5
if 2*dist <= k:
    if best == -1:
        print(2*dist)
    else:
        print(min(best,2*dist))
else:
    print(best)
