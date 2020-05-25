x = int(input())
def rec(lst, x):
    if x == 0:
        return
    lst.append(x); rec(lst, x - 1)
a = []
print(rec(a, 5))
print(a)

N = int(input())
nums = list(map(int, input().split()))
perm = sorted(range(N), key=lambda n:nums[n], reverse=True)

import bisect
found = SortedList([-1, N])
total = 0
def sup(index):
    lo = 0; hi = len(found) - 1
    while lo < hi:
        mid = lo + (hi - lo + 1) // 2
        if found[mid] >= index:
            hi = mid - 1
        else:
            lo = mid
    return found[lo]

def inf(index):
    lo = 0; hi = len(found) - 1
    while lo < hi:
        mid = lo + (hi - lo) // 2
        if found[mid] <= index:
            lo = mid + 1
        else:
            hi = mid
    return found[lo]
            
for ind in perm:
    if nums[ind] == N: bisect.insort(found, ind); continue
    
    l0 = sup(ind)
    l1 = sup(l0)
    r0 = inf(ind)
    r1 = inf(r0)

    le = (l0 - l1) * (r0 - ind) if l0 != -1 else 0
    ri = (r1 - r0) * (ind - l0) if r0 != N else 0

    total += (le + ri) * nums[ind]
    found.add(ind)
print(total)
