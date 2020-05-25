N = int(input())
seqs = []
for i in range(N):
    vals = list(map(int, input().split()))[1:]
    seqs.append(vals)

works = 0
los = []
his = []

ans = 0

for seq in seqs:
    if sorted(seq, reverse=True) != seq: works += 1
    else:
        lo = min(seq)
        hi = max(seq)

        los.append(lo)
        his.append(hi)

los = sorted(los)
his = sorted(his)

for lo, hi in zip(los, his):
    l = 0
    h = len(his)-1

    
    while l < h:
        m = (l + h) // 2
        # print(l, m, h)
        if his[m] > lo:
            h = m
        else:
            l = m + 1

    

    if his[l] > lo:
        print("AS LOW", lo, l, len(los) - l)
        ans += (len(los) - l)

    l = 0
    h = len(los)-1
    while l < h:
        m = (l + h + 1) // 2
        if los[m] < hi:
            l = m
        else:
            h = m - 1
    if los[l] < hi:
        print("AS HI", hi, l + 1)
        ans += l + 1
ans //= 2
print(ans)
ans += 2 * works * N
print(ans)
