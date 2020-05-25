N = int(input())
D = list(map(int, input().split()))

 
MOD = 998244353
 
occ = [0 for i in range(N+5)]
for d in D:
    occ[d] += 1
 
if occ[0] != 1 or D[0] != 0:
    print(0)
    quit()
 
cur = 1
for i in range(1, N+5):
    cur *= pow(occ[i - 1], occ[i])
    cur %= MOD
print(cur % MOD)
