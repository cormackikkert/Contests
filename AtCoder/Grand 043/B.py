def solve(arr):
    while len(arr) >= 2:
        arr = [abs(arr[i+1] - arr[i]) for i in range(len(arr)-1)]
    return arr[0]

def solveSmart(arr): 
    N = len(arr)
    if N <= 7:
        return solve(arr)
    S = 0
    for i in range(N//2):
        if i == 0 or (i == 2 and N % 2 == 0) or ((N - 1) % (i + 2) >= i):
            S += arr[i]
            S += arr[N-1-i]
    return S % 2

def solveNormal(arr):
    while len(arr) >= 2:
        arr = [abs(arr[i+1] - arr[i]) for i in range(len(arr) - 1)]
        bad = False
        for i in range(len(arr)):
            if arr[i] != 2: continue
            if i - 1 >= 0 and arr[i-1] == 0: bad = True
            if i + 1 < len(arr) and arr[i+1] == 0: bad = True
        if not bad:
            for i in range(len(arr)):
                if arr[i] == 2: arr[i] = 0
            return solveSmart(arr)

N = int(input())
arr = list(map(int, input()))
print(solveNormal(arr))
