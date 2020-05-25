N, K = map(int, input().split())
vals = list(map(int, input().split()))

objs = [None for i in range(K+1)]

objs[0] = -1

for i in range(K+1):
    score = -1
    for a in vals:
        if a <= i:
            score = max(score, -objs[i-a])
    objs[i] = score

if objs[-1] == 1:
    print("First")
else:
    print("Second")
