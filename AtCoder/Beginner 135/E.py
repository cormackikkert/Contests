K = int(input())
X, Y = map(int, input().split())
X, Y = abs(X), abs(Y)
CX, CY = 0, 0

if K % 2 == 0 and (X + Y) % 2 != 0:
    print(-1)

points = []
while True:
    if CX != X:
        CX = min(X, CX + K)
        CY += max(0, K - (CX - X))
    else:
        
