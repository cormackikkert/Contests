itemNum = int(input())
items = [list(map(int, input().split())) for i in range(itemNum)]

items = sorted(items, key=lambda a:a[1])

T = sum(item[0] + item[1] for item in items)

K = [[0 for i in range(T + 1)] for i in range(len(items) + 1)]

for i in range(len(items) + 1):
    for t in range(T + 1):
        if i == 0 or t == 0:
            K[i][t] = 0

        # Not enough time
        elif t + items[i-1][0] >= items[i-1][1] or (t - items[i-1][0] < 0):
            K[i][t] = K[i-1][t]
        else:
            K[i][t] = max(items[i-1][2] + K[i-1][t-items[i-1][0]], K[i-1][t])
print(K[:-1])
