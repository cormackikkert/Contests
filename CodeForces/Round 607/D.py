t = int(input())
for i in range(t):
    r, c = map(int, input().split())
    grid = []
    for i in range(r):
        grid.append(list(input()))

    rowTrues = [all(grid[row][col] == "A" for col in range(c)) for row in range(r)]
    colTrues = [all(grid[row][col] == "A" for row in range(r)) for col in range(c)]

    if all(rowTrues):
        print(0)
        continue

    if rowTrues[0] or rowTrues[-1] or colTrues[0] or colTrues[-1]:
        print(1)
        continue
    
    if any(rowTrues) or any(colTrues):
        print(2)
        continue

    corner = False
    edge = False
    middle = False
    for i in range(r):
        for j in range(c):
            if grid[i][j] == "A":
                middle = True
                if (i == 0 and j == 0) or (i == 0 and j == c-1) or (i == r-1 and j ==0) or (i == r-1 and j == c-1):
                    corner = True
                if i == 0 or i == r-1 or j == 0 or j == c-1:
                    edge = True
    if corner:
        print(2)
        continue

    if edge:
        print(3)
        continue

    if middle:
        print(4)
        continue
    print("MORTAL")
