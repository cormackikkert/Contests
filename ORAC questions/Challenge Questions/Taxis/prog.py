with open("taxiin.txt") as file:
    S = int(file.readline())
    N = int(file.readline())
    cost = []
    peop = []
    for i in range(N):
        a, b = map(int, file.readline().split())
        cost.append(a)
        peop.append(b)
        cost.append(a)
        peop.append(b - 1)
        
dp = list(range(S+1))

dp[0] = 0

for i in range(1, S+1):
    dp[i] = min(cost[j] + dp[i - peop[j]] for j in range(2 * N))
    
with open("taxiout.txt", "w") as file:
    file.write(str(dp[-1]))
