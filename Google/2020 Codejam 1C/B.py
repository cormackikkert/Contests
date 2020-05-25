def res():
    U = int(input())
    res = [set("ABCDEFGHIJKLMNOPQRSTUVWXYZ") for i in range(10)]

    ALLC = set()
    print("REE", U)
    for i in range(int(pow(10, 4))):
        Q, S = input().split()
        if len(Q) == len(S):
            for i in range(int(Q[0])+1, 10):
                if S[0] in res[i]:
                    res[i].remove(S[0])
        for c in S: ALLC.add(c)

    for i in range(10):
        for c in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
            if c not in ALLC:
                if c in res[i]: res[i].remove(c)
    print(res)


T = int(input())
for i in range(T):
    print("Case #" + str(i+1)+": " +res())