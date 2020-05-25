import sys
sys.setrecursionlimit(100000 + 1)

N, M = map(int, input().split())

maxDist = [0 for i in range(N+1)]
in_degree = [0 for i in range(N+1)]
adj_list = [[] for i in range(N+1)]

for i in range(M):
    x, y = map(int, input().split())
    adj_list[x].append(y)
    in_degree[y] += 1

for node in range(1, N+1):
    adj_list[0].append(node)
    in_degree[node] += 1

# dp[i] = maximum length of path ending at i
flattenedNodes = []
def dfs(node):
    for child in adj_list[node]:
        maxDist[child] = max(maxDist[child], 1 + maxDist[node])
        in_degree[child] -= 1
        if in_degree[child] == 0:
            dfs(child)
            
dfs(0)
print(max(maxDist) - 1)
