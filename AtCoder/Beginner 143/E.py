N, M, L = map(int, input().split())
edges = [[float('inf') for i in range(N)] for j in range(N)]
for i in range(M):
    A, B, C = map(int, input().split())
    A, B = A-1, B-1
    edges[A][B] = C
    edges[B][A] = C

data = [[None for i in range(N)] for j in range(N)]

# Build up data
def dijkstra(start):
    distances = [(float('inf'), float('inf')) for i in range(N)]
    visited = [False for i in range(N)]
    
    distances[start] = (0, L)
    while True:
        minVertex, minDist = None, (float('inf'), float('inf'))
        for n in range(N):
            if not visited[n] and distances[n] < minDist:
                minVertex = n
                minDist = distances[n]

        if minVertex == None: break

        curVertex = minVertex

        refill, left = distances[curVertex]
        
        if visited[curVertex] or distances[curVertex][0] == float('inf'): break
        visited[curVertex] = True
        
        for neighbour in range(N):
            cost = edges[curVertex][neighbour]
            if cost == float('inf'): continue

            if cost > left and L >= cost:
                distances[neighbour] = min(distances[neighbour], (refill + 1, L - cost))
            elif left >= cost:
                distances[neighbour] = min(distances[neighbour], (refill, left - cost))

    for i in range(N):
        if visited[i]:
            data[start][i] = distances[i][0]
        else:
            data[start][i] = -1

for i in range(N): dijkstra(i)

Q = int(input())
for i in range(Q):
    s, t = map(int, input().split())
    print(data[s-1][t-1])
