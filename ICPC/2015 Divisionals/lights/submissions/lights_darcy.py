n,d = [int(x) for x in input().split()]

ans = "YES"
for _ in range(n):
    x,a,g,r = [int(x) for x in input().split()]
    if x < a or (x-a) % (g+r) > g:
        ans = "NO"

print(ans)
