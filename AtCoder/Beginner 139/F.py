"""
N = int(input())
points = []
for i in range(N):
    x, y = map(int, input().split())
    if (x, y) == (0, 0): N -= 1; continue
    points.append((x,y))

if not points:
    print(0)
    quit()
    
PI = 3.14
"""
import math
def calc(points):
    N = len(points)//2
    # Greedy optimality
    l = 0
    h = 1

    xsum = points[0][0]
    ysum = points[0][1]

    highest = xsum ** 2 + ysum ** 2
    while h < len(points):
        nx, ny = xsum - points[l][0], ysum - points[l][1]
        if (not l >= h) and nx ** 2 + ny ** 2 > xsum ** 2 + ysum ** 2 or h - l >= N:
            xsum, ysum = nx, ny
            l += 1
        else:
            xsum += points[h][0]
            ysum += points[h][1]
            h += 1
        highest = max(highest, xsum ** 2 + ysum ** 2)
    return highest ** 0.5

def calc2(points):
    N = len(points)//2
    hi = 0
    
    for s in range(N):
        for j in range(1,N+1):
            xt = yt = 0
            for x in range(j):
                xt += points[s+x][0]
                yt += points[s+x][1]
            hi = max(hi, xt ** 2 + yt ** 2)

    return hi ** 0.5

import random  
while True:
    p = [(0, random.randint(1, 100000)) for i in range(random.randint(0, 100))]
    p+= [(0, -random.randint(1, 100000)) for i in range(random.randint(0, 100))]
    if p == []: continue
    p.sort(key=lambda x : math.atan2(x[0], x[1]))
    if calc2(p + p) != calc(p + p):
        print("REEE", p)
print(calc2(points + points))
