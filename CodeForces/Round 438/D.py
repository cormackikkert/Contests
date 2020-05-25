n = int(input())
strings = [input() for i in range(n)]

# (0's, 1's)
data = []
for string in strings:
    l0 = string.lstrip('0')
    l1 = string.lstrip('1')
    r0 = string.rstrip('0')
    r1 = string.rstrip('1')
    l = (len(string) - len(l0), len(string) - len(l1))
    r = (len(string) - len(r0), len(string) - len(r1))
    mid = string[max(l):-max(r)]
    f0 = -1
    f1 = -1
    for k in range(1, len(mid)):
        if '0' * k not in mid:
            if f0 == -1:
                f0 = k - 1
        if '1' * k not in mid:
            if f1 == -1:
                f1 = k - 1
        if f0 != -1 and f1 != -1:
            break
    m = (f0 if f0 != -1 else len(mid), f1 if f1 != -1 else len(mid))
    data.append((l, m, r))

m = int(input())
for i in range(m):
    a, b = map(int, input().split())
    l = data[a-1][0]
    r = data[b-1][2]
    midl = data[a-1][2]
    midr = data[b-1][0]
    mscores = [data[a-1][1], data[b-1][1]]
    if midl[0] > midl[1] and midr[0] > midr[1]:
        mscores.append((midl[0] + midr[0], 0))
    if midl[1] > midl[0] and midr[1] > midr[0]:
        mscores.append((0, midl[1] + midr[1]))
    
    m0 = max(max(mscores, key=lambda n:n[0])[0], data[a-1][2][0], data[b-1][0][0])
    m1 = max(max(mscores, key=lambda n:n[1])[1], data[a-1][2][1], data[b-1][0][1])
    data.append((l, (m0, m1), r))
    k = min(max(l[0], m0, r[0]), max(l[1], m1, r[1]))
    print(k)
