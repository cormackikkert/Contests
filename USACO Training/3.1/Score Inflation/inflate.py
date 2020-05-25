"""
TASK: inflate
ID: cormac.1
LANG: PYTHON3
"""

with open("inflate.in") as file:
    M, N = map(int, file.readline().split())

    # (points, minutes)
    classes = [tuple(map(int, file.readline().split())) for i in range(N)]

classes.sort(key=lambda n: n[1])

dp = [0 for i in range(M+1)]

for t in range(1, M+1):
    dp[t] = dp[t-1]
    for cls in classes:
        if cls[1] <= t:
            dp[t] = max(dp[t], dp[t-cls[1]] + cls[0])
        else:
            break

with open("inflate.out", "w") as file:
    file.write(str(dp[M]) + "\n")
        
