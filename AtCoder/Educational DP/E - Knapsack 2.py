N, W = map(int, input().split())

weights = [None for i in range(N)]
values = [None for i in range(N)]

# dp[i][j] = minimum weight required to get value exactly i, and by using elements 1,...,j

dp = [[float('inf') for i in range(N+1)] for j in range(1000 * N + 1)]

for i in range(N):
    w, v = map(int, input().split())
    weights[i] = w
    values[i] = v

for i in range(N+1):
    dp[0][i] = 0

highest_value = 0
for value in range(1000 * N + 1):
    for item in range(1,N+1):
        
        # Case: dont include item
        dp[value][item] = min(dp[value][item],
                              dp[value][item-1])

        # Case: include item
        if value - values[item-1] < 0: continue
        dp[value][item] = min(dp[value][item], dp[value - values[item-1]][item-1] + weights[item-1])

    if float('inf') > dp[value][-1] <= W:
        highest_value = max(value, highest_value)
    if float('inf') > dp[value][-1]  > W:
        print(highest_value)
        break
"""
highest_value = 0 
for value in range(1000 * N + 1):
    for item in range(1, N+1):
        if dp[value][item] <= W:
            highest_value = max(highest_value, value)

print(highest_value)
"""
