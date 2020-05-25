N = int(input())

rooms = [False for i in range(10)]
L = 0
R = 9

for e in input():
    if e == 'L':
        for i in range(10):
            if rooms[i] == False:
                break
        rooms[i] = True
    elif e == 'R':
        for i in reversed(range(10)):
            if rooms[i] == False:
                break
        rooms[i] = True
    else:
        rooms[int(e)] = False

print("".join("01"[o] for o in rooms))
            
