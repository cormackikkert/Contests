N, M = map(int, input().split())

costs = [None for i in range(M)]
opens = [None for i in range(M)]

for i in range(M):
    costs[i] = list(map(int,input().split()))[0]
    o = list(map(int, input().split()))
    x = pow(2, 12)-1
    for item in o:
        x &= ~(1 << (item-1))
    opens[i] = x

dp = [-1 for i in range(pow(2, 12))]
dp[0] = 0

def recurse(required):
    if dp[required] != -1:
        return dp[required]

    totalCost = float('inf')
    for i in range(M):
        c = required & opens[i]
        if c == required:continue
        
        totalCost = min(totalCost, costs[i] + recurse(c))

    dp[required] = totalCost
    return totalCost


val = recurse(pow(2, N)-1)
if val == float('inf'):
    print(-1)
else:
    print(val)
