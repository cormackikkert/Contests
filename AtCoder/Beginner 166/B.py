N,K = map(int, input().split())
has = [False for i in range(N)]
for i in range(K):
    input()
    args = list(map(int, input().split()))
    for i in args:
        has[i-1] = True

res = 0
for i in has: 
    if i == False: 
        res += 1
print(res)