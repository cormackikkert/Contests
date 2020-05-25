T = int(input())

for i in range(T):
    N, K = map(int, input().split())
    total = []
    for i in range(N):
        total.append((N + i + 1) / K)
    print(total)
