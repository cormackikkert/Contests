T = int(input())
for i in range(T):
    N = int(input())
    table = {input() : i for i in range(N)}
    AS = [i for i in range(N)]
    BS = [table[input()] for i in range(N)]
    
    done = [False for i in range(N)]
    vals = []
    lasts = [-1]
    i = 0
    while True:
        highest = i
        if done[i]: continue
        j = i
        done[i] = True
        while True:
            highest = max(highest, AS[j])
            j = BS[AS[j]]
            if j < i:
                while lasts[-1] > j: lasts.pop()
            done[j] = True
            highest = max(highest, j)
            if j == i: break
        vals.append(highest - i + 1)
        lasts.append(highest)
        i = highest + 1
        if i >= N: break
    print(" ".join([str(lasts[i] - lasts[i-1]) for i in range(1, len(lasts))]))


