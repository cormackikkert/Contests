N, K = map(int, input().split())
H = [0] + list(map(int, input().split())) + [0]

# dp[i][j] = minimum operations upto col i (fixed), with j moves remaining
dp = [[float('inf') for i in range(K+1)] for j in range(N+2)]
dp[0] = [0 for i in range(K+1)]

def cost(i, j):
    return max(0, H[j] - H[i])

for i in range(1, N+2):
    for j in range(K+1):
        for d in range(j+1):
            if i-d-1 < 0: break
            dp[i][j] = min(dp[i][j], cost(i-d-1, i) + dp[i-d-1][j-d])
                
print(dp[-1][K])
