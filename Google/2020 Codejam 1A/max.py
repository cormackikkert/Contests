import math
x, y = map(int, input().split())
def lcm(x,y):
    return (x * y)//math.gcd(x, y)

def thingo(x,y):
    if (x == 0 and y == 0):
        return -1
    if (x != 0 and y == 0):
        return x
    test = lcm(x,y)
    if (test-x >= x):
        return test-x
    else:
        return -1
print(thingo(x,y))