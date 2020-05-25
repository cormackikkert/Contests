T = int(input())
for i in range(T):
    N, K, D = map(int, input().split())
    shows = list(map(int, input().split()))

    count = [0 for i in range(K + 1)]
    types = 1

    best = float('inf')
    lo = 0
    hi = 0
    count[shows[0]] += 1
    while hi < N:
        
        
        if hi - lo + 1 < D:
            hi += 1
            
            try:
                if count[shows[hi]] == 0:
                    types += 1
                count[shows[hi]] += 1
            except:
                pass
        else:
            best = min(best, types)
            
            count[shows[lo]] -= 1
            if count[shows[lo]] == 0:
                types -= 1

            lo += 1

    print(best)
