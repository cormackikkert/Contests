q = int(input())

def composite(limit):
    a = [True] * limit
    a[0] = a[1] = False

    comp = []
    for i, isprime in enumerate(a):
        if isprime:
            for n in range(i*i, limit, i):
                if n not in comp:
                    comp.append(n)
                a[n] = False
    return sorted(comp)

items = []
for i in range(q):
    items.append(int(input()))
    
n = max(items)
data = composite(n+1)

dp = [0]
for i in range(1, n+1):
    if i not in data:
        dp.append(float('-inf'))
        continue
    val = 0
    for comp in data:
        if i - comp >= 0:
            val = max(val, 1 + dp[i - comp])
        else:
            break
    dp.append(val)

print(dp)

for num in items:
    if num not in data:
        print(-1)
    else:
        print(dp[num])
    
    
