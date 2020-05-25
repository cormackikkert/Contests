N, M = map(int, input().split())
s = input() 

N += 1
# Max size of tree  
tree = [0] * (2 * N);  
n = N
# function to build the tree  
def build() : 
  
    # insert leaf nodes in tree  
    for i in range(N) :  
        tree[n + i] = (float('inf'), float('inf'));  
      
    # build the tree by calculating parents  
    for i in range(n - 1, 0, -1) :  
        tree[i] = min(tree[i << 1], tree[i << 1 | 1])
  
# function to update a tree node  
def updateTreeNode(p, value) :  
      
    # set value at position p  
    tree[p + n] = (value, p);  
    p = p + n;  
      
    # move upward and update parents  
    i = p; 
      
    while i > 1 : 
          
        tree[i >> 1] = min(tree[i], tree[i ^ 1]);  
        i >>= 1;  
  
# function to get sum on interval [l, r)  
def query(l, r) :  
  
    res = (float('inf'), float('inf'));  
      
    # loop to find the sum in the range  
    l += n; 
    r += n; 
      
    while l < r : 
      
        if (l & 1) : 
            res = min(res, tree[l]);  
            l += 1
      
        if (r & 1) : 
            r -= 1; 
            res = min(res, tree[r]);  
              
        l >>= 1; 
        r >>= 1
      
    return res;

par = [None for i in range(N)]
build()
updateTreeNode(0, 0)
for i in range(1, N):
    if s[i] == "1": continue
    r = query(max(0, i - M), i)
    par[i] = r[1]
    updateTreeNode(i, r[0]+1)
    # updateTreeNode(i, query(max(0, i - M), i))
    
    # for k in range(1, M+1):
    #     if i - k < 0: break
    #     dp[i] = min(dp[i], (dp[i-k][0], (i - k)))



moves = []
cur = N - 1
if par[cur] == float('inf'):
    print(-1)
    quit()
try:
    while par[cur] != None:
        new = par[cur]
        moves.append(cur - new)
        cur = new
except:
    print(-1)
    quit()

moves = list(reversed(moves))
print(" ".join(map(str, moves)))
