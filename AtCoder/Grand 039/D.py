from math import *

N, L = map(int, input().split())
T = []
for i in range(N):
    T.append(float(input()))

Lines = []
for i in range(N):
    for j in range(i + 1, N):
        lines.append((cos(2 * pi * T[i] / L), sin(2 * pi * T[i]) / L))

EL = (sum(line[0] for line in lines) / (N * (N - 1) / 2),
      sum(line[1] for line in lines)
