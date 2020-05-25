s = 1
def f(n):
    s = 1
    while n > 1:
        s *= n; n -= 2
    return len(str(s)) - len(str(s).rstrip('0'))

for item in [10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250]:
    print(item, f(item))
