N, M, Q = map(int, input().split())

def gcd(a, b):
    if a == 0: return b
    return gcd(b % a, a)

LCM = N * M / gcd(N, M)

inn = LCM // M
out = LCM // N

for i in range(Q):
    sx, sy, ex, ey = map(int, input().split())

    if sx == 1:
        p1Part = (sy - 1) // inn
    else:
        p1Part = (sy - 1) // out

    if ex == 1:
        p2Part = (ey - 1) // inn
    else:
        p2Part = (ey - 1) // out
    
    print(["NO", "YES"][p1Part == p2Part])
    
