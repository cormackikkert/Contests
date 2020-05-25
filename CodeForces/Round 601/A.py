T = int(input())
for i in range(T):
    a, b = map(int, input().split())
    n = abs(b - a)
    total = 0
    total += n // 5
    n -= 5 * (n // 5)
    total += n // 2
    n -= 2 * (n // 2)
    total += n
    print(total)
