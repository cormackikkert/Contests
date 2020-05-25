N, K = map(int, input().split())
AS = list(map(int, input().split()))
FS = list(map(int, input().split()))
AS.sort(); FS.sort(reverse=True)

def isValid(x):
    import math
    trains = 0
    for i in range(N):
        num = AS[i] * FS[i]
        if num <= x: continue
        trains += math.ceil((num - x) / FS[i])
    return trains <= K

def binarySearch(lo, hi):
    if lo >= hi:
        return lo
    mid = lo + (hi - lo) // 2
    if isValid(mid):
        return binarySearch(lo, mid)
    else:
        return binarySearch(mid + 1, hi)
            
print(binarySearch(0, max(AS[i] * FS[i] for i in range(N))))
