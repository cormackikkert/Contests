T = int(input())

def check(a, m):
    h = float('-inf')
    for i, a in enumerate(a):
        h = max(h, a)
        if h != m[i]: return False
    return True

for i in range(T):
    N = int(input())
    QS = list(map(int, input().split()))

    used = [False for i in range(N+1)]
    arr = [None for i in range(N)]
    arr[0] = QS[0]
    used[arr[0]] = True
    for i in range(1, N):
        if QS[i-1] != QS[i]:
            arr[i] = QS[i]
            used[arr[i]] = True
 
    cur = 0
    ind = 1
    while True:
        while cur < N and arr[cur] != None:
            cur += 1
        if cur == N: break
        while used[ind] == True: ind += 1
        arr[cur] = ind
        used[ind] = True

    if check(arr, QS):
        print(" ".join(map(str, arr)))
    else:
        print(-1)
