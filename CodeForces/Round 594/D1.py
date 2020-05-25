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

def calc(string):
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

if even(string):
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

    print(highest)
    print(a+1, b+1)
else:
    print(0)
    print(1, 1)
        
