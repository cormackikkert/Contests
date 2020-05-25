N = int(input())
BS = list(map(int, input().split()))
AS = [float('inf') for i in range(N)]

for i in range(N-1):
    AS[i] = min(AS[i], BS[i])
    AS[i+1] = max(AS[i], BS[i])

print(sum(AS))
