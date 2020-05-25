import sys
sys.setrecursionlimit(10000)

N = int(input())
dishes = list(map(int, input().split()))

count = [0, 0, 0]
for item in dishes:
    count[3-item] += 1
    
dp = {}

dp = [[[None for i in range(301)] for j in range(301)] for k in range(301)]

dp[0][0][0] = 0

def recurse(a, b, c):
    if dp[a][b][c] != None:
        return dp[a][b][c]

    expected = 0
    
    if a != 0:
        expected += a * recurse(a-1, b+1, c)
    if b != 0:
        expected += b * recurse(a, b-1, c+1)
    if c != 0:
        expected += c * recurse(a, b, c-1)

    expected /= a + b + c
    
    dp[a][b][c] = (N/(a+b+c)) + expected
    return dp[a][b][c]

print(recurse(count[0], count[1], count[2]))
