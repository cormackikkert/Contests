"""
TASK: agrinet
LANG: PYTHON3
ID: cormac.1
"""

with open("agrinet.in") as file:
    N = int(file.readline())

    weights = [*map(int, file.read().split())]
    weight = [weights[N*i:N*i+N] for i in range(N)]

dist = [float('inf') for i in range(N)]
inTree = [False for i in range(N)]

totalCost = 0
dist[0] = 0

while True:
    cityToAdd = min(list(range(N)), key=lambda n:(inTree[n], dist[n]))

    if inTree[cityToAdd]: break
    
    totalCost += dist[cityToAdd]
    inTree[cityToAdd] = True

    for i in range(N):
        dist[i] = min(dist[i], weight[cityToAdd][i])

with open("agrinet.out", "w") as file:
    file.write(str(totalCost) + "\n")
    
