with open("lscin.txt") as file:
    N, L = map(int, file.readline().split())
    shops = [0] + list(map(int, file.readline().split()))
    pam = list(map(int, file.readline().split()))
    pamR = list(reversed(pam))

lo, hi = 1, L

for far, close in zip(pamR, pamR[1:]):
    fpos = shops[far]
    cpos = shops[close]
    dist = abs(fpos - cpos) - 1
    if cpos < fpos:
        hi = min(hi, fpos - (dist // 2 + 1))
    else:
        lo = max(lo, fpos + (dist // 2 + 1))

with open("lscout.txt", "w") as file:
    if lo <= hi:
        file.write(str(lo) + '\n')
    else:
        file.write("-1\n")
