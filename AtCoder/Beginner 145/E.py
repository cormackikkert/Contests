# A Dynamic Programming based Python Program for 0-1 Knapsack problem 
# Returns the maximum value that can be put in a knapsack of capacity W
# ty geekforgeeks
def knapSack(W, wt, val, n): 
    K = [[0 for x in range(W+1)] for x in range(n+1)] 
  
    # Build table K[][] in bottom up manner 
    for i in range(n+1): 
        for w in range(W+1):
            if i==0 or w==0: 
                K[i][w] = 0
            elif wt[i-1] <= w: 
                K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]) 
            else: 
                K[i][w] = K[i-1][w] 
        res = K[n][W] 
      
    w = W
    used = [False for i in range(N)]
    for i in range(n, 0, -1): 
        if res <= 0: 
            break
        # either the result comes from the 
        # top (K[i-1][w]) or from (val[i-1] 
        # + K[i-1] [w-wt[i-1]]) as in Knapsack 
        # table. If it comes from the latter 
        # one/ it means the item is included. 
        if res == K[i - 1][w]: 
            continue
        else: 
            # This item is included. 
            used[i - 1] = True
              
            # Since this weight is included 
            # its value is deducted 
            res = res - val[i - 1] 
            w = w - wt[i - 1] 
    return K[n][W], used

N, T = map(int, input().split())
wts = [None for i in range(N)]
val = [None for i in range(N)]
for i in range(N):
    a, b = map(int, input().split())
    wts[i] = a
    val[i] = b

best, _ = knapSack(T, wts, val, N)
print(best)
other, used = knapSack(T - 1, wts, val, N)
add = 0
for i, wasUsed in enumerate(used):
    if not wasUsed: add = max(add, val[i])
print(max(best, other + add))

