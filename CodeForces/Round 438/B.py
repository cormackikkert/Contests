h, m, s, t1, t2 = map(int, input().split())

m = m/60 * 12
s = s/60 * 12

def between(a, b, c):
    if a < b:
        if a < c and  c < b:
            return True
        else:
            return False
    else:
        if b < c and  c < a:
            return False
        else:
            return True

if not between(t1, t2, h) and not between(t1, t2, m) and not between(t1, t2, s):
    print("YES")
else:
    if not between(t2, t1, h) and not between(t2, t1, m) and not between(t2, t1, s):
        print("YES")
    else:
        print("NO")
