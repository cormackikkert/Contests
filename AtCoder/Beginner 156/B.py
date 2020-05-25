N, K = map(int, input().split())

d = 1
C = K
while N >= C:
    d += 1
    C *= K
print(d)