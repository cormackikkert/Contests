q = int(input())
for i in range(q):
    n = int(input())
    perm = list(map(int, input().split()))

    def swap(i, j):
        perm[i], perm[j] = perm[j], perm[i]

    curIndex = 0
    while curIndex < n:
        move = min(range(curIndex, n), key = lambda x : perm[x])
        for i in range(move - 1, curIndex - 1, -1):
            swap(i, i+1)
        if move != curIndex:
            curIndex = move
        else:
            curIndex += 1
            
    print(" ".join(map(str, perm)))
    
