"""
ID: cormac.1
LANG: PYTHON3
TASK: job
"""

with open("job.in") as file:
    N, A, B = map(int,file.readline().split())
    M = list(map(int, file.read().split()))
    M1, M2 = M[:A], M[A:]
    
# Perform A tasks
endtimes = list(M1)
tasks = [0 for i in range(N)]
times = []
for i in range(N):
    machine = endtimes.index(min(endtimes))
    times.append(endtimes[machine])
    endtimes[machine] += M1[machine]

endtimes = list(M2)
tasks = [0 for i in range(N)]
times2 = []
for i in range(N):
    machine = endtimes.index(min(endtimes))
    times2.append(endtimes[machine])
    endtimes[machine] += M2[machine]
times2 = list(reversed(times2))

maxTime = max(times2[i] + times[i] for i in range(N))

with open("job.out", "w") as file:
    file.write(str(max(times)) + " " + str(maxTime) + "\n")
    
