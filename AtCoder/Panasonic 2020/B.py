H, W = map(int, input().split())
import math
if min(H, W) > 1:
    print(math.ceil(H/2) * math.ceil(W/2) + math.floor(H/2) * math.floor(W/2))
else:
    print(1)