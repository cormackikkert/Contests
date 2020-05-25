N, K = map(int, input().split())

authors = [{c : 0 for c in "ABCDEFGHIJKLMNOPQRSTUVWXYZ"} for i in range(N)]
for i in range(N):
    author = input()
    for c in author:
        authors[i][c] = authors[i].get(i, 0) + 1

words = [input() for i in range(K)]

memo = {}
def calcScore(state):
    if state in memo:
        return memo[state]
    total = 0
    
    word, used, index = state

    if index < 0: return 1
    
    for i in range(N):
        if used[i] and authors[i][word[index]] > 0:
            newUsed = list(used)
            newUsed[i] = False
            total += authors[i][word[index]] * calcScore((word, tuple(newUsed), index - 1))
    memo[state] = total
    return total

import time

s = time.time()
for word in words:
    if len(word) != N:
        pass
    else:
        calcScore((word, tuple(True for i in range(N)), N-1))
print(time.time() - s)
