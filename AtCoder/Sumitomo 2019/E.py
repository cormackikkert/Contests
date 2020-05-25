N = int(input())
A = list(map(int, input().split()))
count = [0 for i in range(N)]
count[-1] = 3

MOD = 1000000007
ways = 1
for n in A:
    ways *= count[n-1]
    count[n-1] -= 1
    count[n] += 1
    ways %= MOD
print(ways)
