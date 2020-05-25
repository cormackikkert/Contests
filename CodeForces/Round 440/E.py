p = int(input())
points = []
for i in range(p):
    points.append(list(map(int, input().split())))

t = 3 * (len(points) ** 2 - 1)

px = {p[0] for p in points}
py = {p[1] for p in points}

for x in px:
    rest = sum(1 for p in points if p[0] == x)
    if rest < p:
        t -= 3 * (rest ** 2 - 1)

for y in py:
    rest = sum(1 for p in points if p[1] == y)
    if rest < p:
        t -= 3 * (rest ** 2 - 1)

print(t)
