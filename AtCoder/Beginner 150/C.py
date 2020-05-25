N = int(input())
P1 = tuple(map(int, input().split()))
P2 = tuple(map(int, input().split()))

import itertools
a = 0
b = 0
for perm in itertools.permutations([i+1 for i in range(N)]):
    if perm <= P1:
        a += 1
    if perm <= P2:
        b += 1
print(abs(b - a))