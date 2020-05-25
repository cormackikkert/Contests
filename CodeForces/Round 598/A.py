q = int(input())
for i in range(q):
    a, b, n, s = map(int, input().split())

    t = min(s // n, a)
    if s - t * n <= b:
        print("YES")
    else:
        print("NO")
