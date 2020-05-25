for M in range(1, 15):
    for d in range(1, M):
        if M % d == 0: continue
        high = 0
        cur = 0
        for i in range(M):
            cur = (cur + d) % M
            high = max(high, cur)
        if (M != high + 1):
            print(M, d)