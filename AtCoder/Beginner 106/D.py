N, M, Q = map(int, input().split())
tracks = [[] for i in range(N)]
for i in range(M):
    L, R = map(int, input().split())
    tracks[L-1].append(R-1)
    
for track in tracks: track.sort()

ans = [[None for j in range(N)] for i in range(N)]
for L in range(N):
    cur = 0
    tot = 0
    for R in range(L, N):
        while cur < len(tracks[L]) and tracks[L][cur] <= R:
            cur += 1
            tot += 1
        ans[L][R] = tot

dp =[[None for i in range(N)] for j in range(N)]
for i in range(Q):
    p, q = map(int, input().split())
    if dp[p-1][q-1] == None:
        dp[p-1][q-1] = sum(ans[i][q-1] for i in range(p-1, q))
    print(dp[p-1][q-1])
    
