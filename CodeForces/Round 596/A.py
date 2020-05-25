a, b = map(int, input().split())
if b - a == 1 or (a==9 and b == 1):
    print(a*10 + 9, a*10 + 10)
elif b - a == 0:
    print(a * 10, a * 10 + 1)
else:
    print(-1)
