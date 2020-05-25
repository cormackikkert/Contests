S = input()
consecNum = [1]
consecType = [S[0]]
last = None
for c in range(1, len(S)-1):
    if last != S[c]:
        last = S[c]
        consecNum.append(0)
        consecType.append(S[c])
    consecNum[-1] += 1
consecNum.append(1)
consecType.append(S[-1])

canBeRemoved = [False for i in range(len(consecNum))]
for i in range(1, len(consecNum) - 1):
    canBeRemoved[i] = consecType[i - 1] != consecType[i + 1]
    
total = 0
for i in range(1, len(consecNum) - 1):
    if consecType[i-1] == consecType[i+1] and (canBeRemoved[i - 1] + canBeRemoved[i+1]) % 2 == 0:
        total += consecNum[i] - 1
    else:
        total += consecNum[i]

print("Second" if total % 2 == 0 else "First")
