with open("atlanin.txt") as file:
    hi, lo = map(int, file.readline().split())
    R, C = map(int, file.readline().split())
    grid = [list(map(int, file.readline().split())) for i in range(R)]
    vaul = [[True for i in range(C)] for j in range(R)]

ADJ_LIST = [(-1, -1), (-1, 0), (-1, 1), (0, -1), (0, 1), (1, -1), (1, 0), (1, 1)]

for x in range(C):
    for y in range(R):
        if x in [0, C - 1] or y in [0, R - 1]:
            if grid[y][x] <= hi:
                queue = [(x, y)]
                vaul[y][x] = False
                while queue:
                    
                    px, py = queue.pop()    
                    for mx, my in ADJ_LIST:
                        if  0 <= px + mx < C and 0 <= py + my < R:
                            if vaul[py + my][px + mx]:
                                if grid[py + my][px + mx] <= hi:
                                    queue.append((px + mx, py + my))
                                    vaul[py + my][px + mx] = False

done = set()
for x in range(C):
    for y in range(R):
        if x in [0, C - 1] or y in [0, R - 1]:
            queue = [(x, y)]
            if grid[y][x] > lo:
                vaul[y][x] = True
            while queue:
                px, py = queue.pop()
                if grid[py][px] > lo:
                    vaul[py][px] = True
                for mx, my in ADJ_LIST:
                    if  0 <= px + mx < C and 0 <= py + my < R:
                        if (px + mx, py + my) not in done:
                            if grid[py][px] <= grid[py + my][px + mx]:
                                queue.append((px + mx, py + my))
                                done.add((px + mx, py + my))
total = 0
for x in range(C):
    for y in range(R):
        total += 1 - vaul[y][x]


with open("atlanout.txt", "w") as file:
    file.write(str(total))

