h1, a1, c1 = map(int, input().split())
h2, a2 = map(int, input().split())

data = []
while h2 > 0:
    # Attack
    if h1 > a2: #or a1 >= h2:
        h2 -= a1
        data.append("STRIKE")
    # Heal
    else:
        h1 += c1
        data.append("HEAL")
    h1 -= a2

print(len(data))
for item in data:
    print(item)
