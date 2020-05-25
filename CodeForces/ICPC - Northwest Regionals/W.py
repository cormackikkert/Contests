T = int(input())
for i in range(T):
    print("Case " + str(i + 1) + ":")
    P = int(input())
    PL = {}
    PX = [None for i in range(P)]
    PY = [None for i in range(P)]
    PZ = [None for i in range(P)]

    def getDist(i, j):
        return ((PX[i] - PX[j]) ** 2 + (PY[i] - PY[j]) ** 2 + (PZ[i] - PZ[j]) ** 2) ** 0.5
    
    for i in range(P):
        n, x, y, z = input().split()
        PL[n] = i
        PX[i] = int(x)
        PY[i] = int(y)
        PZ[i] = int(z)
        
    W = int(input())
    dist = [[float('inf') for i in range(P)] for j in range(P)]
    for i in range(P):
        for j in range(P):
            dist[i][j] = getDist(i, j)
            
    for i in range(W):
        p1, p2 = input().split()

        p1index, p2index = PL[p1], PL[p2]

        dist[p1index][p2index] = 0
    

    for k in range(P):
        for i in range(P):
            for j in range(P):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

    q = int(input())
    for i in range(q):
        p1, p2 = input().split()
        print("The distance from " + p1 + " to " + p2 + " is " + str(int(dist[PL[p1]][PL[p2]] + 0.5)) + " parsecs.")
    
