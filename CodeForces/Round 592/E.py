N, K = map(int, input().split())
arr = sorted(list(map(int, input().split())))
print(arr)
onl = 1
onr = 1
l = 0
r = N - 1

while l < r:
    lcost = onl * (arr[l+1]-arr[l]) 
    rcost = onr * (arr[r] - arr[r-1])
    if lcost <= rcost and lcost <= K:
        onl += 1
        l += 1
        K -= lcost
        print(lcost)
    elif rcost <= lcost and rcost <= K:
        onr += 1
        r -= 1
        K -= rcost
        print(rcost)
    else:
        break

lo = arr[l]
hi = arr[r]
if l != r:
    if onl < onr:
        lo += K // onl
    else:
        hi -= K // onr
        
if lo >= hi or l == r:
    print(0)
else:
    print(hi - lo)
