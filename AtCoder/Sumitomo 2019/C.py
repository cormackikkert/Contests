X= 1000001
cando = [False for i in range(X+1)]
cando[0] = True
for i in range(X+1):
    if not cando[i]: continue
    for item in [100, 101, 102, 103, 104, 105]:
        if i + item <= X:
            cando[i+item] = True

def f(n):
    if (n<100):
        return 0
    div100 = int(n/100)
    if (n>div100*105):
        return 0
    else:
        return 1

def g(n):
    res=int((n%100)/5)
    n -= 105*res
    if n == 0 or n >= 100:
        return 1
    else:
        return 0

def h(n):
    return cando[n]

for i in range(1000001):
    if f(i) != g(i):
        print(i)
