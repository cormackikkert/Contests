import sys
sys.setrecursionlimit(10000000)

N = int(input())
dp = {}
def recurse(n, ind, carry):
    if n < 10:
        return min(n, 1 + 10 - n)

    if n in dp: return dp[n]
    
    ans = float('inf')
    ans = min(ans, n % 10 + recurse(n // 10))
    ans = min(ans, 10 - (n % 10) + recurse(n // 10 + 1))
    
    dp[n] = ans
    return ans


print(recurse(N))
print(len(dp), len(str(N)))