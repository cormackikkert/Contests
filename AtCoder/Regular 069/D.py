N = int(input())
S = input()

isF = [False for i in range(N)]
isT = [False for i in range(N)]

def isSatisfied():
    for i in range(2, N+2):
        different = (S[(i - 1) % N] == "x" and isT[(i - 1) % N]) or (S[(i - 1) % N] == "o" and isF[(i - 1) % N])
        if different:
            isF[i % N] |= not isF[(i-2) % N]
            isT[i % N] |= not isT[(i-2) % N]
        else:
            isF[i % N] |= isF[(i-2) % N]
            isT[i % N] |= isT[(i-2) % N]
    for j in range(2, N+2):
        i = 1-i
        different = (S[(i + 1) % N] == "x" and isT[(i + 1) % N]) or (S[(i + 1) % N] == "o" and isF[(i + 1) % N])
        if different:
            isF[i % N] |= not isF[(i+2) % N]
            isT[i % N] |= not isT[(i+2) % N]
        else:
            isF[i % N] |= isF[(i+2) % N]
            isT[ i% N] |= isT[(i+2) % N]
    for i in range(N):
        if isF[i] and isT[i]: return False
    return True

for a in [False, True]:
    for b in [False, True]:
        isF = [False for i in range(N)]
        isT = [False for i in range(N)]
        isF[0] = a
        isT[0] = not a
        isF[1] = b
        isT[1] =  not b
        if isSatisfied():
            print("".join(["S" if isT[i] else "W" for i in range(N)]))
            quit()
print(-1)
