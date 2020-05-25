N = int(input())
SS = []
SD = []
for i in range(N):
    s, t = input().split()
    SS.append(s)
    SD.append(int(t))

X = input()
count = 0
play = False
for i in range(1, N):
    if SS[i-1] == X: play = True
    if play: count += SD[i]

print(count)
