N = int(input())
H = list(map(int, input().split()))
H = list(reversed(H))

hi = 0
s = 0
while s < N:
    h = s
    while h + 1 < N and H[h+1] >= H[h]:
        h += 1
    hi = max(hi, h - s)
    s = h + 1

print(hi)
