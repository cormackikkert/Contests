t = int(input())
for i in range(t):
    n = int(input())
    c = 0
    for d in range(1, 10):
        p = d
        while True:
            if p<=n: c += 1
            else: break
            p *= 10; p += d;
    print(c)
