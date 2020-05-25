t = int(input())
for i in range(t):
    n = int(input())
    s = list(map(int, input().split()))

    high = {}
    for i in range(n):
        item = s[i]
        c = 0
        while item % 2 == 0:
            item //= 2
            c += 1
        if item not in high:
            high[item] = c
        else:
            high[item] = max(c, high[item])
    tally = 0
    for n in high:
        tally += high[n]
    print(tally)
