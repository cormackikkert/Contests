a, b = map(int, input().split())

t = 1
if (b - a) > 10:
    t = 0
else:
    for i in range(a + 1, b + 1):
        t *= (i % 10)
print(t % 10)
