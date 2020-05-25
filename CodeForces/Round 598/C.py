n, m, d = map(int, input().split())
planks = list(map(int, input().split()))

onRight = n + 1
total = sum(planks)

cur = 0

data = [0 for i in range(n + 2)]

for j, plank in enumerate(planks):

    dist = onRight - total + d if total + d > onRight else d

    if dist < 0:
        break

    print(cur + dist)
    cur += dist

    
    for i in range(plank):
        data[cur + i] = j + 1

    cur += plank - 1
    
    onRight = n - cur
    total -= plank
else:
    print("YES")
    print(" ".join(map(str, data[1:-1])))
    quit()
print("NO")
    
