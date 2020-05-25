def cor(N, K, arr):
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
        elif rcost <= lcost and rcost <= K:
            onr += 1
            r -= 1
            K -= rcost
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
        return 0
    else:
        return hi - lo

def tim(n, k, seq):

    i = 0
    j = n-1
    result = seq[n-1] - seq[0]

    while result > 0:
        if i == j-1:
            used = (seq[i+1]-seq[i])*(i+1)
        else:
            used = (seq[i+1] - seq[i] + seq[j] - seq[j-1])*(i+1)
        if used >= k:
            result -= k//(i+1)
            break
        k -= used
        if i == j-1:
            result = 0
            break
        result = seq[j-1]-seq[i+1]
        i += 1
        j -= 1

    return result


import random
while True:
    a = sorted([random.randint(0, 10) for i in range(4)])
    
    if cor(4, 20, list(a)) != tim(4, 20, list(a)):
        print(cor(4, 20, list(a)), tim(4, 20, list(a)))
        print(a)
    

