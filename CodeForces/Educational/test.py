def gcd(a, b):
    while a > 0:
        a, b = b % a, a
    return b

def tim(r, b, k):
    if r < b: r, b = b, r
    g= gcd(r,b);
    r=r//g;
    b=b//g;
    return (r-2)/b+1 >= k

def brute_force(r, b, k):
    lcm = (r * b) // gcd(r, b)
    col = [""]
    for a in range(1, lcm+2):
        if a % r == 0 and a % b == 0:
            new = []
            for c in col:
                new.append(c + "G")
                new.append(c + "R")
            col = new
        elif a % r == 0:
            new = []
            for c in col: new.append(c + "R")
            col = new
        elif a % b == 0:
            new = []
            for c in col: new.append(c + "G")
            col = new
            
    return all(("G" * k in c) or ("R" * k in c) or ("B" * k in c) for c in col)


for a in range(1, 50):
    for b in range(1, 50):
        for k in range(2, min(100,a*b)):
            if tim(a, b, k) != brute_force(a, b, k):
                print("REE", a, b, k)
