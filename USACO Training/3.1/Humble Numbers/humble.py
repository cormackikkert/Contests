"""
ID: cormac.1
LANG: PYTHON3
TASK: humble
"""

with open("humble.in") as file:
    N, K = map(int, file.readline().split())
    primes = list(map(int, file.readline().split()))

inSet = [1]

def binarySearch(lo, hi, number, last):
    # print(lo, hi, number, last)
    if lo == hi: return inSet[lo]
    mid = (lo + hi) // 2
    if inSet[mid] * number > last:
        return binarySearch(lo, mid, number, last)
    else:
        return binarySearch(mid + 1, hi, number, last)

for i in range(K):
    inSet.append(min(prime * binarySearch(0, i, prime, inSet[-1]) for prime in primes))

with open("humble.out", "w") as file:
    file.write(str(inSet[-1]) + "\n")

