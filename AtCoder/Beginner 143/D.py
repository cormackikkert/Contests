N = int(input())
sticks = sorted(list(map(int, input().split())))

def calc(N, sticks):
    sums = [0 for i in range(1002)]
    for stick in sticks:
        for i in range(stick + 1):
            sums[i] += 1
    total = 0
    for i in range(N):
        for j in range(N):
            if i == j: continue
            a, b = sticks[i], sticks[j]

            lo = abs(b-a)+1
            hi = min(a+b, 1001)
            
            val = sums[lo] - sums[hi] - (lo <= a) - (lo <= b)
            if val <= 0: continue
            total += val
    return total // 6


print(calc(N, sticks))
