with open("frogin.txt") as file:
     N, K = map(int, file.readline().split())
     nums = [int(file.readline()) for i in range(N-1)]

diff = [num - K for num in nums]
lSums = [None for _ in nums]
rSums = [None for _ in nums]

rDiff = 0
for i,l in enumerate(diff):
    rDiff += l
    lSums[i] = rDiff
rDiff = 0
for i,r in enumerate(reversed(diff)):
    rDiff += r
    rSums[i] = rDiff

indexes = list(range(N-1))
indexes.sort(key=lambda n:diff[n], reverse=True)
t = 0
for i in indexes:
    lt = lSums[i-1] if i-1>= 0 else 0
    rt = rSums[i+1] if i+1<N-1 else 0
    if abs(lt + diff[i]) < abs(rt + diff[i]):
        t += abs(diff[i])
        if i - 1 >= 0: diff[i - 1] += diff[i]
    else:
        t += abs(diff[i])
        if i+1<N-1: diff[i + 1] += diff[i]
print t    
open("frogout.txt", "w").write(`t`)
