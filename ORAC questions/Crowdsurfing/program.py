
mappings = {'*': None, 'v': (1, 0), '>': (0, 1), '+': True}
total = 0

with open("surfin.txt") as file:
    rows, cols = map(int, file.readline().strip().split())
    grid = [[mappings[j] for j in file.readline().strip()] for i in range(rows)]
    dpro = [[None for j in range(cols)] for i in range(rows)]

for i in range(cols):
    for j in range(rows):
        row, col = rows - j - 1, cols - i - 1

        if grid[row][col] == None:
            dpro[row][col] = True
            total += 1
            continue

        if grid[row][col] == True:
            dpro[row][col] = False
            continue

        result = grid[row][col]
        drops = dpro[row + result[0]][col + result[1]]
        dpro[row][col] = drops
        total += drops

with open("surfout.txt", "w+") as file:
    file.write(str(total))
