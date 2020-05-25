T = int(input())
for i in range(T):
    N, M = map(int, input().split())
    weights = list(map(int, input().split()))
    if N == 2:
        print(-1)
    elif M < N:
        print(-1)
    else:
        print(2 * sum(weights))
        for i in range(N):
            print(i + 1, (i+1) % N + 1)
