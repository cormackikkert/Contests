import sys
sys.setrecursionlimit(1000000)

with open("ruckusin.txt") as file:
    N, L, K, M = list(map(int, file.readline().split()))
    edgelist = {}
    for i in range(1, N+1):
        edgelist[i] = []
    for i in range(L):
        s, e = map(int, file.readline().split())
        edgelist[s] += [e]
        edgelist[e] += [s]

lines = []
cycles = []
cur_component = []
total = 0
discovered = [False for i in range(N+1)]

def get_components():
    global cur_component
    global total
    for i in range(1,N+1):
        if discovered[i] == False:
            cur_component = []
            search(i)
            if len(cur_component) >= M:
                total += 1
            if len(cur_component) >= 2 * M:
                if all(len(edgelist[v]) == 2 for v in cur_component):
                    cycles.append(len(cur_component))
                else:
                    lines.append(len(cur_component))
        
def search(start):
    global cur_component
    cur_component.append(start)
    discovered[start] = True
    for edge in edgelist[start]:
        if discovered[edge] == False:
            search(edge)

get_components()
cycles.sort()

for i in range(K):
    if lines:
        length = lines.pop()
        total += 1
        if length - M >= 2*M:
            lines.append(length - M)
    elif cycles:
        lines.append(cycles.pop())

with open("ruckusout.txt", "w") as file:
    file.write(str(total))