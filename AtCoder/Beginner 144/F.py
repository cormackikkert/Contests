N, M = map(int, input().split())
edges = [[] for i in range(N)]
for i in range(M):
    s, t = map(int, input().split())
    edges[s - 1].append(t - 1)

def calc():
    steps = [0 for i in range(N)]
    for i in range(N - 2, -1, -1):
        steps[i] = 1 / len(edges[i]) * sum(steps[node] for node in edges[i]) + 1

    return steps

steps = calc()

best = steps[0]

for i in range(N - 1):
    if len(edges[i]) == 1: continue
    highest = max(edges[i], key=lambda n: steps[n])
    edges[i].remove(highest)
    best = min(best, calc()[0])
    edges[i].append(highest)

print(best)
