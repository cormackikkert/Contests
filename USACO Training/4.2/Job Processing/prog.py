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

starttimes = list(times)
maxTime = [0 for i in range(B)] # Maximum time used for each machine
machines = [times[-1] for i in range(B)]

data = []

for time in reversed(starttimes):
    
    usedMachines = list(filter(lambda n : time <= machines[n], range(B)))
    unusedMachines = list(filter(lambda n: time > machines[n], range(B)))
    print("---")
    print(time, usedMachines, unusedMachines)
    usedScore = unusedScore = float('inf')
    usedMin = unusedMin = None
    
    if usedMachines:
        usedMin = min(usedMachines, key = lambda n : (max(maxTime[n], time + M2[n]), M2[n]))
        usedScore = time + M2[usedMin]
    if unusedMachines:
        unusedMin = min(unusedMachines, key = lambda n : (time - machines[n] + maxTime[n], M2[n]))
        unusedScore = time - machines[unusedMin] + maxTime[unusedMin]

    print(f"{usedMin} - {usedScore}, {unusedMin} - {unusedScore}")
    
    if usedScore <= unusedScore:
        data.append((usedMin, time, machines[usedMin], machines[usedMin] + M2[usedMin]))
        machines[usedMin] = time - M2[usedMin] if machines[usedMin] == times[-1] else machines[usedMin] - M2[usedMin]
        maxTime[usedMin] = max(maxTime[usedMin], machines[usedMin] + 2 * M2[usedMin])
    else:
        for i, d in enumerate(data):
            if d[0] == unusedMin:
                data[i] = (d[0], d[1], d[2] + time - machines[unusedMin], d[3] + time -machines[unusedMin]) 
        data.append((unusedMin, time, time, time + M2[unusedMin]))
        maxTime[unusedMin] += time - machines[unusedMin]
        machines[unusedMin] = time - M2[unusedMin]
    print(machines, maxTime)
    
print(times)
print(maxTime)

print(data)

with open("job.out", "w") as file:
    file.write(str(max(times)) + " " + str(max(maxTime)) + "\n")
    
