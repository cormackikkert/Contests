N, W = map(int, input().split())

weights = [None for i in range(N)]
values = [None for i in range(N)]

# dp[i][j] = maximum value using at most i weight and using elements 1,...,j

dp = [[0 for i in range(N+1)] for j in range(W+1)]

for i in range(N):
    w, v = map(int, input().split())
    weights[i] = w
    values[i] = v
    
for weight in range(W+1):
    for item in range(1,N+1):

        # Case: dont include item
        dp[weight][item] = max(dp[weight][item],
                               dp[weight][item-1])

        # Case: include item
        dp[weight][item] = max(dp[weight][item],
                               dp[weight-1][item])
        
        if weights[item-1] > weight: continue
 
        # Case: include item
        dp[weight][item] = max(dp[weight][item],
                               values[item-1] + dp[weight - weights[item-1]][item - 1])
    
print(max(dp[-1]))
