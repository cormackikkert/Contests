import sys
sys.setrecursionlimit(10000000)

N = int(input())
edges = [[] for i in range(N+1)]
alledges = []
for i in range(N-1):
    a, b = map(int, input().split())
    alledges.append((a, b))
    edges[a].append(b)
    edges[b].append(a)

def dfs(node, parent):
    used = {col[(node, parent)]}
    curcol = 1
    for n in edges[node]:
        if n == parent: continue

        while curcol in used: curcol += 1

        col[(node, n)] = curcol
        col[(n, node)] = curcol

        dfs(n, node)

        used.add(curcol)
        
col = {}
start = max(range(1, N+1), key = lambda x : len(edges[x]))

for i, n in enumerate(edges[start]):
    col[(start, n)] = i + 1
    col[(n, start)] = i + 1
    dfs(n, start)



done = set()
print(len(edges[start]))
for e in alledges:
    print(col[e])
