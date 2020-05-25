inn = "pentin.txt"
outn = "pentout.txt"
inf=open(inn);outf = open(outn,"w");
fileInput=lambda:inf.readline().strip();
filePrint=lambda args,sep=' ',end='\n':[outf.write(sep.join(map(str,args))+end),outf.flush()]

MOVES = {(1, 0), (-1, 0), (0, 1), (0, -1)}

R, C = map(int, fileInput().split())
grid = [list(map(int, fileInput())) for i in range(R)]
PENTOS = []

def display(done):
    updatedGrid = [["." for i in range(C)] for j in range(R)]
    for i, pento in enumerate(done):
        for x,y in pento:
            updatedGrid[y][x] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i]
    for row in updatedGrid:
        filePrint([''.join(row)])
       
def blocks(done, current, pos):
    if len(current) == 5:
        if current not in PENTOS:
            PENTOS.append(current)
            
        if len(done) + 1 == (R * C) // 5:
        
            done = done + [current]
            display(done)
            
            return True
        else:
            if blocks(done + [current], [], pos):
                return True
    else:
        x, y = pos
        for movement in MOVES:
            mx, my = movement
            if (0 <= x + mx < C and 0 <= y + my < R):
                if grid[y+my][x+mx] not in [grid[posy][posx] for posx,posy in current]:
                    for pento in done:
                        if (x + mx, y + my) in pento:
                            break
                    else:
                        if blocks(done, current + [(x + mx, y + my)], (x + mx, y + my)):
                            return True

def generate(blocks, current):
    if len(current) == (R * C) // 5:
        display(current)
        return True
    else:
        for block in blocks:
            if (block not in current):
                d = []
                for a in current:
                    for pos in a:
                        if pos in d:
                            break
                        else:
                            d.append(pos)
                else:
                    for pos in block:
                        if pos in d:
                            break
                        else:
                            d.append(pos)
                    else:
                        if generate(blocks, current + [block]):
                            return True
                
if not blocks([], [], (0, 0)):
    generate(PENTOS, [])



