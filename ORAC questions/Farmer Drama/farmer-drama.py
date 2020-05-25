with open("farmin.txt") as file:
    plots = int(file.readline())
    sizes = list(map(int, file.readline().split()))

lo,hi = 0, plots - 1
count = 0

while lo < hi:
    le, ri = sizes[lo], sizes[hi]
    while lo < hi and le != ri:
        if le < ri:
            lo += 1
            le += sizes[lo]
        elif ri < le:
            hi -= 1
            ri += sizes[hi]
        count += 1
    lo += 1
    hi -= 1

with open("farmout.txt", "w") as file:
    file.write(str(count))
