S = input()
K = int(input())

import random
import string


def count(string):
    total = 0
    i = 1
    while i < len(string):
        if string[i-1] == string[i]:
            total += 1
            i += 1
        i += 1
    return total

if S == len(S) * S[0]:
    res = (K * len(S)) // 2      
elif S[0] == S[-1]:
    new = S.strip(S[0])
    start = len(S) - len(S.lstrip(S[0]))
    end = len(S) - len(S.rstrip(S[0]))
    res = start // 2 + end // 2 + K * count(new) + (K - 1) * ((start + end) // 2)
else:
    res = K * count(S)

print(res)
