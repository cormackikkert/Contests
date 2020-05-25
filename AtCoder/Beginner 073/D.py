N, M, R = map(int, input().split())
towns = list(map(int, input().split()))
allEdges = [[float('inf') for i in range(N)] for i in range(N)]
for i in range(M):
    A, B, C = map(int, input().split())
    allEdges[A-1][B-1] = C
    allEdges[B-1][A-1] = C

for k in range(N):
    for i in range(N):
        for j in range(N):
            allEdges[i][j] = min(allEdges[i][j], allEdges[i][k] + allEdges[k][j])

graph = [[float('inf') for i in range(R)] for j in range(R)]

for i in range(R):
    for j in range(R):
        graph[i][j] = allEdges[towns[i] - 1][towns[j] - 1]

dp = [[-1 for i in range(R)] for j in range(1 << R)]

def recurse(seen, cur):
    if seen == (1 << R) - 1:
        return 0
    if dp[seen][cur] != -1:
        return dp[seen][cur]
    
    cost = float('inf')
    for i in range(R):
        if seen & (1 << i) == 0:
            cost = min(cost, recurse(seen | (1 << i), i) + graph[cur][i])
    dp[seen][cur] = cost
    return dp[seen][cur]

cost = float('inf')
for i in range(R):
    cost = min(cost, recurse(1 << i, i))

print(cost)
