A, Q = map(int,input().split())

dt = {}

for a in range(A):
    for c in input():
        if c.isupper():
            if c not in dt:
                dt[c] = {a}
            else:
                dt[c].add(a)

memo = {}

def f(msg, banned, rec=0):
    #print("    "*rec+msg, "|", banned)
    if len(msg) == 0:
        return 1
    if msg[0] not in dt:
        return 0
    if (msg,banned) in memo:
        return memo[(msg,banned)]
    result = 0
    for i in dt[msg[0]]:
        if i in banned:
            continue
        result += f(msg[1:],banned|{i}, rec+1)
    memo[(msg,banned)] = result
    return result

for _ in range(Q):
    q=input()
    if len(q)!=A:
        print(0)
    else:
        print(f(q,frozenset()))
