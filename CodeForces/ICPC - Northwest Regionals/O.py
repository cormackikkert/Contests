T = int(input())
for i in range(T):
    N = int(input())
    values = [list(map(float, input().split())) for i in range(N)]

    dp = [1 for i in range(N)]
    for i in range(N-2, -1, -1):
        for j in range(i+1, N):
            if values[i][0] < values[j][0] and values[i][1] > values[j][1]:
                dp[i] = max(dp[i], 1 + dp[j])

    print(max(dp))
