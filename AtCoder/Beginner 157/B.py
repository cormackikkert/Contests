A = [[],[],[]]
A[0] = list(map(int, input().split()))
A[1] = list(map(int, input().split()))
A[2] = list(map(int, input().split()))

complete = [[False, False, False] for i in range(3)]

N = int(input())
for i in range(N):
    val = int(input())

    for y in range(3):
        for x in range(3):
            if A[y][x] == val: complete[y][x] = True

bingo = False
for y in range(3):
    if all(complete[y]): bingo = True

for x in range(3):
    if (all(complete[i][x] for i in range(3))): bingo = True

if all(complete[i][i] for i in range(3)): bingo = True
if all(complete[i][3-i-1] for i in range(3)): bingo = True

if bingo:
    print("Yes")
else:
    print("No")