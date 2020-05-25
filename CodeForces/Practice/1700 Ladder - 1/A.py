N = int(input())
if N % 2 == 0:
    bags = [[] for i in range(N)]
    mid = (N * N) // 2
    for i in range(mid):
        bags[i % N].append(mid + i + 1)
        bags[i % N].append(mid - i)
    for bag in bags:
        print(*bag)
else:
    count = (N - 1) // 2
    mid = (N * N + 1) // 2
    LHS = (N + 1) // 2
    RHS = N - LHS
    S = ((N + 1) * (2*N + 1)) // 6
    bags = [[] for i in range(count)]
    for i in range(count):
        LS = LHS * (((mid - i - 1) + (mid - i - 1 - (N - 1) * (LHS - 1))) // 2)
        for j in range(LHS):
            bags[i].append(mid - i - 1 - (N - 1) * j)
        for j in range(RHS//2):
            bags[i].append(N*N - i, S - LS - N * N + i)
    print(bags)
        
