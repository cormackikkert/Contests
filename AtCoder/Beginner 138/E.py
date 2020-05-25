S = list(map(lambda x : ord(x)-ord('a'), input().strip()))
T = list(map(lambda x : ord(x)-ord('a'), input().strip()))

L = len(S)

occ = [[] for i in range(26)]
for i, c in enumerate(S):
    occ[c].append(i)

for c in T:
    if occ[c] == []:
        print(-1)
        quit()

total = 0
cur = -1

def getLowest(bound, lo, hi, lst):
    # Return lowest element in list greater than bound
    while lo < hi:
        mid = lo + (hi - lo) // 2
        if lst[mid] > bound:
            hi = mid
        else:
            lo = mid + 1
    if lst[lo] > bound:
        return lst[lo]
    return lst[0]
        
    

for i, char in enumerate(T):
    newpos = getLowest(cur, 0, len(occ[char])-1, occ[char])
    if cur == newpos:
        total += L
    elif newpos < cur:
        total += L - cur + newpos
    else:
        total += newpos - cur
    cur = newpos
print(total)
    
