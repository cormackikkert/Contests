q = int(input())
for i in range(q):
    n, k = map(int, input().split())
    perm = list(int(x) for x in input())

    def swap(i, j):
        perm[i], perm[j] = perm[j], perm[i]
        
    onLeft = 0
    for i, item in enumerate(perm):
        if item == 0:
            if k < i - onLeft:
                swap(i - k, i)
                break
            else:
                swap(onLeft, i)
                k -= i - onLeft
                onLeft += 1

    print("".join(map(str, perm)))
                
        
