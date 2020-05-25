P, T = map(int, input().split())
data = [list(map(int, input().split())) for i in range(P)]

data = sorted(data, key = lambda n: sum(n))

for item in data:
    if sum(item) == 0:
        print("YES")
        break
else:
    for i in range(1, P):
        td = [0 for i in range(T)]
        done = []
        for j in range(i):
            lc = td.index(min(td))
            for prob in data:
                if prob not in done:
                    prob[lc] > 0
                    for k in range(len(td)):
                        td[k] += prob[k]
                    done.append(prob)
        for item in td:
            if item > i / 2:
                break
        else:
            print("YES")
            break
    else:
        print("NO")
    
