hmm = list(map(int, input().split()))

for a in range(27):
    for b in range(a + 2, 27):
        for c in range(b + 2, 27):
            for d in range(c + 2, 27):
                for e in range(d + 2, 27):
                    for f in range(e + 2, 27):
                        for g in range(f + 2, 27):
                            for h in range(g + 2, 27):
                                for i in range(h + 2, 27):
                                    for j in range(i + 2, 27):
                                        for k in range(j + 2, 27):
                                            for l in range(k + 2, 27):
                                                for m in range(l + 2, 27):
                                                    arr = [a, b, c, d, e, f, g, h, i, j, k, l, m]
                                                    bad = False
                                                    for i in range(12):
                                                        if arr[i+1] - arr[i] <= 1:
                                                            bad = True
                                                    if bad: continue

                                                    s = 0
                                                    for i in arr: s += hmm[i]
                                                    if s == 295:
                                                        print(arr)