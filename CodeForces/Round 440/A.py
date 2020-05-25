N, M = map(int, input().split())
numN = list(map(int, input().split()))
numM = list(map(int, input().split()))

ln = min(numN)
lm = min(numM)

if ln == lm:
    print(ln)
    
elif ln == 0 or lm == 0:
    if ln == 0:
        print(str(lm) + str(ln))
    else:
        print(str(ln) + str(lm))
else:
    if ln > lm:
        print(str(lm) + str(ln))
    else:
        print(str(ln) + str(lm))
