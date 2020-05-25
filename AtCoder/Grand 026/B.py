T = int(input())

def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

for i in range(T):
    A, B, C, D = map(int, input().split())
    G = gcd(B, D)
    # Find closest to C
    U = A - G * ((A - C) // G)
    if U < B :
        print("No")
    else:
        print("Yes")
