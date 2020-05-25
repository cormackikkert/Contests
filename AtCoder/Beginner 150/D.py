N, M = map(int, input().split())
seqs = set()
for a in list(map(int, input().split())):
    seqs.add((a, a//2))
seqs = list(seqs)
N = len(seqs)
def egcd(a, b):
    x,y, u,v = 0,1, 1,0
    while a != 0:
        q, r = b//a, b%a
        m, n = x-u*q, y-v*q
        b,a, x,y, u,v = a,r, u,v, m,n
    gcd = b
    return gcd, x, y

s1 = seqs[0]
for i in range(1, N):
    s2 = seqs[1]
    if (s2 == s1): continue

    a1, a2 = s1
    b1, b2 = s2

    g, x0, y0 = egcd(a1, -b1)

    # print(g, x0, y0)

    if (b2 - a2) % g != 0:
        print(0)
        quit()

    a1 *= (b2 - a2) // g
    b1 *= (b2 - a2) // g
    x0 = x0 % (b1 // g)

    s1 = [a2 + a1 * x0, a1 * b1 // g]

#print(M, s1)
print((M - s1[0]) // s1[1] + 1)
