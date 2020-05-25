N = int(input())
lands = []
for i in range(N):
    t = tuple(map(int, input().split()))
    if t[0] > t[1]:
        lands.append(t)
    else:
        lands.append((t[1], t[0]))

lands.sort(reverse=True)
HIGH = max(land[0] * land[1] for land in lands)

highDealt = 0
    
for land in lands:
    HIGH = max(HIGH, land[0] * 2 * min(land[1], highDealt))
    highDealt = max(highDealt, land[1])

if HIGH%2 == 0:
    print(f"{HIGH//2}.0")
else:
    print(f"{HIGH//2}.5")
