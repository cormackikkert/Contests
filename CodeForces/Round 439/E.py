N, M, Q = map(int, input().split())

bars = []

for i in range(Q):
    t, r1, c1, r2, c2 = map(int, input().split())
    if t == 1:
        bars.append((c1, r1, c2, r2))
    elif t == 2:
        bars.remove((c1, r1, c2, r2))
    elif t == 3:
        bars.sort(key = lambda n:n[0])
        for x1, y1, x2, y2 in bars:
            if x1 > c1 and x1 > c2:
                break
            inter1 = (x1 <= c1 <= x2 and y1 <= r1 <= y2)
            inter2 = (x1 <= c2 <= x2 and y1 <= r2 <= y2)
            if inter1 and inter2:
                pass
            elif inter1 or inter2:
                print("No")
                break
        else:
            print("Yes")
