with open("job.in") as file:
    N, A, B = map(int,file.readline().split())
    M = list(map(int, file.read().split()))
    MA = [M[:A], M[A:]]

def solve(et, j):
    tasks = [0 for i in range(N)]
    times = []
    for i in range(N):
        m = et.index(min(et))
        times += [et[m]]
        et[m] += MA[j][m]
    return times

l1 = solve(list(MA[0]), 0)
l2 = solve(list(MA[1]), 1)[::-1]

with open("job.out", "w") as file:
    file.write(str(max(l1)) + " " + str(max(l1[i] + l2[i] for i in range(N))) + "\n")
