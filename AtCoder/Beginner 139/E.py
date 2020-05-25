import time

t0 = time.clock()

N = int(input())
mat = []
for i in range(N):
    mat.append(list(map(lambda x:int(x)-1, input().split())))

ind = [0 for i in range(N)]
days = 0
while True:
    if time.clock() - t0 > 1:
        print(N * (N - 1) // 2)
        quit()
        
    madeMatch = False
    
    played = [False for i in range(N)]
    for i in range(N):
        if ind[i] == N-1 or played[i]: continue
        playAgainst = mat[i][ind[i]]
        if mat[playAgainst][ind[playAgainst]] == i and not played[playAgainst]:
            madeMatch = True
            played[i] = True
            played[playAgainst] = True

            ind[playAgainst] += 1
            ind[i] += 1
    if not madeMatch: break
    days += 1
    
if all(x == N-1 for x in ind):
    print(days)
else:
    print(-1)
