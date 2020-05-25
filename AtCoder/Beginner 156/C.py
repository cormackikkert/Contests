N = int(input())
XS = list(map(int, input().split()))

best = float('inf')
for c in range(0, 101):
    cost = 0
    for x in XS:
        cost += (x - c) * (x - c)
    best = min(cost, best)
print(best)