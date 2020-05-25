N = 8
nums = [i for i in range(N)] * 2

import itertools

allEl = set()
for perm in itertools.permutations(nums):
    done = set()
    for i in range(2*N):
        for j in range(i + 1, 2 * N):
            if perm[i] == perm[j]:
                x = 0
                for ind in range(i, j+1): x ^= perm[ind]
                done.add(x)
    if len(done) == 1:
        print(done, [bin(x) for x in perm])
        allEl |= done
    if len(allEl) == N: break
        # print(perm, done)
print(sorted(allEl))