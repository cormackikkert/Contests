with open("hirein.txt") as file:
    N = int(file.readline())
    monks = sorted([int(file.readline()) for i in range(N)])
    S = int(file.readline())
    sJobs = sorted([int(file.readline()) for i in range(S)])
    M = int(file.readline())
    mJobs = sorted([int(file.readline()) for i in range(M)], reverse=True)

total = 0
lo, hi = 0, N-1
curLo = curHi = 0
while lo <= hi:
    if curLo < S:
        if monks[lo] <= sJobs[curLo]:
            lo += 1
            total += 1
        curLo += 1
    if lo > hi: break
    if curHi < M:
        if monks[hi] >= mJobs[curHi]:
            hi -= 1
            total += 1
        curHi += 1
    if curLo == S and curHi == M: break

with open("hireout.txt", "w") as file:
    file.write(str(total))
