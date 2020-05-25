with open("farmin.txt") as file:
    N = int(file.readline())
    plots = list(map(int, file.readline().split()))

lo, hi = 0, N - 1
total_lo = plots[lo]
total_hi = plots[hi]

counter = 0

while lo < hi:
    while total_lo != total_hi:
        if total_lo < total_hi:
            lo += 1
            total_lo += plots[lo]
        else:
            hi -= 1
            total_hi += plots[hi]
    total_lo, total_hi = 0, 0
    print(lo, hi)
    lo += 1
    hi -= 1
    counter += 1

print(counter)
input()
