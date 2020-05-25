import random

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a%b)

for i in range(3, 23):
    while True:
        ans = []
        for j in range(i): ans.append(random.randint(2, 1000))
        if len(ans) != len(set(ans)): continue
        g = ans[0]
        for j in ans: g = gcd(g, j)
        if g != 1: continue
        total = 0
        for j in ans: total += j
        bad = False
        for j in ans:
            if gcd(total - j, j) == 1: bad = True
        if bad: continue
        res = str(ans).replace("[", "{").replace("]","}")
        print(f"if (N == {i}) ans = {res}")
        break
total = []
for i in range(1, 31):
    if i % 2 == 0 or i % 3 == 0 or i % 5 == 0:
        total += [i]

print(total)