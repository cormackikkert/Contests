with open("evadingin.txt") as file:
    N, E, X, K = map(int, file.readline().split())
    neighbours = [[] for i in range(N+1)]
    for i in range(E):
        a, b = map(int, file.readline().split())
        neighbours[a].append(b)
        neighbours[b].append(a)

# Find shortest odd and even path to a vertex
distance = [[float('inf'), float('inf')] for i in range(N+1)]
distance[X][0] = 0

queue = [None for i in range(100001)]
head = 0
pointer = 1
queue[0] = (X, 0)
while queue[head] != None:
    vertex, parity = queue[head]
    
    head = (head + 1) % 100001
    if distance[vertex][parity] == K: continue
    
    for neighbour in neighbours[vertex]:
        if distance[neighbour][1-parity] == float('inf'):
            distance[neighbour][1-parity] = distance[vertex][parity] + 1
            queue[pointer] = (neighbour, 1-parity)
            pointer = (pointer + 1) % 100001

with open("evadingout.txt", "w") as file:
    file.write(str(sum(distance[i][K%2] <= K for i in range(1, N+1))))
