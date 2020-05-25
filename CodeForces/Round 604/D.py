import sys
sys.setrecursionlimit(1000000)
a, b, c, d = map(int, input().split())
if a + b + c + d == 0:
    print("YES")
    print()
    quit()
if a + b + c + d == 1:
    if a == 1: print("YES\n0")
    if b == 1: print("YES\n1")
    if c == 1: print("YES\n2")
    if d == 1: print("YES\n3")
def canDo(v, s, e):
    for i in range(4): v[i] *= 2
    v[s] -= 1
    v[e] -= 1
    a, b, c, d = v
    
    nodes = [[] for i in range(4)]
    nodes[0] = [1 for i in range(a)]
    nodes[1] = [0 for i in range(a)]
    nodes[2] = [3 for i in range(d)]
    nodes[3] = [2 for i in range(d)]
    b -= a; c -= d;
    if b != c or b < 0 or b == 0 and min(a, d) > 0:
        return False
    for i in range(b):
        nodes[1].append(2)
        nodes[2].append(1)
    
    circuit = [] #[None for i in range(1024)]
    circuitpos = 0

    def findCircuit(node):
        if len(nodes[node]) == 0:
            circuit.append(node)
        if len(nodes[node]) > 0:
            while nodes[node]:
                neighbour = nodes[node].pop(0)
                nodes[neighbour].remove(node)
                findCircuit(neighbour)
            circuit.append(node)
    findCircuit(s)

    if any(d != [] for d in nodes): return False
    return circuit


for s in range(4):
    for e in range(4):
        res = canDo([a, b, c, d], s, e)
        if res:
            print("YES")
            print(" ".join(map(str, res)))
            quit()
print("NO")
