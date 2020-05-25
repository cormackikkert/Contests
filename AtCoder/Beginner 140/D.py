N, K = map(int, input().split())
S = input()
last = None
total = 0
for c in S:
    if c != last:
        total += 1
    last = c
print(N-max(1, total - 2 * K))
