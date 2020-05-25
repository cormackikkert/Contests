N = int(input())
dist = []
neighbours = [[] for i in range(N)]
for i in range(N):
    line = list(input())
    dist.append([1 if c == '1' else float('inf') for c in line ])
    for j, char in enumerate(line):
        if char == '1': neighbours[i].append(j)

for i in range(N): dist[i][i] = 0
# Find diameter
for k in range(N):
    for i in range(N):
        for j in range(N):
            if dist[i][k] + dist[k][j] < dist[i][j]:
                dist[i][j] = dist[i][k] + dist[k][j]

startVertex = 0
startDiam = 0
for i in range(N):
    for j in range(N):
        if dist[i][j] > startDiam:
            startDiam = dist[i][j]
            startVertex = i
            
isPossible = True

# Dijkstra
distances = [float('inf') for i in range(N)]
visited = [False for i in range(N)]

distances[startVertex] = 0

while True:
    curNode = min(range(N), key=lambda n:(visited[n], distances[n]))

    if visited[curNode]:
        break
    visited[curNode] = True

    for neighbour in neighbours[curNode]:
        if distances[neighbour] == float('inf'):
            distances[neighbour] = distances[curNode] + 1
        else:
            if abs(distances[neighbour] - distances[curNode]) != 1:
                isPossible = False

if not isPossible:
    print(-1)
else:
    total = len(set(distances))
    print(total)
