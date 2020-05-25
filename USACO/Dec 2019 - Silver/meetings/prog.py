with open("meetings.in") as file:
    N, L = map(int, file.readline().split())
    xs = [0 for i in range(N)]
    ds = [0 for i in range(N)]
    for i in range(N):
        w, x, d = map(int, file.readline().split())
        xs[i] = x
        ds[i] = d

vals = sorted(range(N), key=lambda x: xs[i] if ds[i] == 1 else L - xs[i])
import math
total = 0
for index in range(math.ceil(N/2)): 
    i = vals[i]
    if ds[i] == 1: 
        for cow in range(N):
            if xs[cow] > xs[i] and ds[cow] == -1: total += 1
    if ds[i] == -1:
        for cow in range(N):
            if xs[cow] < xs[i] and ds[cow] == 1: total += 1

with open("meetings.out", "w") as file:
    file.write(str(total))

