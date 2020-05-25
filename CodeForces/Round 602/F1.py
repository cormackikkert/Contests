N, K = map(int, input().split())
HS = list(map(int, input().split()))

MOD = 998244353

dppos = [[-1 for j in range(N+1)] for i in range(N)]
dpneg = [[-1 for j in range(N+1)] for i in range(N)]

def recurse(i, j):
    if j < 0:
        dp = dpneg
    else:
        dp = dppos
    if j > N or j < -N: return 0
    
    if dp[i][j] != -1:
        return dp[i][j]

    if i == 0:
        if j == -1:
            return 1 if HS[1 % N] != HS[0] else 0
        if j == 0:
            return (K - 2) + (2 if HS[1 % N] == HS[0] else 0)
        if j == 1:
            return 1 if HS[1 % N] != HS[0] else 0
        return 0
    ways = 0
    if HS[(i + 1) % N] == HS[i]:
        # Get both wrong
        ways += K * recurse(i - 1, j)
    else:
        # Gain a point 2nd
        ways += recurse(i - 1, j - 1)
        # Both Wrong
        ways += (K - 2) * recurse(i - 1, j)
        # Gain a point 1st
        ways += recurse(i - 1, j + 1)
    ways %= MOD

    dp[i][j] = ways
    return ways

t = 0
for i in range(1, N+1):
    t += recurse(N-1, i)
print(t % MOD)
