with open("wormin.txt") as file:
	R, C, Q = map(int, file.readline().strip().split())
	grid = [list(int(char == "B") for char in file.readline().strip()) for i in range(R)]
	mods = [tuple(map(lambda n:int(n)-1, file.readline().split())) for i in range(Q)]

row_full = [False for i in range(R)]
row_count = 0
col_full = [False for i in range(C)]
col_count = 0

def update(x, y):
	global row_count
	global col_count
	row = [grid[i][x] for i in range(R)]
	
	
	if all(grid[y]) or not any(grid[y]):
		row_count += int(row_full[y] == False)
		row_full[y] = True
	else:
		row_count -= int(row_full[y] == True)
		row_full[y] = False

	if all(row) or not any(row):
		col_count += int(col_full[x] == False)
		col_full[x] = True
	else:
		col_count -= int(col_full[x] == True)
		col_full[x] = False

def get_components():
	if R == 1 and C == 1:
		return 0
	if R == 1:
		return int(row_count == 1)
	if C == 1:
		return int(col_count == 1)
	if (row_count == 0 and col_count == C):
		if C >= 4:
			return 1
		elif C == 3 or C == 2:
			return 2
		elif C == 1:
			return 1
	if (row_count == R and col_count == 0):
		if R >= 4:
			return 1
		elif R == 3 or R == 2:
			return 2
		elif R == 1:
			return 1
	return min(row_count, col_count)

for y in range(R):
	if all(grid[y]) or not any(grid[y]):
		row_count += 1
		row_full[y] = True

for x in range(C):
	row = [grid[i][x] for i in range(R)]
	if all(row) or not any(row):
		col_count += 1
		col_full[x] = True

with open("wormout.txt", "w") as file:
	for (y, x) in mods:
		file.write(str(get_components())+"\n")

		grid[y][x] = 1 - grid[y][x]
		update(x, y)

	file.write(str(get_components())+"\n")
