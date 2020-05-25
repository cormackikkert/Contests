N, M, L = map(int, input().split())
singular = [[float('inf') for i in range(N)] for j in range(N)]
for i in range(N): singular[i][i] = 0
for i in range(M):
    A, B, C = map(int, input().split())
    A, B = A-1, B-1
    singular[A][B] = C
    singular[B][A] = C

for k in range(N):
    for i in range(N):
        for j in range(N):
            singular[i][j] = min(singular[i][j], singular[i][k] + singular[k][j])
for i in range(N):
    for j in range(N):
        if singular[i][j] <= L:
            singular[i][j] = 0
        else:
            singular[i][j] = float('inf')

for k in range(N):
    for i in range(N):
        for j in range(N):
            singular[i][j] = min(singular[i][j], singular[i][k] + singular[k][j] + 1)

Q = int(input())
for i in range(Q):
    s, t = map(int, input().split())
    d = singular[s-1][t-1]
    if d == float('inf'):
        print(-1)
    else:
        print(d)

""" charls code
start = 1
end = [1,6,9]

OneByOne = [[1,1]]
TwoByTwo = [[1,2],[2,3],[3,4],[4,5],[5,6]]
ThreeByThree = [[1,2],[1,4],[1,5],[2,3],[2,5],[2,6],[3,6],[5,9],[6,8],[6,9],[7,8],[8,9]]
allCounts = []

def shortMaze(paths,current, end, count=-1):
  for i in paths:
    if i[0] == current:
      count +=1
      if i[1] == end:
        allCounts.append(count)
        return
      shortMaze(paths, i[1], end, count)

shortMaze(OneByOne, start, end[0])
print(min(allCounts)) 

allCounts = []
shortMaze(TwoByTwo, start, end[1])
print(min(allCounts))

allCounts = []
shortMaze(ThreeByThree, start, end[2])
print(min(allCounts))
"""
