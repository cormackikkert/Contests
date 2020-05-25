import math
t = int(input())
for i in range(t):
    a, b, c, d, k = map(int, input().split())
    pens = math.ceil(a / c)
    pencils = math.ceil(b / d)
    if pens + pencils <= k:
        print(pens, pencils)
    else:
        print(-1)
