N, K = map(int, input().split())
heights = list(map(int, input().split()))

dp = [float('inf') for i in range(N)]
dp[0] = 0

for i, h in enumerate(heights[1:]):
    index = i + 1
    for j in range(K):
        back = ~j
        if index + back >= 0:
            dp[index] = min(dp[index], dp[index + back] +
                            abs(heights[index] - heights[index + back]))


print(dp[-1])
