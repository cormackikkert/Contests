N = int(input())
marbles = list(map(lambda x:int(x)-1, input().split()))
MM = max(marbles) + 1

count = [[0 for i in range(20)] for j in range(20)]

for i in range(20):
    for j in range(20):
        if i == j: continue
        
        # Count swaps required to place i before j
        total = 0
        onLeft = 0
        for marble in marbles:
            if marble != i and marble != j: continue
            if marble == i: total += onLeft
            else: onLeft += 1

        count[i][j] = total
    
dp = [None for i in range(pow(2, MM))]

def order(bitmask):
    if dp[bitmask] != None:
        return dp[bitmask]

    if bitmask == 0: return 0
    
    score = float('inf')
    for marbleType in range(MM):
        if bitmask & (1 << marbleType):
            score = min(score,
                        order(bitmask & ~(1 << marbleType)) +
                        sum(count[i][marbleType] for i in range(MM) if bitmask & (1 << i)))
    dp[bitmask] = score
    return score

print(order(pow(2, MM)- 1))
