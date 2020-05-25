N, K = map(int, input().split())

grid = [[char == "B" for char in input()] for j in range(N)]
works = [[False for i in range(N)] for j in range(N)]

free = 0
for y, row in enumerate(grid):
    lo = N
    hi = None
    for x, point in enumerate(row):
        if point:
            lo = min(x, lo)
            hi = x
    if (hi == None): free += 1
    elif hi - lo <= K - 1:
        for i in range(max(0, hi - K + 1), lo + 1):
            works[y][i] = True

for x in range(N):
    lo = N
    hi = None
    for y in range(N):
        if grid[y][x]:
            lo = min(y, lo)
            hi = y
    if (hi == None): free += 1
    elif hi - lo <= K - 1:
        for i in range(max(0, hi - K + 1), lo + 1):
            works[i][x] = True


startBest = sum(works[i][j] for j in range(K) for i in range(K))

maxVal = startBest

for y in range(N - K):
    newBest = startBest
    if y != 0:
        startBest = newBest
        for x in range(K):
            startBest -= works[y - 1][x]
            startBest += works[y + K - 1][x]
    for x in range(N - K):
        if x != 0:
            for ny in range(y, y+K):
                startBest -= works[ny][x-1]
                startBest += works[ny][x + K - 1]
        print(x, y, startBest)
        maXVal = max(maxVal, startBest)

print(maxVal + free)
                
        
