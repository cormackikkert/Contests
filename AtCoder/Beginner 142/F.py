N, M = map(int, input().split())
neighbours = [[] for i in range(N)]
for i in range(M):
    A, B = map(lambda x:int(x)-1,input().split())
    neighbours[A].append(B)

visited = [False for i in range(N)]
def bfs(node):
    parents = [None for i in range(N)]
    stack = [node]
    while stack:
        item = stack.pop(0)
        orig = item
        for neighbour in neighbours[item]:
            if visited[neighbour]:
                if parents[neighbour] == None:
                    parents[neighbour] = item
                try:
                    graph = {neighbour}
                    while item != neighbour:
                        graph.add(item)
                        item = parents[item]
                        if item == orig and item != neighbour:
                            1/0
                    print(len(graph))
                    for item in graph:
                        print(item+1)
                    return True
                except:
                    pass
            if not visited[neighbour]:
                parents[neighbour] = item
                visited[neighbour] = True
                stack.append(neighbour)
            
for i in range(N):
    if not visited[i]:
        if bfs(i):
            break
else:
   print(-1)
