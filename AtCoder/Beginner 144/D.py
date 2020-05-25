W, H, X = map(int, input().split())
X /= W
if W*H==X:
    print(0)
    quit()
import math
if H*2*X/pow(H,2)<=W:
    print(90 - math.atan(2*X/pow(H,2)) * 180/math.pi)
else:
    angle = 90 - math.atan(W*W/(2*(W*H-X))) * 180/math.pi
    print(angle)
