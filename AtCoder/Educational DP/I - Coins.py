N = int(input())

coins = list(map(float, input().split()))

dp = [[0 for i in range(N+1)] for j in range(N)]

dp[0][0] = 1 - coins[0]
dp[0][1] = coins[0]

for j in range(1, N):
    for h in range(j+2):
        if h == 0:
            dp[j][h] = (1 - coins[j]) * dp[j-1][0]
        else:
            dp[j][h] = (1 - coins[j]) * dp[j-1][h] + coins[j] * dp[j-1][h-1]
     
print(sum(dp[-1][head] for head in range(N//2 + 1, N+1)))
