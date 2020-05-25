"""
ID: cormac.1
LANG: PYTHON3
TASK: camelot
"""
from heapq import *

def kingDist(px, py, ex, ey):
    return min(abs(px - ex), abs(py - ey)) + abs(abs(px - ex) - abs(py - ey))

KNIGHT_DELTAS = {(-2, 1), (-1, 2), (1, 2), (2, 1), (2, -1), (1, -2), (-1, -2), (-2, -1)}

def dijkstra(point):
    # (hasKing, px, py)
    
    heap = []

    processed = [[[False
                   for i in range(C)]
                   for j in range(R)] for b in range(2)]
    
    distances = [[[float('inf')
                  for i in range(C)]
                  for j in range(R)] for b in range(2)]

    distances[False][point[1]][point[0]] = 0
    
    heappush(heap, (0, (False, point[0], point[1])))

    while heap:
        _, (hasKing, px, py) = heappop(heap)
        if processed[hasKing][py][px]: continue
        processed[hasKing][py][px] = True

        for MX, MY in KNIGHT_DELTAS:
            if not (0 <= px + MX < C and 0 <= py + MY < R): continue
            if distances[hasKing][py][px] + 1 < distances[hasKing][py + MY][px + MX]:
                distances[hasKing][py + MY][px + MX] = distances[hasKing][py][px] + 1
                heappush(heap, (distances[hasKing][py + MY][px + MX], (hasKing, px + MX, py + MY)))
        if hasKing == False:
            if distances[False][py][px] + kingDist(px, py, KX, KY) < distances[True][py][px]:
                distances[True][py][px] = distances[False][py][px] + kingDist(px, py, KX, KY)
                heappush(heap, (distances[True][py][px], (True, px, py)))
    print("DIJKSTRA")
    for row in distances[False]:
        print(row)
    print("---")
    for row in distances[True]:
        print(row)
    for y in range(R):
        for x in range(C):
            totalKnightCost[y][x] += distances[False][y][x]
            kingCost[y][x] = min(kingCost[y][x], distances[True][y][x] - distances[False][y][x])

with open("camelot.in") as file:
    R, C = map(int, file.readline().split())

    
    
    placements = file.read().split()

    KY = int(placements[1]) - 1
    KX = ord(placements[0]) - ord('A')
    
    totalKnightCost = [[0 for i in range(C)] for i in range(R)]
    kingCost        = [[kingDist(KX, KY, i, j) for i in range(C)] for j in range(R)]
    
    
    for i in range(1,len(placements) // 2):
        pointx, pointy = placements[2*i:2*i+2]
        pointx = ord(pointx) - ord('A')
        pointy = int(pointy) - 1
        dijkstra((pointx, pointy))

minMoves = float('inf')
for x in range(C):
    for y in range(R):
        minMoves = min(totalKnightCost[y][x] + kingCost[y][x], minMoves)

with open("camelot.out", "w") as file:
    file.write(str(minMoves) + "\n")
        
