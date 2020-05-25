N = int(input())
s1 = list(input())
s2 = list(input())

total = 0
swaps = []

isPossible = True

lastGood = 0
while True:
    for i in range(lastGood, N):
        if s1[i] != s2[i]:
            break
    else:
        break
    
    # Look for duplicate
    foundNice = False
    for j in range(i + 1, N):
        if s1[i] == s1[j] and s2[i] == s2[j]:
            foundNice = True
            break
    
    if foundNice:
        swaps.append((i+1, j+1))
        s1[i], s2[j] = s2[j], s1[i]
    else:
        for j in range(i + 1, N):
            if s1[j] != s2[j]:
                break
        else:
            print(-1)
            isPossible = False
            break
        
        swaps.append((i+1, i+1))
        swaps.append((i+1, j+1))
        s2[i], s2[j] = s2[j], s2[i]
    total += 1
    lastGood = i

if isPossible:
    print(len(swaps))
    for p1, p2 in swaps:
        print(p1, p2)
