N = int(input())
compat = [list(map(int, input().split())) for i in range(N)]

MOD = int(pow(10, 9) + 7)
# dp[i][j] = first i men have been paired, j bitmask of women
dp = [[-1 for i in range(1 << N)] for j in range(N + 1)]
dp[0][0] = 1

def recurse(num, free):
    if num == 0:
        return 1
    if dp[num][free] != -1:
        return dp[num][free]
    total = 0
    for i in range(N):
        if compat[num-1][i] and free & (1 << i):
            total += recurse(num - 1, free & ~(1 << i))
    total %= MOD
    dp[num][free] = total
    return total

recurse(N, (1 << N) - 1)
print(dp[-1][-1])
