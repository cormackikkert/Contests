allStates = []
winStates = set()
loseStates = set()
def getNeighbours(item):
    neighbours = []
    A, B = item
    for i in range(1, A+1):
        neighbours.append((A-i, B+2*i))
    for i in range(1, B+1):
        neighbours.append((A+2*i, B-i))
    return neighbours

children = {}
loseStates |= {(1, 1), (0, 1), (1, 0)}

queue = [((1, 1), 0), ((0, 1), 0), ((1, 0), 0)]
for i in range(200):
    item = queue.pop(0)
    allStates.append(item[0])

    for neighbour in getNeighbours(item[0]):
        queue.append((neighbour, 1-item[1]))
        children[neighbour] = children.get(neighbour, []) + [item[0]]


for item in allStates:
    # print(item, children.get(item, []))
    isWinState = False
    for child in children.get(item, []):
        if child in loseStates: isWinState = True
    if isWinState: 
        winStates.add(item)
    else:
        loseStates.add(item)
print("WIN: ")
for item in winStates:print(item)
print(loseStates)