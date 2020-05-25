import math
T = int(input())
for i in range(T):
    N = int(input())
    AS = list(map(int, input().split())) + [0]
    M = int(input())
    PS = list(map(int, input().split()))
    SS = list(map(int, input().split()))
    heros = [(PS[i], SS[i]) for i in range(M)]
    heros.sort()

    # Build max DS
    monsterStrengthMax = [[None for i in range(N)] for j in range(N)]
    for i in range(N):
        monsterStrengthMax[i][i] = AS[i]
        
    length = 2
    while True:
        for a in range(N):
            b = a + length - 1
            if b >= N: break
            w = (b - a + 1) // 2
            monsterStrengthMax[a][b] = max(monsterStrengthMax[a, a+w-1],
                                           monsterStrengthMax[a+w, b])
        length *= 2
    
    def getMonsterStrength(a, b):
        k = pow(2, math.floor(math.log(b - a + 1) / math.log(2)))
        return max(monsterStrengthMax[a, a + k - 1], monsterStrengthMax[b - k + 1, b])

    # Build max stamina DS
    heroStaminaMax = [[None for i in range(M)] for j in range(M)]
    for i in range(N):
        heroStaminaMax[i][i] = heros[i][1]
        
    length = 2
    while True:
        for a in range(M):
            b = a + length - 1
            if b >= M: break
            w = (b - a + 1) // 2
            heroStaminaMax[a][b] = max(heroStaminaMax[a, a+w-1],
                                       heroStaminaMax[a+w, b])
        length *= 2

    def getHeroStamina(a, b):
        k = pow(2, math.floor(math.log(b - a + 1) / math.log(2)))
        return max(heroStaminaMax[a, a + k - 1], heroStaminaMax[b - k + 1, b])


    # Solve
    start = 0
    while start != N:
        
        
    def binarySearch(lo, hi):
        # Return furthest spot one can get to 
     
    
