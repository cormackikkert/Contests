S = input()
T = input()

moves = [[None for i in range(len(T)+1)] for j in range(len(S)+1)]
dp = [[0 for i in range(len(T)+1)] for j in range(len(S)+1)]

# dp[i][j] = longest substring of S[:i] and T[:j]

for i in range(1,len(S)+1):
    for j in range(1,len(T)+1):
        sc = S[i-1]
        tc = T[j-1]

        c = 0

        if dp[i-1][j] > dp[i][j]:
            dp[i][j] = dp[i-1][j]
            c = 1
        if dp[i][j-1] > dp[i][j]:
            dp[i][j] = dp[i][j-1]
            c = 2
        if sc == tc and 1 + dp[i-1][j-1] > dp[i][j]:
            dp[i][j] = 1 + dp[i-1][j-1]
            c = 3
        moves[i][j] = c

s = ""

cur = [len(S), len(T)]
while cur != [0, 0]:
    
    move = moves[cur[0]][cur[1]]
    if move == 3:
        s += S[cur[0]-1]
        cur[0] -= 1
        cur[1] -= 1
    elif move == 2:
        cur[1] -= 1
    elif move == 1:
        cur[0] -= 1
    else:
        break


print(s[::-1])
