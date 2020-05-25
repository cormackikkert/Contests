import sys
sys.setrecursionlimit(1000000)

N = int(input())
edges = [[] for i in range(N)]
MOD = int(pow(10, 9) + 7)

for i in range(N-1):
    x, y = map(int, input().split())
    edges[x-1].append(y - 1)
    edges[y-1].append(x - 1)

# dp[i][j] - no of ways of painting tree rooted at i, with parent coloured j
dp = [[-1, -1] for i in range(N)]
def recurse(vertex, parent, parentColour):
    if dp[vertex][parentColour] != -1:
        return dp[vertex][parentColour]

    bways = 1
    wways = 1
    
    for n in edges[vertex]:
        if n == parent: continue
        bways *= recurse(n, vertex, False)
        if not parentColour:
            wways *= recurse(n, vertex, True)

    ways = bways if parentColour else bways + wways
    ways %= MOD
    dp[vertex][parentColour] = ways
    return ways

recurse(0, None, False)

print(dp[0][False])
