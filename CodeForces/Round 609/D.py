N = int(input())
cols = list(map(int, input().split()))
b = 0
w = 0
for i, col in enumerate(cols):
    if i %2 == 0:
        b += col // 2
        w += col - col // 2
    else:
        b += col - col // 2
        w += col // 2
print(min(b, w))
