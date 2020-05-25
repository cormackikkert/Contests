N = int(input())

vals = [[0, 0, 0] for i in range(N)]

for i in range(N):
    v1, v2, v3 = map(int, input().split())
    vals[i][0] = v1
    vals[i][1] = v2
    vals[i][2] = v3

dp = [[0 for i in range(3)] for j in range(N)]

dp[0][0] = vals[0][0]
dp[0][1] = vals[0][1]
dp[0][2] = vals[0][2]

for i in range(1, N):
    for activity in range(3):
        for pastActivity in range(3):
            if activity == pastActivity: continue
            
            dp[i][activity] = max(dp[i][activity],
                                  dp[i-1][pastActivity] + vals[i][activity])

print(max(dp[-1]))
