N = int(input())
O = list(map(int, input().split()))

strings = [["0" for i in range(N)] for i in range(N+1)]

scores = sorted([(O[i], i) for i in range(N)], reverse=True)
T = [None for i in range(N)]
for i, (num, ind) in enumerate(scores): T[ind] = i

for i, x in enumerate(O):
    for j in range(x):
        strings[(T[i] + j) % (N + 1)][i] = "1"
strings = [s for s in strings if "1" in s]
print(len(strings))
for s in strings:
    print("".join(s))    
