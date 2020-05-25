import math
T = int(input())
for i in range(T):
    r, g, b = sorted(list(map(int, input().split())))
    b = min(b, 2 * math.ceil(g / 2))
    print((r + g + b) // 2)
    
