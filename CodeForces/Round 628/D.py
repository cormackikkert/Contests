
u, v = map(int, input().split())
if u == 0 and v == 0:
    print(0)
elif u == v:
    print(1)
    print(u)
elif (v - u < 2 or (v - u) % 2 == 1):
    print(-1)
else:
    ex = (v - u) // 2
    if (ex & u == 0):
        print(2)
        print(ex | u, ex)
    else:
        print(3)
        print(u, ex, ex)