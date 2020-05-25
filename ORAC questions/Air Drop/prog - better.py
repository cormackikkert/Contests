with open("dropin.txt") as file:
    N = int(file.readline())
    drops = list(map(int, file.read().split()))

def getIndex(drop, lo, hi):
    if lo <= hi:
        mid = (lo + hi) // 2
        if drops[mid] == drop:
            return mid
        elif drops[mid] < drop:
            return getIndex(drop, mid+1, hi)
        else:
            return getIndex(drop, lo, mid-1)
    return -1
    
dp = [[0 for i in range(1000)] for j in range(1000)]

for i, item in enumerate(drops):
    for j, previous in enumerate(drops[:i+1]):
        jump = item - previous

        last = getIndex(previous - jump, 0, N-1)
        
        if last != -1:
            dp[i][j] = 1 + dp[j][last]
        else:
            dp[i][j] = 1


with open("dropout.txt", "w") as file:
    file.write(str(max([max(row) for row in dp]) + 1))

