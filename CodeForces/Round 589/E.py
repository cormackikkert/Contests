n, k = map(int, input().split())

r = pow(10, 9) + 7

def num(free):
    total = 1
    for i in range(free):
        total *= k
        total %= r
    return total

print((2 * num(n * n - n) - num(n * n - 2 * n + n%2)) % r)

def isValid(grid):
    for y in range(len(grid)):
        if min(grid[y][x] for x in range(len(grid))) != 1: return False
    for x in range(len(grid)):
        if min(grid[y][x] for y in range(len(grid))) != 1: return False
    return True

print(len(list(1
        for a in [1, 2]
        for b in [1, 2]
        for c in [1, 2]
        for d in [1, 2]
        for e in [1, 2]
        for f in [1, 2]
        for g in [1, 2]
        for h in [1, 2]
        for i in [1, 2]
          if isValid([[a, b, c],
         [d, e, f],
         [g, h, i]]))))
