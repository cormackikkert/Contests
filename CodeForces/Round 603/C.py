s = set()
for i in range(1,101):
    s.add(100//i)
print(sorted(s))    
"""T = int(input())

for i in range(T):
    N = int(input())

    res = []
    
    def check(a):
        if a == N or a== 1: return True
        return int(N/a) != int(N/(a+1))
    
    X = N
    while True:
        if check(X):
            res.append(X)

        if X > 2:
            X = X // 2 + 1
        elif X == 2:
            X = 1
        else:
            break
    res.append(0)
    print(list(reversed(res)))
    # print(" ".join(map(str, reversed([x for x in res]))))
    """
        
    
    
