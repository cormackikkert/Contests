"""
ID: cormac.1
LANG: PYTHON3
TASK: range
"""

with open("range.in") as file:
    N = int(file.readline())
    land = [[1 if char == '1' else 0 for char in file.readline()]
            for j in range(N)]

landSum = [[0 for i in range(N+1)] for j in range(N+1)]

for y in range(1, N+1):
    for x in range(1, N+1):
        landSum[y][x] = land[y-1][x-1] + landSum[y-1][x] + landSum[y][x-1] - landSum[y-1][x-1]

results = []
for landSize in range(2, N+1):
    freq = 0
    for sx in range(1, N+2 - landSize):
        for sy in range(1, N+2 - landSize):
            area = landSum[sy+landSize-1][sx+landSize-1] - landSum[sy-1][sx+landSize-1] - landSum[sy+landSize-1][sx-1]+landSum[sy-1][sx-1]
            if area == landSize * landSize:
                freq += 1
    if freq != 0: results.append((landSize, freq))
    
with open("range.out", "w") as file:
    for size, freq in results:
        file.write(str(size) + " " + str(freq) + "\n")
