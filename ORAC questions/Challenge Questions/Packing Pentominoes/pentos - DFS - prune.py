
with open("pentin.txt") as file:
    R, C = map(int, file.readline().split())
    grid = [list(map(int, file.readline().strip())) for i in range(R)]

blocks = []

def dfs(x, y, left, cur_block):
    print(cur_block)
    if len(left) == 0:
        return [cur_block]

    if all(num != None for num in cur_block):
        print("BLOCK", cur_block)
        max_x, max_y = max(left)
        #if not can_search(max_x, max_y, set(left)):
        #    return None

        min_x, min_y = min(left)
        left.remove((min_x, min_y))
        
        new_blocks = [None for i in range(5)]
        new_blocks[grid[min_y][min_x]-1]=(min_x, min_y)

        result = dfs(min_x, min_y, left, new_blocks)
        left.add((min_x, min_y))

        if result: return [cur_block] + result
        else: return result

    for mx, my in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
        nx = x + mx
        ny = y + my

        if not (0 <= nx < C and 0 <= ny < R):
            continue
        if cur_block[grid[ny][nx]-1] != None:
            continue
        if not ((nx, ny) in left):
            continue

        left.remove((nx, ny))
        cur_block[grid[ny][nx]-1] = (nx, ny)

        result = dfs(nx, ny, left, cur_block)
        if result: return result
        left.add((nx, ny))
        cur_block[grid[ny][nx]-1] = None

        
def can_search(cur_x, cur_y, left):
    left.remove((cur_x, cur_y))
    stack = [(cur_x, cur_y)]
    while stack:
        cx, cy = stack.pop()
        for mx, my in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
            nx = mx + cx
            ny = my + cy

            if not (0 <= nx < C and 0 <= ny < R):
                continue  
            if not ((nx, ny) in left):
                continue

            stack.append((nx, ny))
            left.remove((nx, ny))
    return len(left) == 0


orig = [None for i in range(5)]
orig[grid[0][0]-1] = (0,0)

points = set([(x, y) for y in range(R) for x in range(C)])
points.remove((0, 0))

answer = dfs(0, 0, points, orig)

grid = [['X' for i in range(C)] for j in range(R)]

for i, block in enumerate(answer):
    for (x, y) in block:
        grid[y][x] = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'[i]

        
with open("pentout.txt", "w") as file:
    for row in grid:
        file.write(''.join(row) + '\n')
