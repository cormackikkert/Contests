S = input()
best = 0
for i in range(len(S)):
    for j in range(i+1, len(S)+1):
        s = S[i:j]
        c = 0
        for k in range(len(S)):
            if S[k:].startswith(s): c += 1
        if c >= 2: 
            best = max(best, len(s))
print(best)