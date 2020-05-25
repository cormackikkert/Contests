with open("lscin.txt") as file:
    N, M, L = map(int, file.readline().split())
    shops  = list(map(int, file.readline().split()))
    houses = list(map(int, file.readline().split()))
    nums   = list(map(int, file.readline().split()))
    
total = sum(nums)

def getDistance(dist):
    lo = hi = t = 0
    for house in houses:
        while hi + 1 < N and shops[hi+1] - house <= dist:
            hi += 1
        while lo < hi and abs(house - shops[lo]) > dist:
            lo += 1
        if lo >= N or abs(shops[hi] - house) > dist:
            continue
        t += hi - lo + 1

    return t

def check(dist):
    lo = hi = 0

    distances = []
    
    for house in houses:
        while hi + 1 < N and shops[hi+1] - house <= dist:
            hi += 1
        while lo < hi and abs(house - shops[lo]) > dist:
            lo += 1
        if lo >= N or abs(shops[hi] - house) > dist:
            distances.append(0)
            continue
        distances.append(hi - lo + 1)

    return sorted(distances)

lo = 0
hi = L

while lo <= hi:
    mid = lo + (hi - lo) // 2
    
    distances = getDistance(mid)
    
    if distances == total:
        lo = mid
        hi = mid
        break

    if distances > total:
        hi = mid - 1
    else:
        lo = mid + 1

with open("lscout.txt", "w") as file:
    if check(lo) == nums and lo <= hi:
        file.write(str(lo))
    else:
        file.write(str(-1))
