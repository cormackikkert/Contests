N, M = list(map(int, input().split()))
digits = [-1 for i in range(N)]

fail = False

for i in range(M):
    s, c = list(map(int, input().split()))
    s -= 1

    if (digits[s] != -1 and digits[s] != c):
        fail = True
    elif s >= N:
        fail = True
    else:
        digits[s] = c

if (N == 1 and (digits[0] == -1 or digits[0] == 0)):
    print(0)
    quit()

if (digits[0] == -1): digits[0] = 1
for i in range(1,N):
    if digits[i] == -1: digits[i] = 0

if digits[0] == 0:
    fail = True

if fail:
    print(-1)
else:
    print("".join(map(str, digits)))