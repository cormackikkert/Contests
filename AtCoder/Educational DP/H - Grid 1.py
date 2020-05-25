H, W = map(int, input().split())

mod = pow(10, 9) + 7

grid = [
    [1 if c == '#' else 0 for c in input()]
    for row in range(H)]

dp = [[0 for i in range(W)] for j in range(H)]

dp[0][0] = 1

for y in range(H):
    for x in range(W):
        # Move down
        if y > 0 and not grid[y-1][x]:
            dp[y][x] += dp[y-1][x]

        # Move right
        if x > 0 and not grid[y][x-1]:
            dp[y][x] += dp[y][x-1]
            
        dp[y][x] %= mod

print(dp[-1][-1])
