import math

def check(num, target):
    return math.ceil(num) == target or math.floor(num) == target

mult = 1
def binarySearch(lo, hi, denom, target):
    if lo >= hi:
        return lo if check(lo*pow(10,mult)/denom, target) else -1
    mid = lo + (hi - lo + 1) // 2
    # print(mid*pow(10,mult), denom, target, lo, hi)
    if check(mid*pow(10,mult)/denom, target): return mid
    if mid * pow(10, mult) / denom > target:
        return binarySearch(lo, mid-1, denom, target)
    else:
        return binarySearch(mid+1, hi, denom, target)

T = int(input())
for i in range(T):
    num = ("0" + input().strip()).split(".")
    if len(num) == 1 or len(num[1]) == 0:
        mult = 0
        N = int(num[0])
    else:
        mult = len(num[1])
        N = int(num[0]) * (pow(10, mult)) + int(num[1])

    # Brute force
    for power in range(8):
        denom = pow(2, power)
        numerator = binarySearch(0, 2 * N * denom, denom, N)
        # print(numerator)
        if numerator != -1:
            # print("DONE")
            # print(N, numerator, denom)
            big = numerator // denom
            other = numerator % denom

            rest = "" if other == 0 else str(other) + "/" + str(denom) + '"'
            if big > 0:
                print(str(big) + (" " if rest != "" else '"') + rest)
            else:
                print(rest)
            break
        # print(numerator)
    
