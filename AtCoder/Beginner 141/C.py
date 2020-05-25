N, K, Q = map(int, input().split())
wins = [0 for i in range(N)]
for i in range(Q):
    wins[int(input()) - 1] += 1

for i in range(N):
    if Q - wins[i] >= K:
        print("No")
    else:
        print("Yes")
