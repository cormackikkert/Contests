a, b = input().split()
c, d = map(int, input().split())
e = input()

if e == a: c-= 1
elif e == b: d -= 1

print(c, d)