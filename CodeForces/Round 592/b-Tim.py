t = int(input())

results = []
for _ in range(t):
    n = int(input())
    stairs = input()
    best = n
    left1 = -1
    right1 = -1
    for i in range(n):
        if stairs[i] == "1":
            if left1 == -1:
                left1 = i
            right1 = i
    if right1 != -1:
        best = n+1
        best = max(best, 2*(n-left1))
    if left1 != -1:
        best = max(best, 2*(right1+1))
    results.append(best)

for i in results:
    print(i)
