n, p, w, d = map(int, input().split())
def calc(z):
    x = ((n - z) * d - p) // (d - w)
    y = ((n - z) * -w +p) // (d - w)
    return x, y

def binarySearch(lo, hi):
    mid = lo + (hi - lo + 1) // 2
    x, y = calc(mid)
    if lo >= hi:
        return lo
    if x < 0:
        return binarySearch(mid + 1, hi)
    if y < 0:
        return binarySearch(lo, mid-1)
    return mid

i = binarySearch(0, int(1e12))
for j in range(2*w):
    if j % 2 == 0:
        index = i + j//2
    else:
        index = i - j//2
    x, y = calc(index)
    if x < 0 or y < 0 or index < 0:
        continue
    if x + y + index == n:
        print(x, y, index)
        break
else:
    print(-1)
