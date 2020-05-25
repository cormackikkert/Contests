N = int(input())
'''attempts = [int(input()) for i in range(N)]
high = max(attempts)
result = [False for i in range(high + 1)]
def dfs(n):
    if n > 100:
        return
    result[n] = True
    dfs(n + 3)
    dfs(n + 7)

dfs(0)
print(result)'''

data = [False, False, False, True, False, False, True, True, False, True, True, False, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True, True]
for i in range(N):
    print("YES" if data[int(input())] else "NO")
