N = int(input())
string = list(input())

def even(string):
    a = 0
    b = 0
    for c in string:
        if c == ")": a += 1
        if c == "(": b += 1
    return a == b

def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def calc2(string):
    N = len(string)
    l = 0
    s = 0
    for char in string:
        if char == "(":
            s += 1
        else:
            s -= 1
        l = min(l, s)
    
    if s != 0: return 0

    t = 0

    for i in range(N):
        c = string[i]
        if c == "(":
            s += 1
            if s - l <= 1:
                t += 1
        else:
            s -= 1
    return t

def stupid(string):
    highest = calc(string)
    a = b = 0
    for i in range(N):
        for j in range(i + 1, N):
            if string[i] == string[j]: continue
            swap(string, i, j)
            total = calc(string)
            if total > highest:
                highest = total
                a, b = i, j
            swap(string, i, j)
    return highest

def calc(string):
    string = list(string)
    
    def getLow(string):
        s = 0
        l = 0
        for char in string:
            if char == "(": s += 1
            elif char == ")": s -= 1
            l = min(s, l)
        return l
    
    low = getLow(string)

    s = 0

    best = None
    bestCount = -1
    curCount = -1
    start = None
    for i, char in enumerate(string):
        if char == "(": s += 1
        elif char == ")": s -= 1
        
        if s == low + 1:
            # Start or end segment
            if start == None:
                curCount = 0
                start = i
            else:
                if curCount > bestCount:
                    bestCount = curCount
                    best = (start, i)
                start = None
        if s == low + 2:
            curCount += 1
    swap(string, best[0], best[1])
    print(calc2(string))
    print("".join(string))
    swap(string, best[0], best[1])
    print(bestCount, best)
