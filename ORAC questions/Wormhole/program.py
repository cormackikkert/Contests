with open("wormin.txt") as file:
    R, C, Q = map(int, file.readline().split())
    grid = [file.readline().strip() for i in range(R)]
    mods = [tuple(map(int, file.readline().split())) for i in range(Q)]

print(mods)

def counter(grid):
    points = []
    for row in range(R):
        for col in range(C):
            opposite = 'B' if grid[row][col] == 'O' else 'O'
            if opposite in grid[row]:
                continue
            if opposite in ''.join(row[col] for row in grid):
                continue
            points.append([row, col])

    removed = []
    for i in range(len(points)):
        if points[i] in removed:
            continue
        for other_point in points[i+1:]:
            if other_point in removed:
                continue
            if points[i][0] == other_point[0]:
                removed.append(other_point)
                continue
            if points[i][1] == other_point[1]:
                removed.append(other_point)
                continue
    return len(points) - len(removed)

with open("wormout.txt", "w+") as file:
    file.write(str(counter(grid)))
    for mod in mods:
        file.write('\n')
        grid[mod[0]-1] = grid[mod[0]-1][:mod[1]-1] + ('B' if grid[mod[0]-1][mod[1]-1] == 'O' else 'O') + grid[mod[0]-1][mod[1]:]
        file.write(str(counter(grid)))
