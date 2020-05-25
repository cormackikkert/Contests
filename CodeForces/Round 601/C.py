import sys
sys.setrecursionlimit(200000)

N = int(input())

app1 = [set() for i in range(N + 1)]
app2 = [set() for i in range(N + 1)]

for i in range(N-2):
    a, b, c = map(int, input().split())

    for x, o in [(a, b), (a, c), (b, a), (b, c), (c, a), (c, b)]:
        if o in app1[x]:
            app1[x].remove(o)
            app2[x].add(o)
        else:
            app1[x].add(o)

sequence = []
visited = [False for i in range(N+1)]
start = None
for i, s in enumerate(app2):
    if len(s) == 1: start = i; break

def dfs(v):
    visited[v] = True
    sequence.append(v)
    for item in app2[v]:
        if visited[item]: continue
        dfs(item)

dfs(start)

for i, s in enumerate(app1):
    if i == 0: continue
    if len(app2[i]) != 0: continue
    if start in app1[i]:
        sequence = [i] + sequence
    else:
        sequence.append(i)
        
print(" ".join(map(str, sequence)))
    
