N = int(input())
H = list(map(int, input().split()))
B = list(map(int, input().split()))

dp = [0 for i in range(N)]
interesting = set()

for i in range(N):
    
    best = None
    for item in interesting:
        if H[item] < H[i] and ((best == None) or dp[item] > dp[best]):
            best = item
    print(i, interesting, best)
    if best == None:
        dp[i] = B[i]
    else:
        interesting.remove(best)
        dp[i] = B[i] + dp[best]
    interesting.add(i)
print(max(dp))
    
