with open("alienin.txt") as file:
    N, W = map(int, file.readline().split())
    spec = list(map(int, [file.readline() for i in range(N)]))

lo = 0
hi = 0

max_val = 0
tk = 1

while True:
    while hi < N and spec[hi] < spec[lo] + W:
        hi += 1
        tk += 1
    hi -= 1
    tk -= 1

    if tk > max_val:
        max_val = tk

    if hi >= N-1:
        break
    
    lo += 1
    tk -= 1


with open("alienout.txt", "w") as file:
    file.write(str(max_val))

                  
