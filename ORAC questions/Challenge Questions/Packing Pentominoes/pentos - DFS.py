
with open("pentin.txt") as file:
    R, C = map(int, file.readline().split())
    grid = [list(map(int, file.readline().strip())) for i in range(R)]

blocks = []

def dfs(x, y):
    queue = [((x, y, grid[y][x]),)]
    while queue:
        block = queue.pop()
        if len(block) == 5:
            new = set(block)
            if new not in blocks:
                blocks.append(new)
        else:
            x, y, _ = block[-1]
            for mx, my in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                nx = x + mx
                ny = y + my
                if 0 <= nx < C and 0 <= ny < R:
                    positions = []
                    numbers = []
                    for item in block:
                        positions.append((item[0], item[1]))
                        numbers.append(item[2])
                    if (nx, ny) not in positions and grid[ny][nx] not in numbers:
                        queue.append(block + ((nx, ny, grid[ny][nx]),))

def brute_force(current, blocks):
    if len(current) == (R * C) / 5:
        # Make sure no blocks repeat
        positions = []
        for block in current:
            for x,y,w in block:
                if (x, y) not in positions:
                    positions.append((x, y))
                else:
                    return None
        return current

    if len(blocks) == 0:
        return None
    
    for i, block in enumerate(blocks):
        if block not in current:
            result = brute_force(current + [block], blocks[:i] + blocks[i + 1:])
            if result:
                return result
            
for x in range(C):
    for y in range(R):
        dfs(x, y)
        
items = brute_force([], blocks)
grid = [['X' for i in range(C)] for j in range(R)]

for i, item in enumerate(items):
    for x, y, w in item:
        grid[y][x] = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'[i]
        
with open("pentout.txt", "w") as file:
    for row in grid:
        file.write(''.join(row) + '\n')
