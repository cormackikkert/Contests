N = int(input())
points = []
for i in range(N):
    x, y = map(int, input().split())
    points.append((x, y))

import itertools
totalDist = 0
totalSum = 0
for perm in itertools.permutations(list(range(N))):
    curLength = 0
    for i in range(1, N):
        curLength += ((points[perm[i]][0] - points[perm[i - 1]][0]) ** 2 + (points[perm[i]][1] - points[perm[i - 1]][1]) ** 2) ** 0.5
    totalDist += curLength
    totalSum += 1
print(totalDist/totalSum)
