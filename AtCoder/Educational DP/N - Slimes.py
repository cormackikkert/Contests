N = int(input())
slimes = list(map(int, input().split()))

sums = [[None for i in range(N)] for j in range(N)]
for i in range(N):
    for j in range(i, N):
        sums[i][j] = sum(slimes[i:j+1])

dp = [[-1 for i in range(N)] for j in range(N)]

def recurse(i, j):
    if i == j: return 0
    
    if dp[i][j] != -1:
        return dp[i][j]

    cost = float('inf')
    for s in range(i, j):
        cost = min(cost, sums[i][j] + recurse(i, s) + recurse(s+1,j))

    dp[i][j] = cost
    return cost

print(recurse(0, N - 1))
