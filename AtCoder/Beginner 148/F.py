import sys
sys.setrecursionlimit(1000000)
 
N, u, v = map(int, input().split())
 
u -= 1
v -= 1
 
graph = [[] for i in range(N)]
for i in range(N - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    graph[a].append(b)
    graph[b].append(a)
 
lst = []
def calcDist(cur, par, dst):
    global lst  
    q = []
    lst[cur] = dst
    for neighbour in graph[cur]:
        if neighbour == par: continue
        calcDist(neighbour, cur, dst + 1)
        
uDist = [None for i in range(N)]
vDist = [None for i in range(N)]
lst = uDist
calcDist(u, -1, 0)
lst = vDist
calcDist(v, -1, 0)
 
best = 0

for node in range(N):
    if uDist[node] < vDist[node]: best = max(best, vDist[node] - 1)
print(best)
