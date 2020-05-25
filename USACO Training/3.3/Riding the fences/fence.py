"""
ID: cormac.3
LANG: PYTHON3
TASK: fence
"""
import sys
sys.setrecursionlimit(10000)

nodes = [[] for i in range(500)]


first = 500

with open("fence.in") as file:
    F = int(file.readline())
    for i in range(F):
        a, b = map(int, file.readline().split())

        first = min(a-1, b-1, first)
        
        nodes[a-1].append(b-1)
        nodes[b-1].append(a-1)

# Find starting point

for neighbours in nodes:
    neighbours.sort()
    
firstOdd = None

for i, neighbours in enumerate(nodes):
    if len(neighbours) % 2 != 0:
        firstOdd = i
        break
    
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

if firstOdd == None:
    findCircuit(first)
else:
    findCircuit(firstOdd)


with open("fence.out", "w") as file:
    for item in reversed(circuit):
        file.write(str(item + 1) + "\n")    
            
            
        
    
    
