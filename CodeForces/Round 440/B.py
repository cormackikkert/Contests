n, k = map(int, input().split())
a = list(map(int, input().split()))

if k >= 3:
    print(max(a))
elif k == 2:
    for j in range(1, len(a)):
        h = max(h, max(min(a[:j]), min(a[j:])))
    print(h)
elif k == 1:
    print(min(a))
