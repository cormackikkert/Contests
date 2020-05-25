import operator as op
from functools import reduce

def ncr(n, r):
    if (r<0):
        return 0
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return int(numer / denom)


n = int(input())
for i in range(n):
    isGood = True
    
    k = input().strip()
    nos = len(k)
    ink = int(k)
    kay = [int(i) for i in k]

    for m in range(1,len(kay)):
        if (kay[m]<kay[m-1]):
            print(-1)
            isGood = False

    if (not isGood):
        continue
    
    combs = 0
    for j in range(1,nos):
        combs += ncr(8+j,8)

    combs += ncr(8+nos, 8)

    combs -= ncr(8-kay[0]+nos,8-kay[0])
    
    for a in range(1,len(kay)):
        if(kay[a]>=kay[a-1]):
            combs -= ncr(8-kay[a]+nos-a,8-kay[a])
    
    print(combs)
