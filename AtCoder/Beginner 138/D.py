import sys
sys.setrecursionlimit(1000000)

N, Q = map(int, input().split())
edges = [[] for i in range(N+1)]
for i in range(N-1):
    a, b = map(int, input().split())
    edges[a].append(b)
    edges[b].append(a)

tally = [0 for i in range(N+1)]
for i in range(Q):
    p, x = map(int, input().split())
    tally[p] += x

count = [0 for i in range(N + 1)]
visited = [False for i in range(N+1)]

stack = [(1, 0)]
while stack:
    root, curCount = stack.pop()
    
    visited[root] = True
    curCount += tally[root]
    count[root] = curCount
    for neighbour in edges[root]:
        if visited[neighbour]: continue
        stack.append((neighbour, curCount))

print(*count[1:])
