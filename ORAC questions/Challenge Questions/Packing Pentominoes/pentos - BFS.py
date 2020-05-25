import sys
sys.setrecursionlimit(1500):

with open("pentin.txt") as file:
    R, C = map(int, file.readline().strip().split())
    grid = [list(map(int, file.readline().strip())) for i in range(R)]

moves = set((1, 0), (-1, 0), (0, 1), (0, -1))
pents = []

def display(done):
    updatedGrid = [["." for i in range(C)] for j in range(R)]
    for i, pento in enumerate(done):
        for x,y in pento:
            updatedGrid[y][x] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i]
    return [''.join(row) for row in updatedGrid]
    
        
def search(current, pos):
    if len(current) == 5:
        pent = set(current)
        if pent not in pents:
            pents.append(pent)
    px, py = pos
    for mx, my in moves:
        nx = px + mx
        ny = py + my
        if 0 <= nx < C and 0 <= ny < R:
            if grid[ny][nx] not in [grid[posy][posx] for posx,posy in current]:
                search(current + [(nx, ny)], (nx, ny))
    
def generate(blocks, current):
    if len(current) == (R * C) / 5:
        return display(current)
    else:
        for block in blocks:
            if (block not in current):
                d = []
                for a in current:
                    for pos in a:
                        if pos in d:
                            break
                        else:
                            d.append(pos)
                else:
                    for pos in block:
                        if pos in d:
                            break
                        else:
                            d.append(pos)
                    else:
                        result = generate(blocks, current + [block])
                        if result:
                            return result
                        
for x in range(C):
    for y in range(R):
        # Calculate all pentominoes from point x, y
        search([], (x, y))

with open("pentout.txt", "w+") as file:
    for line in generate(pents, []):
        file.write(line + "\n")
