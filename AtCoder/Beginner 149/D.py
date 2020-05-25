N, K = map(int, input().split())
R, S, P = map(int, input().split())
T = input()

def best(string):
    dp = [[-1, -1, -1] for i in range(len(string))]
    dp[0][0] = R if string[0] == 's' else 0
    dp[0][1] = P if string[0] == 'r' else 0
    dp[0][2] = S if string[0] == 'p' else 0
    for i in range(1, len(string)):
        dp[i][0] = (R if string[i] == 's' else 0) + max(dp[i-1][1], dp[i-1][2])
        dp[i][1] = (P if string[i] == 'r' else 0) + max(dp[i-1][0], dp[i-1][2])
        dp[i][2] = (S if string[i] == 'p' else 0) + max(dp[i-1][0], dp[i-1][1])
    # print(string, dp)
    return max(dp[-1])

strings = []
for i in range(K):strings.append(T[i::K])

print(sum(map(best, strings)))
