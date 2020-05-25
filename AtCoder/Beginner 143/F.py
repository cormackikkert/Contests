N = int(input())
A = list(map(int, input().split()))
types = {}
for i in A: types[i] = types.get(i, 0) + 1
A = sorted([types[k] for k in types], reverse=True)
L = len(A)
cumsum = [0 for i in range(L+1)]
for i in range(L-1, -1, -1):
    cumsum[i] = A[i] + cumsum[i+1]



def getMidPoint(lo, hi, O):
    if lo >= hi: return lo
    mid = lo + (hi - lo+1) // 2
    if A[mid] > O:
        return getMidPoint(mid, hi, O)
    else:
        return getMidPoint(lo, mid-1, O)

getMid = [getMidPoint(0, L - 1, o) for o in range(N+1)]

# Highest K for given O
def calc(O):
    

    mid = getMid[O]
    if A[mid] < O: mid = - 1
    return (mid+1) + cumsum[mid+1] // O

for K in range(1, N+1):
    def getO(lo, hi):
        if lo >= hi: return lo
        mid = lo + (hi - lo+1) // 2
        if calc(mid) < K:
            return getO(lo, mid - 1)
        else:
            return getO(mid, hi)
        
    print(getO(0, N))
    
