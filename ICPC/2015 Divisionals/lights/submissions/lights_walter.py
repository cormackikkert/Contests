import sys

sys.stdin.readline()
result = 'YES'
for line in sys.stdin:
  x, a, b, c = list(map(int, line.split()))
  xm = x % (b + c)
  am = a % (b + c)
  abm = (a + b) % (b + c)
  if not (a <= x and (am <= xm <= abm or abm < am <= xm or xm <= abm < am)):
    result = 'NO'
    break
print(result)
