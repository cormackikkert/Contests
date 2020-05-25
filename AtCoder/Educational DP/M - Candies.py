N, K = map(int, input().split())
candies = list(map(int, input().split()))

MOD = int(pow(10, 9) + 7)

dp = [[0 for i in range(K+1)] for i in range(N+1)]
dp[0] = [1 for i in range(K+1)]

for c in range(1, N+1):
    for r in range(K, -1, -1):
        lo = dp[c - 1][r]
        hi = dp[c - 1][r + candies[c - 1] + 1] if r + candies[c - 1] + 1 <= K else 0
        dp[c][r] = (lo - hi) + (dp[c][r+1] if r + 1 <= K else 0)
        dp[c][r] %= MOD

def pprint(table):
    for i, row in enumerate(table):
        print([row[j] - row[j+1] for j in range(K)] + [row[K]])

# pprint(dp)

print((dp[N][0] - (dp[N][1] if K > 0 else 0)) % MOD)
