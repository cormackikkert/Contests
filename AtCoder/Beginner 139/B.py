A, B = map(int, input().split())
import math
if B != 1:
    print(math.ceil((B-1)/(A-1)))
else:
    print(0)
