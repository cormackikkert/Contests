import re

n = int(input())

elems = dict()

for _ in range(n):
  elem, mass = input().split()
  elems[elem] = int(mass.replace(".",""))

compound = re.findall('[A-Z][a-z0-9]*',input())

ans = 0
for part in compound:
  x = re.findall('\d+|\D+', part)
  elem = x[0]
  num = 1 if len(x) == 1 else int(x[1])
  ans += elems[elem] * num

print(ans / 100.0)
