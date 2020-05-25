N, M = map(int, input().split())
sweets = sorted(list(map(int, input().split())), reverse=True)
groupings = [[] for i in range(M)]
for i, item in enumerate(sweets):
    groupings[i % M].append(item)
    
cumsum = [[0 for i in range(len(groupings[i]))] for i in range(M)]
for t in range(M):
    cumsum[t][-1] = groupings[t][-1]
    for i, item in enumerate(list(reversed(groupings[t]))[1:]):
        cumsum[t][-i-2] = cumsum[t][-i-1] + item

output = []
total = 0
for i in range(N, -1, -1):
    if i == N:
        for i, sweet in enumerate(sweets):
            total += sweet * (i // M + 1)
    else:
        j = N - i - 1
        total -= cumsum[j%M][j//M]
    output.append(total)
print(*list(reversed(output))[1:])

