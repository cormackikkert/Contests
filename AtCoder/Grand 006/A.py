N = int(input())
S = input()
T = input()

best = float('inf')
for i in range(len(T)+1):
    s = S + T[i:]
    if s[::-1][:N][::-1] == T:
        best = min(best, len(s))

print(best)