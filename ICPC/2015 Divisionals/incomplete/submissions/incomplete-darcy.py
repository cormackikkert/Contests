k, d = [int(x) for x in input().split()]

val = 1
while k*(2**val - 1) <= d:
  val += 1

print(val-1)
