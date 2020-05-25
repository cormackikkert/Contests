with open("dollin.txt") as file:
    N = int(file.readline())
    dolls = list(map(int,file.readlines()))

# Greedy approach
finished = []

while len(finished) < len(dolls):
    parents = {}
    dp = [1]
    for i in range(1, N):
        opts = [j for j in range(i) if dolls[j] > dolls[i] and j in finished]
        if opts:
            high = max(opts, key=lambda n:dp[n])
            parents[i] = high
            dp.append(dp[high] + 1)
        else:
            dp.append(1)
    best = max(range(N), key=lambda n:dp[n])
    while best in parents:
        finished.append(best)
        best = parents[best]
    finished.append(best)
print(dp)
