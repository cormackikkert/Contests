T = int(input())
for i in range(T):
    N, M, K = map(int, input().split())
    H = list(map(int, input().split()))

    cur = 0
    while cur < N - 1:
        if M < 0:
            break
        if H[cur] >= (H[cur+1] - K):
            M += H[cur] - (H[cur+1] - K)
        else:
            M -= H[cur+1] - K - H[cur]
        cur += 1

    print(["NO", "YES"][cur == N - 1 and M >= 0])
