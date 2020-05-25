N = int(input())

def simulate(K):
    T = N
    while T >= K:
        if T % K:
            T -= K
        else:
            T /= K
    return T == 1

l1 = []
l2 = []
for i in range(2, N+1):
    if simulate(i):
        l1.append(i);#print(i)

print(l1)