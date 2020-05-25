N, K, bx, by = map(int, input().split())

# node 0 = starting position

def distFunc(u1, u2):
    return max(0, ((u1[0] - u2[0]) ** 2 + (u1[1] - u2[1]) ** 2) ** 0.5 - u1[2] - u2[2])

adjMatrix = [[float('inf') for i in range(N+1)] for j in range(N+1)]
umbrellas = [None for i in range(N+1)]

umbrellas[0] = (0, 0, 0)

for i in range(N):
    umbrellas[i+1] = tuple(map(int, input().split()))

for i, u1 in enumerate(umbrellas):
    for j, u2 in enumerate(umbrellas):
        dist = distFunc(u1, u2)
        if dist <= K:
            adjMatrix[i][j] = dist
            adjMatrix[j][i] = dist

# Dijkstra
seen = [False for i in range(N+1)]
distances = [float('inf') for i in range(N+1)]

distances[0] = 0

while True:
    minNode, minDist = None, float('inf')
    for node in range(N+1):
        if not seen[node] and distances[node] < minDist:
            minDist = distances[node]
            minNode = node
    if minNode == None: break

    seen[minNode] = True

    for otherNode in range(N+1):
        dist = adjMatrix[minNode][otherNode]
        if dist != float('inf'):
            # otherNode is a neighbour
            distances[otherNode] = min(distances[otherNode],
                                       distances[minNode] + dist)

minDist = float('inf')

for p1 in range(N+1):
    for p2 in range(p1, N+1):
        ballGrabDist = distFunc(umbrellas[p1], (bx, by, 0)) + distFunc(umbrellas[p2], (bx, by, 0))
        if ballGrabDist <= K:
            minDist = min(minDist, distances[p1] + distances[p2] + ballGrabDist)

if minDist == float('inf'):
    print(-1)
else:
    print(minDist)
               
            
