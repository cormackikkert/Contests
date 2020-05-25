"""
ID: cormac.1
LANG: PYTHON3
TASK: kimbits
"""

fact = lambda x : 1 if x <= 1 else x * fact(x - 1)
def choose(n, k):
    return fact(n)//fact(n-k)//fact(k)

def solve(N, L, I):
    if N == 0: return ""
    if N == 1: return "0" if I == 1 else "1"
    
    if I <= sum(choose(N-1, i) for i in range(L+1)):
        return "0" + solve(N - 1, L, I)
    return "1" + solve(N - 1, L - 1, I - sum(choose(N-1, i) for i in range(L+1)))
    
with open("kimbits.in") as file:
    N, L, I = map(int, file.readline().split())

result = solve(N, L, I)

with open("kimbits.out", "w") as file:
    file.write(result + "\n")
