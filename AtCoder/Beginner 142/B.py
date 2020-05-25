N, K = map(int, input().split())
heights = list(map(int, input().split()))

total = 0
for h in heights:
    if h >= K: total+=1

print(total)
