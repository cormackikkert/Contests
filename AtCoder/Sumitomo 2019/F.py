
T1, T2 = map(int, input().split())
A1, A2 = map(int, input().split())
B1, B2 = map(int, input().split())

A1 *= T1
B1 *= T1
A2 *= T2
B2 *= T2

if A1 > B1:
    A1, A2, B1, B2 = B1, B2, A1, A2

if A1 + A2 == B1 + B2:
    print('infinity')
elif A1 + A2 < B1 + B2 or A1 == A2:
    print(0)
else:
    def check(c):
        return c * (A1 + A2) + A1 >= c * (B1 + B2) + B1
    
    l = 0
    h = B1 + B2
    while l < h:
        mid = l + (h - l) // 2
        if check(mid):
            h = mid
        else:
            l = mid + 1

    
    print(2*l-(l * (A1 + A2) + A1 != l * (B1 + B2) + B1))
