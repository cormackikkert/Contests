# Questions 1: Vestigium

# Equating the trace:
def trace(grid):
    n = len(grid[0])
    total = 0
    for i in range(n):
        total += int(grid[i][i])
    return total

# Duplicate Hunting
def row_dupe(grid):
    n = len(grid[0])
    count = 0
    check = []
    for i in range(n):
        check = []
        for j in range(n):
            if grid[i][j] in check:
                count += 1
                check = []
                break
            elif grid[i][j] not in check:
                check.append(grid[i][j])
    return count

def col_dupe(grid):
    n = len(grid[0])
    count = 0
    check = []
    for i in range(n):
        check = []
        for j in range(n):
            if grid[j][i] in check:
                count += 1
                check = []
                break
            elif grid[j][i] not in check:
                check.append(grid[j][i])
    return count

# Solve a test case (iterated through t)
def solve(iteration):
    #iteration = integer in range(0,t)
    dimensions = int(input())

    grid = []
    for i in range(dimensions):
        grid.append(list(map(int, input().split())))

    #perform necessary operations on grid to obtain Case #i answer
    k = trace(grid)
    r = row_dupe(grid)
    c = col_dupe(grid)

    print("Case #{}: {} {} {}".format(iteration+1, k, r, c))

t = int(input())
for i in range(t):
    solve(i)